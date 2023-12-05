/**************************************************************************
* 版权声明：Copyright@2019 上海东软载波微电子有限公司
* 文件名称：spi.c
* 功能描述：spi通讯函数
* 函数列表：spi_init			
* 文件作者：Ljj  
* 文件版本： 
* 完成日期：2023-08-23	
* 修订历史：
* 修订日期：
**************************************************************************/
#include <hic.h>
#include "type.h"
#include "spi.h"

#define		CSN_0()		CSN = 0
#define		CSN_1()		CSN = 1

uint8_t		val_h, val_l;

/**************************************************************************
* 函数名称：spi_init
* 功能描述：初始化spi
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void spi_init(void)
{
	TCSN = 0;
	TSCK = 0;
	TMOSI = 0;
	TMISO = 1;

	CSN = 1;
	SCK = 0;
	MOSI = 0;

	SPIRST = 1;			//复位SPI
    while(SPIRST);
    SPICON0 = 0xF0;     //CKS = Fosc/4 = 32/8 = 4MHz，清空发送器、接收器，字节读写 0xF0:Fosc/16 0xE0:Fosc/8 0xD0:Fosc/4 0xC0:Fosc/2
    SPICON1 = 0x00;      //0:上升沿发送（先），下降沿接收（后）；
    MS = 0;				//0：主机模式，1：从机模式
    RBIE = 0;			//关闭接收中断	
    SPIEN = 1;			//SPI使能
}

/**************************************************************************
* 函数名称：hw2000b_write_reg
* 功能描述：写hw2000b寄存器
* 输入参数：addr  寄存器地址
            value 寄存器值
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_write_reg(uint8_t addr, uint16_t data)
{
	addr |= 0x80;
	REN = 0;        //关闭接收

	CSN_0();
	SPITBW = addr;
    while(!TBIF);
	SPITBW = data>>8;
	while(!TBIF);
	SPITBW = data;
	while(!IDIF);

	CSN_1();
}

/**************************************************************************
* 函数名称：hw2000b_read_reg
* 功能描述：读hw2000b寄存器
* 输入参数：addr  寄存器地址
* 返回参数：value 寄存器值
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
uint16_t hw2000b_read_reg(uint8_t addr)
{
    CSN_0();
	REN = 1;        //打开接收

	SPITBW = addr;
	while (!RBIF);   //等待接收完成
	val_h = SPIRBR;  //读数据

	SPITBW = 0xFF;
	while (!RBIF);   //等待接收完成
	val_h = SPIRBR;  //读数据

	SPITBW = 0xFF;
	while (!RBIF);   //等待接收完成
	val_l = SPIRBR;  //读数据

	CSN_1();
	REN = 0;        //关闭接收

	return ((val_h <<8) + val_l);
}

/**************************************************************************
* 函数名称：hw2000b_write_fifo
* 功能描述：写hw2000b FIFO
* 输入参数：addr   FIFO地址
            data   数据地址
            length 数据长度
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_write_fifo(uint8_t addr, uint8_t *data, uint8_t length)
{
	uint16_t i;	
	addr |= 0x80;
	REN = 0;        //关闭接收

	CSN_0();
	SPITBW = addr;           //write addr
	
	for (i = 0; i < length; i++) {
		while (!TBIF);       //waiting for spi txb empty
		SPITBW = data[i];    //write  data
	}
	while (!IDIF);

	CSN_1();
}

/**************************************************************************
* 函数名称：hw2000b_read_fifo
* 功能描述：写hw2000b FIFO
* 输入参数：addr   FIFO地址
            data   数据地址
            length 数据长度
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_read_fifo(uint8_t addr, uint8_t *data, uint8_t length)
{
	uint16_t i;

	SPIEN = 1;      //SPI使能
	REN = 1;        //打开接收

	CSN_0();
	SPITBW = addr;        //write addr
	while (!RBIF);        //waiting for spi rxb full
	data[0] = SPIRBR;
	for (i = 0; i < length; i++) {
		SPITBW = 0xFF;
		while (!RBIF);    //waiting for spi rxb full
		data[i] = SPIRBR;
	}

	CSN_1();
	REN = 0;        //关闭接收
}

