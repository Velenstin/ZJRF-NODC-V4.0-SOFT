/**************************************************************************
* ��Ȩ������Copyright@2019 �Ϻ������ز�΢�������޹�˾
* �ļ����ƣ�main.c
* ����������	
* �����б�
* �ļ����ߣ�Ljj  
* �ļ��汾�� 
* ������ڣ�2023-08-23	
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
#include <hic.h>
#include "string.h" 
#include "io.h"
#include "hw2000b.h"
#include "timer.h"
#include "ram.h"
#include "spi.h"

#define CLRWDT()   {__Asm CWDT;}        //�궨���幷ָ��

uint16_t	_ack_count;
sbit		_hw2000b_irq_request;	//��Ƶ�жϱ�־
sbit		rx_ok;

uint8_t sleep_flag = 0;
uint8_t RX_OK_flag = 0;

uint8_t rxbuf[40];

uint8_t timer_cnt;

#define STARTADDR    0xC000     //�궨��������IAP������ʼ��ַ
#define ENDADDR      0xC002     //�궨��������IAP����������ַ
#define WRDATA       0x87654321     //�궨���д������

#define DATA_1_ADDR	0xC000
#define DATA_2_ADDR	0xC001
#define DATA_3_ADDR	0xC002

uint8_t dataerr = 0;      //0��д���������ȣ�1��д�����������

uint8_t CallFlashEn,FlashEwEn;//���������


static volatile unsigned int section8 FRAN @ 0xFF8E;
static volatile unsigned int section8 FRA  @ 0xFF90;

/******************************************************
��������void StartIAP(void)
��  ������ʼIAP������ע�⣺IAP�̶�������ʽ��ʹ��ʱ���ɸı�
����ֵ����
���ֵ����
����ֵ����
*******************************************************/
void StartIAP(void)
{
    __asm{
          MOVI 0x55
          MOVA ROMCH
          MOVI 0xFF     //8��NOP������俪ʼ
          SECSEL &FlashEwEn& % 0x80//ѡ��������ڵ�section
          XOR &FlashEwEn& % 0x80,0//0xFF xor 0xAA = 0x55
          SECSEL &CallFlashEn& % 0x80//ѡ��������ڵ�section
          XOR &CallFlashEn& % 0x80,0//��CallFlashEn�ڵ��ú���ǰΪ0x55��0x55 xor 0x55 = 0x00
          JBS PSW,Z//���������Ϊ0x00����ִ����ȷ��������һ��NOP
          GOTO $+3
          NOP//8��NOP����������
          MOVI 0xAA
          MOVA ROMCH
          MOVI 0xFF     //8��NOP������俪ʼ
          SECSEL &FlashEwEn& % 0x80//ѡ��������ڵ�section
          XOR &FlashEwEn& % 0x80,0//0xFF xor 0xAA = 0x55
          SECSEL &CallFlashEn& % 0x80//ѡ��������ڵ�section
          XOR &CallFlashEn& % 0x80,0//��CallFlashEn�ڵ��ú���ǰΪ0x55��0x55 xor 0x55 = 0x00
          JBS PSW,Z//���������Ϊ0x00����ִ����ȷ��������һ��NOP
          GOTO $+3
          NOP//8��NOP����������
          BSS ROMCL,WR     //������̲���
          JBC ROMCL,WR
          goto $-1         //�ȴ���������
        }
}

/*******************************************************
��������void DataFlashErsPage(void)
��  ��������DataFlash��ҳ(256 word)����ַ��Χ��0xC000~0xC1FF
����ֵ��DataFlash��ַaddr��DataFlashȡ����ַaddri
���ֵ����
����ֵ����
*******************************************************/
void DataFlashErsPage(unsigned int addr, unsigned int addri)
{
	unsigned char gie_bk = GIE;		//����GIE
    CLRWDT();
	while(GIE == 1)GIE = 0;            //����IAPǰ�ر�ȫ���ж�
	FlashEwEn = 0xAA;//�������������

    FPEE = 1;           //�洢������ģʽ
    FRAH = addr>>8;
    FRAL = addr;
    FRAHN = addri>>8;      //IAP����/��̱��������ַȡ���߼�
    FRALN = addri;     

    WREN = 1;           //ʹ�ܲ���/��̹���
    StartIAP();         //��ʼIAP����
	CallFlashEn = 0;//�������������
	FlashEwEn = 0;
    ROMCL = 0x00;       //�˳�IAP
	FRA = 0xFF12;//ָ�����õĵ�ַ�ռ�
	FRAN = 0x3456;//�˴��ѵ�ַ���븳����0xFFFF��FRA��ȡ����ϵ��ֵ
	GIE = gie_bk;       //�ָ�ȫ���ж�
}

/*******************************************************
��������unsigned long DataFlashRdData(unsigned int addr)
��  ������Flashָ����ַ������
����ֵ��DataFlash��ַaddr����ַ��Χ��0xC000~0xC1FF
���ֵ����
����ֵ��DataFlashָ����ַ������
*******************************************************/
unsigned long DataFlashRdData(unsigned int addr)
{
	unsigned long data;
	unsigned char gie_bk = GIE;	  //����GIE
    CLRWDT();
	while(GIE == 1)GIE = 0;
    FRAL = addr;
    FRAH = addr>>8;
	DATARDTRG=1;
	while(DATARDTRG);
	DATARDEN=1;         //DATA������ʹ��
    __Asm TBR;          //����ָ��
    data = ((unsigned long)ROMD1H<<24) | ((unsigned long)ROMD1L<<16) | ((unsigned long)ROMDH<<8) | ROMDL;
	DATARDEN=0;         //DATA��������ֹ
    GIE = gie_bk;       //�ָ�ȫ���ж�
	return data;
}

/*******************************************************
��������void DataFlashWrData(unsigned int addr, unsigned long word)
��  ����дDataFlashָ����ַ�����ݣ���ַ��Χ��0xC000~0xC1FF
����ֵ��DataFlash��ַaddr��DataFlashȡ����ַaddri����д������word
���ֵ����
����ֵ��0:д��ʧ�ܣ�1:д��ɹ�
*******************************************************/
unsigned char DataFlashWrData(unsigned int addr, unsigned int addri, unsigned long word)
{
    unsigned char rmdh,rmdl,rmd1h,rmd1l;      //��ʱ���ROMDH��ROMDLֵ
	unsigned char gie_bk = GIE;	  //����GIE
    CLRWDT();
	while(GIE == 1)GIE = 0;            //����IAPǰ�ر�ȫ���ж�
	FlashEwEn = 0xAA;//�������������

    FPEE = 0;           //�洢�����ģʽ
    ROMD1H = word>>24;    //дWord
    ROMD1L = word>>16;
    ROMDH = word>>8;
    ROMDL = word;
    FRAH = addr>>8;     //IAP��̵�ַ
    FRAL = addr;
    FRAHN = addri>>8;      //IAP����/��̱��������ַȡ���߼�
    FRALN = addri;       

    WREN = 1;           //ʹ�ܱ��
    StartIAP();         //��ʼIAP����
	CallFlashEn = 0;//�������������
	FlashEwEn = 0;
    rmdh = ROMDH++;
    rmdl = ROMDL++;
    rmd1h = ROMD1H++;
    rmd1l = ROMD1L++;
	DATARDEN=1;      //DATA������ʹ��
    FRAH = addr>>8;
    FRAL = addr;
	DATARDTRG=1;     //DATA����������
	while(DATARDTRG);
    __Asm TBR;          //����ָ��
    if (ROMDH!=rmdh || ROMDL!=rmdl || ROMD1H!=rmd1h || ROMD1L!=rmd1l)
	{
        ROMCL = 0x00;       //�˳�IAP
		return 0;
	}
	FRA = 0xFF12;//ָ�����õĵ�ַ�ռ�
	FRAN = 0x3456;//�˴��ѵ�ַ���븳����0xFFFF��FRA��ȡ����ϵ��ֵ
	ROMDH = 0xFF;//���ݳ�ʼ��Ϊ0xFF
	ROMDL = 0xFF;//���ݳ�ʼ��Ϊ0xFF
	ROMD1H = 0xFF;//���ݳ�ʼ��Ϊ0xFF
	ROMD1L = 0xFF;//���ݳ�ʼ��Ϊ0xFF
    ROMCL = 0x00;       //�˳�IAP
	DATARDEN=0;   //DATA��������ֹ
	GIE = gie_bk;       //�ָ�ȫ���ж�
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
��������void sleep(void)
��  ��������IDLEģʽ
����ֵ����
���ֵ����
����ֵ����
**********************************************/
void sleep(void)
{
	T8NEN = 0;				//����T8N
    RX0EN = 0;				//���ܴ��ڽ���

	INTC0 = 0xFF;			//PINT0-˫���ж�
	PIE0 = 1;				//��PINT0�ܽ��ж�
    PIF0 = 0;				//˯��ǰ���жϱ�־λ

	KMSK4 = 0;				//KINT4����
	INTF0 = 0x00;			//����жϱ�־
	INTE0 = 0x00;			//����KIE

	GIE = 0;				//�ر����ж�

							
	PWEN &= 0xFD;			//��ֹIDLE״̬�¼���
	WKDC = 0x1F;
	PWRC = 0x8F;			//ѡ��IDLEģʽ
    __Asm IDLE;				//����IDLEģʽ

	GIE = 1;				//�����ж�

	KMSK4 = 1;				//KINT4ȡ������
	INTF0 = 0x00;			//����жϱ�־
	INTE0 |= 0x10;			//ʹ��KIE

	INTC0 = 0xFF;			//PINT0-˫���ж�
	PIE0 = 0;				//�ر�PINT0�ܽ��ж�
    PIF0 = 0;				//˯��ǰ���жϱ�־λ

	T8NIE = 1;				//�򿪶�ʱ������ж�
	T8NIF = 0;				//���־λ
	T8N = 131;				//����������ֵ   2ms
	T8NEN = 1;				//ʹ��T8N

	timer_cnt = 250;

	RX0EN = 1;			//ʹ�ܴ��ڽ���
}


void WDT_Init(void)
{
    WDTC = 0x16;         //��Ƶ��1:128��ʹ��WDTԤ��Ƶ�������Ź����ʱ��t=256*128/32000=1.024s
    PWEN &= 0xFD;
    PWEN |= 0<<1;		//��ֹIDLE״̬�¼���
}

void UART_Init(void)
{
    RX0LEN = 0;     //8λ���ݽ��ո�ʽ
    TX0LEN = 0;     //8λ���ݷ��͸�ʽ
	//BJT0EN = 1;		//������ȥ��ʹ��
    //BRGH0 = 0;      //�����ʵ���ģʽ��������=Fosc/(64*BRRDIV))
    //BR0R = 0xD0;    //��������������=16MHz/(64*1200bps)=208.3333
	//BR0FRA = 0x05;	//������С������=16*0.3333 �� 5

    //BRGH0 = 0;      //�����ʵ���ģʽ��������=Fosc/(64*(BRR<7:0>+1))
    //BR0R = 0x19;    //������=16MHz/(64*(25+1))��9600bps

    BRGH0 = 0;      //�����ʵ���ģʽ��������=Fosc/(64*(BRR<7:0>+1))
    BR0R = 0x33;    //������=16MHz/(64*(51+1))��4800bps

	RX0TXEN = 1;		//���ڹܽŽ�����RX0=0 ,TX0=1

	RX0IE = 1;			//�����ж�
	//RX0EN = 1;          //�򿪴��ڽ���
}

void TIME_Init(void)
{
    T8NC = 0x0E;         //��ʱ��ģʽ��Ԥ��Ƶ1:(Fosc/2)/128
    T8N = 131;           //����������ֵ   2ms
    T8NIE = 1;           //�򿪶�ʱ������ж�
    T8NIF = 0;           //�������־λ

    T8NEN = 1;           //ʹ��T8N

	timer_cnt = 250;	 //
}


/**************************************************************************
* �������ƣ�main
* �����������������
* �����������
* ���ز�������
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
void main(void) 
{
    GPIOInit();										//��ʼ��GPIO
	WDT_Init();										//��ʼ�����Ź�
	UART_Init();									//��ʼ������
	TIME_Init();									//��ʼ����ʱ��

	rxbuf[0] = 0;									//�崮�ڼ���ֵ
	RX_OK_flag = 0;									//�崮�ڽ�����ɱ�־
	sleep_flag = 1;									//�ϵ�����

	spi_init();										//��ʼ��SPI�˿�

	hw2000b_port_init();							//��ʼ����Ƶ�˿�
	hw2000b_init_250k();							//��ʼ����Ƶ����
	hw2000b_power_down();							//�ر���Ƶģ��

	GIE = 1;										//ȫ���ж�ʹ��

	while(1) 
	{
		if(sleep_flag)							//˯�߱�־λ�ж�
		{
			sleep();							//����˯�ߺ���
			sleep_flag = 0;						//��˯�߱�־λ
		}

		if (RX_OK_flag)							//���ڽ�����ɱ�־λ�ж�
		{
			RX_OK_flag = 0;						//�������ɱ�־λ
			CLRWDT();

			hw2000b_power_on();					//����Ƶģ��
			hw2000b_tx_data(rxbuf, rxbuf[0] + 1);	//���ʹ�������
			hw2000b_power_down();				//�ر���Ƶģ��
			CLRWDT();

			rxbuf[0] = 0;						//�������ֵ

			sleep_flag = 1;						//��˯�߱�־λ
		}

        CLRWDT();								//�忴�Ź�
	}
}

/**************************************************************************
* �������ƣ�isr
* �����������ж���ں���
* �����������
* ���ز�������
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
void isr(void) interrupt
{
	uint8_t y;


    if(PIE0==1 && PIF0==1)
    {
        PIF0 = 0;					//����ⲿ�ж�
    }

    if (T8NIE==1 && T8NIF==1)       //��ʱ��2ms����ж�
    {
        T8NIF = 0;					//���־λ
        T8N = 131;					//���ж��ȸ���������ֵ

		if (timer_cnt < 250)
		{
			timer_cnt++;
			if (timer_cnt >= 4)		//���ֽڼ��8ms
			{
				timer_cnt = 250;
				RX_OK_flag = 1;		//��λ��ɱ�־
			}
		
		}
    }

    if(RX0IE==1 && RX0IF==1)
    {
		timer_cnt = 0;				//���¼���
		rxbuf[rxbuf[0] + 1] = RX0B;
		rxbuf[0] = rxbuf[0] + 1;

		if(rxbuf[0] > 30)			//��������
		{
			rxbuf[0] = 30;
		}
    }

	if(KIE && KMSK4 && KIF)
    {
		KIF = 0;       //����ⲿ�ж�
		if(IRQ)
		{
			_hw2000b_irq_request = 1;
		}
    }

}


