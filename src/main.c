/**************************************************************************
* 版权声明：Copyright@2019 上海东软载波微电子有限公司
* 文件名称：main.c
* 功能描述：	
* 函数列表：
* 文件作者：Ljj  
* 文件版本： 
* 完成日期：2023-08-23	
* 修订历史：
* 修订日期：
**************************************************************************/
#include <hic.h>
#include "string.h" 
#include "io.h"
#include "hw2000b.h"
#include "timer.h"
#include "ram.h"
#include "spi.h"

#define CLRWDT()   {__Asm CWDT;}        //宏定义清狗指令

uint16_t	_ack_count;
sbit		_hw2000b_irq_request;	//射频中断标志
sbit		rx_ok;

uint8_t sleep_flag = 0;
uint8_t RX_OK_flag = 0;

uint8_t rxbuf[40];

uint8_t timer_cnt;

#define STARTADDR    0xC000     //宏定义数据区IAP操作起始地址
#define ENDADDR      0xC002     //宏定义数据区IAP操作结束地址
#define WRDATA       0x87654321     //宏定义待写入数据

#define DATA_1_ADDR	0xC000
#define DATA_2_ADDR	0xC001
#define DATA_3_ADDR	0xC002

uint8_t dataerr = 0;      //0：写入与读出相等，1：写入与读出不等

uint8_t CallFlashEn,FlashEwEn;//软件锁变量


static volatile unsigned int section8 FRAN @ 0xFF8E;
static volatile unsigned int section8 FRA  @ 0xFF90;

/******************************************************
函数名：void StartIAP(void)
描  述：开始IAP操作。注意：IAP固定操作格式，使用时不可改变
输入值：无
输出值：无
返回值：无
*******************************************************/
void StartIAP(void)
{
    __asm{
          MOVI 0x55
          MOVA ROMCH
          MOVI 0xFF     //8个NOP代替语句开始
          SECSEL &FlashEwEn& % 0x80//选择变量所在的section
          XOR &FlashEwEn& % 0x80,0//0xFF xor 0xAA = 0x55
          SECSEL &CallFlashEn& % 0x80//选择变量所在的section
          XOR &CallFlashEn& % 0x80,0//若CallFlashEn在调用函数前为0x55，0x55 xor 0x55 = 0x00
          JBS PSW,Z//如果运算结果为0x00，则执行正确，跳至下一个NOP
          GOTO $+3
          NOP//8个NOP代替语句结束
          MOVI 0xAA
          MOVA ROMCH
          MOVI 0xFF     //8个NOP代替语句开始
          SECSEL &FlashEwEn& % 0x80//选择变量所在的section
          XOR &FlashEwEn& % 0x80,0//0xFF xor 0xAA = 0x55
          SECSEL &CallFlashEn& % 0x80//选择变量所在的section
          XOR &CallFlashEn& % 0x80,0//若CallFlashEn在调用函数前为0x55，0x55 xor 0x55 = 0x00
          JBS PSW,Z//如果运算结果为0x00，则执行正确，跳至下一个NOP
          GOTO $+3
          NOP//8个NOP代替语句结束
          BSS ROMCL,WR     //触发编程操作
          JBC ROMCL,WR
          goto $-1         //等待操作结束
        }
}

/*******************************************************
函数名：void DataFlashErsPage(void)
描  述：擦除DataFlash整页(256 word)，地址范围：0xC000~0xC1FF
输入值：DataFlash地址addr，DataFlash取反地址addri
输出值：无
返回值：无
*******************************************************/
void DataFlashErsPage(unsigned int addr, unsigned int addri)
{
	unsigned char gie_bk = GIE;		//备份GIE
    CLRWDT();
	while(GIE == 1)GIE = 0;            //启动IAP前关闭全局中断
	FlashEwEn = 0xAA;//设置软件锁变量

    FPEE = 1;           //存储器擦除模式
    FRAH = addr>>8;
    FRAL = addr;
    FRAHN = addri>>8;      //IAP擦除/编程必须满足地址取反逻辑
    FRALN = addri;     

    WREN = 1;           //使能擦除/编程功能
    StartIAP();         //开始IAP操作
	CallFlashEn = 0;//清零软件锁变量
	FlashEwEn = 0;
    ROMCL = 0x00;       //退出IAP
	FRA = 0xFF12;//指到不用的地址空间
	FRAN = 0x3456;//此处把地址反码赋成与0xFFFF和FRA无取反关系的值
	GIE = gie_bk;       //恢复全局中断
}

/*******************************************************
函数名：unsigned long DataFlashRdData(unsigned int addr)
描  述：读Flash指定地址的数据
输入值：DataFlash地址addr，地址范围：0xC000~0xC1FF
输出值：无
返回值：DataFlash指定地址的数据
*******************************************************/
unsigned long DataFlashRdData(unsigned int addr)
{
	unsigned long data;
	unsigned char gie_bk = GIE;	  //备份GIE
    CLRWDT();
	while(GIE == 1)GIE = 0;
    FRAL = addr;
    FRAH = addr>>8;
	DATARDTRG=1;
	while(DATARDTRG);
	DATARDEN=1;         //DATA区读出使能
    __Asm TBR;          //查表读指令
    data = ((unsigned long)ROMD1H<<24) | ((unsigned long)ROMD1L<<16) | ((unsigned long)ROMDH<<8) | ROMDL;
	DATARDEN=0;         //DATA区读出禁止
    GIE = gie_bk;       //恢复全局中断
	return data;
}

/*******************************************************
函数名：void DataFlashWrData(unsigned int addr, unsigned long word)
描  述：写DataFlash指定地址的数据，地址范围：0xC000~0xC1FF
输入值：DataFlash地址addr，DataFlash取反地址addri，待写的数据word
输出值：无
返回值：0:写入失败，1:写入成功
*******************************************************/
unsigned char DataFlashWrData(unsigned int addr, unsigned int addri, unsigned long word)
{
    unsigned char rmdh,rmdl,rmd1h,rmd1l;      //临时存放ROMDH、ROMDL值
	unsigned char gie_bk = GIE;	  //备份GIE
    CLRWDT();
	while(GIE == 1)GIE = 0;            //启动IAP前关闭全局中断
	FlashEwEn = 0xAA;//设置软件锁变量

    FPEE = 0;           //存储器编程模式
    ROMD1H = word>>24;    //写Word
    ROMD1L = word>>16;
    ROMDH = word>>8;
    ROMDL = word;
    FRAH = addr>>8;     //IAP编程地址
    FRAL = addr;
    FRAHN = addri>>8;      //IAP擦除/编程必须满足地址取反逻辑
    FRALN = addri;       

    WREN = 1;           //使能编程
    StartIAP();         //开始IAP操作
	CallFlashEn = 0;//清零软件锁变量
	FlashEwEn = 0;
    rmdh = ROMDH++;
    rmdl = ROMDL++;
    rmd1h = ROMD1H++;
    rmd1l = ROMD1L++;
	DATARDEN=1;      //DATA区读出使能
    FRAH = addr>>8;
    FRAL = addr;
	DATARDTRG=1;     //DATA区读出触发
	while(DATARDTRG);
    __Asm TBR;          //查表读指令
    if (ROMDH!=rmdh || ROMDL!=rmdl || ROMD1H!=rmd1h || ROMD1L!=rmd1l)
	{
        ROMCL = 0x00;       //退出IAP
		return 0;
	}
	FRA = 0xFF12;//指到不用的地址空间
	FRAN = 0x3456;//此处把地址反码赋成与0xFFFF和FRA无取反关系的值
	ROMDH = 0xFF;//数据初始化为0xFF
	ROMDL = 0xFF;//数据初始化为0xFF
	ROMD1H = 0xFF;//数据初始化为0xFF
	ROMD1L = 0xFF;//数据初始化为0xFF
    ROMCL = 0x00;       //退出IAP
	DATARDEN=0;   //DATA区读出禁止
	GIE = gie_bk;       //恢复全局中断
    return 1;
}

void Delay_20us(unsigned int a)
{
	uint16_t i;

	for(;a>0;a--)
	{
        for(i = 0;i<10;i++);
	}
}

/**********************************************
函数名：void sleep(void)
描  述：进入IDLE模式
输入值：无
输出值：无
返回值：无
**********************************************/
void sleep(void)
{
	T8NEN = 0;				//禁能T8N
    RX0EN = 0;				//禁能串口接收

	INTC0 = 0xFF;			//PINT0-双沿中断
	PIE0 = 1;				//打开PINT0管脚中断
    PIF0 = 0;				//睡眠前清中断标志位

	KMSK4 = 0;				//KINT4屏蔽
	INTF0 = 0x00;			//清除中断标志
	INTE0 = 0x00;			//禁能KIE

	GIE = 0;				//关闭总中断

							
	PWEN &= 0xFD;			//禁止IDLE状态下计数
	WKDC = 0x1F;
	PWRC = 0x8F;			//选择IDLE模式
    __Asm IDLE;				//进入IDLE模式

	GIE = 1;				//打开总中断

	KMSK4 = 1;				//KINT4取消屏蔽
	INTF0 = 0x00;			//清除中断标志
	INTE0 |= 0x10;			//使能KIE

	INTC0 = 0xFF;			//PINT0-双沿中断
	PIE0 = 0;				//关闭PINT0管脚中断
    PIF0 = 0;				//睡眠前清中断标志位

	T8NIE = 1;				//打开定时器溢出中断
	T8NIF = 0;				//清标志位
	T8N = 131;				//赋计数器初值   2ms
	T8NEN = 1;				//使能T8N

	timer_cnt = 250;

	RX0EN = 1;			//使能串口接收
}


void WDT_Init(void)
{
    WDTC = 0x16;         //分频比1:128，使能WDT预分频器，看门狗溢出时间t=256*128/32000=1.024s
    PWEN &= 0xFD;
    PWEN |= 0<<1;		//禁止IDLE状态下计数
}

void UART_Init(void)
{
    RX0LEN = 0;     //8位数据接收格式
    TX0LEN = 0;     //8位数据发送格式
	//BJT0EN = 1;		//波特率去抖使能
    //BRGH0 = 0;      //波特率低速模式：波特率=Fosc/(64*BRRDIV))
    //BR0R = 0xD0;    //波特率整数部分=16MHz/(64*1200bps)=208.3333
	//BR0FRA = 0x05;	//波特率小数部分=16*0.3333 ≈ 5

    //BRGH0 = 0;      //波特率低速模式：波特率=Fosc/(64*(BRR<7:0>+1))
    //BR0R = 0x19;    //波特率=16MHz/(64*(25+1))≈9600bps

    BRGH0 = 0;      //波特率低速模式：波特率=Fosc/(64*(BRR<7:0>+1))
    BR0R = 0x33;    //波特率=16MHz/(64*(51+1))≈4800bps

	RX0TXEN = 1;		//串口管脚交互，RX0=0 ,TX0=1

	RX0IE = 1;			//接收中断
	//RX0EN = 1;          //打开串口接收
}

void TIME_Init(void)
{
    T8NC = 0x0E;         //定时器模式，预分频1:(Fosc/2)/128
    T8N = 131;           //赋计数器初值   2ms
    T8NIE = 1;           //打开定时器溢出中断
    T8NIF = 0;           //清溢出标志位

    T8NEN = 1;           //使能T8N

	timer_cnt = 250;	 //
}


/**************************************************************************
* 函数名称：main
* 功能描述：工程入口
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void main(void) 
{
    GPIOInit();										//初始化GPIO
	WDT_Init();										//初始化看门狗
	UART_Init();									//初始化串口
	TIME_Init();									//初始化定时器

	rxbuf[0] = 0;									//清串口计数值
	RX_OK_flag = 0;									//清串口接收完成标志
	sleep_flag = 1;									//上电休眠

	spi_init();										//初始化SPI端口

	hw2000b_port_init();							//初始化射频端口
	hw2000b_init_250k();							//初始化射频参数
	hw2000b_power_down();							//关闭射频模块

	GIE = 1;										//全局中断使能

	while(1) 
	{
		if(sleep_flag)							//睡眠标志位判断
		{
			sleep();							//进入睡眠函数
			sleep_flag = 0;						//清睡眠标志位
		}

		if (RX_OK_flag)							//串口接收完成标志位判断
		{
			RX_OK_flag = 0;						//清接收完成标志位
			CLRWDT();

			hw2000b_power_on();					//打开射频模块
			hw2000b_tx_data(rxbuf, rxbuf[0] + 1);	//发送串口数据
			hw2000b_power_down();				//关闭射频模块
			CLRWDT();

			rxbuf[0] = 0;						//清除计数值

			sleep_flag = 1;						//置睡眠标志位
		}

        CLRWDT();								//清看门狗
	}
}

/**************************************************************************
* 函数名称：isr
* 功能描述：中断入口函数
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void isr(void) interrupt
{
	uint8_t y;


    if(PIE0==1 && PIF0==1)
    {
        PIF0 = 0;					//清除外部中断
    }

    if (T8NIE==1 && T8NIF==1)       //定时器2ms溢出中断
    {
        T8NIF = 0;					//清标志位
        T8N = 131;					//进中断先赋计数器初值

		if (timer_cnt < 250)
		{
			timer_cnt++;
			if (timer_cnt >= 4)		//两字节间隔8ms
			{
				timer_cnt = 250;
				RX_OK_flag = 1;		//置位完成标志
			}
		
		}
    }

    if(RX0IE==1 && RX0IF==1)
    {
		timer_cnt = 0;				//重新计数
		rxbuf[rxbuf[0] + 1] = RX0B;
		rxbuf[0] = rxbuf[0] + 1;

		if(rxbuf[0] > 30)			//接收限制
		{
			rxbuf[0] = 30;
		}
    }

	if(KIE && KMSK4 && KIF)
    {
		KIF = 0;       //清除外部中断
		if(IRQ)
		{
			_hw2000b_irq_request = 1;
		}
    }

}


