/*********************************************************
*Copyright (C), 2020, Shanghai Eastsoft Microelectronics Co., Ltd
*�ļ���:  spi_master.c
*��  ��:  AE Team
*��  ��:  v1.0��������iDesigner(v4.2.3.166) + ������HRCC(v1.2.0.106)
*��  ��:  2020/07/08
*��  ��:  SPI����ģʽ��ʾ
          PA6��NSS
          PB4��SCK
          PB5��MOSI
          PB6��MISO
*��  ע:  ���������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
**********************************************************/
#include <hic.h>

#define IT_RECEIVE      //�����ע�͵����ò�ѯ���գ���������жϽ���
#define RXBUF_SIZE 8       //������ջ���������
#define CLRWDT()   {__Asm CWDT;}        //�궨���幷ָ��

typedef unsigned char uchar;
typedef unsigned int uint;

uchar txbuf[8] = {0,1,2,3,4,5,6,7};
uchar rxbuf[RXBUF_SIZE] = {0};
uint rxcnt;

/******************************************************
��������void RAMclear(void)
��  ����RAM���������㣬RAM����ַ0x0000~0x03FF
����ֵ����
���ֵ����
����ֵ����
*******************************************************/
void RAMclear(void)
{
    for (IAAH=0; IAAH<=0x03; IAAH++)
    {
        for (IAAL=0; IAAL<0xFF; IAAL++)
            IAD = 0x00;
        IAD = 0x00;
    }
}

/******************************************************
��������void GPIOInit(void)
��  �������ȳ�ʼ������δ�õ���IO��Ϊ����͵�ƽ
����ֵ����
���ֵ����
����ֵ����
*******************************************************/
void GPIOInit(void)
{
    ANSL = 0xFF;        //ѡ���Ӧ�˿�Ϊ����IO����
	ANSH = 0xFF;
    PAT = 0x00;         //����IO��Ϊ����͵�ƽ
    PBT = 0x00;
    PCT = 0x00;
    PA = 0x00;
    PB = 0x00;
    PC = 0x00;
    PBT6 = 1;       //����MISO��Ϊ����
}

/**********************************************
��������void Init_spi(void)
��  ����SPI��ʼ������
����ֵ����
���ֵ����
����ֵ����
**********************************************/
void Init_spi(void)
{
    SPIRST = 1;     //��λSPI
    while(SPIRST)
        ;
    SPICON0 = 0xF0;       //CKS = Fosc/16����շ�������������
    SPICON1 |= 0<<6;      //0:�����ط��ͣ��ȣ����½��ؽ��գ��󣩣�
    MS = 0;               //0������ģʽ��1���ӻ�ģʽ
#ifdef IT_RECEIVE
    RBIE = 1;       //�򿪽����ж�
#else
    RBIE = 0;       //�رս����ж�
#endif
    REN = 1;        //�򿪽���
    SPIEN = 1;      //SPIʹ��
}
/**********************************************
��������void SPIWriteData(uchar *wbuf,uint n)
��  ����SPI���ݷ��ͳ���
����ֵ������������ʼ��ַ�ͷ��͵����ݸ���
���ֵ����
����ֵ����
**********************************************/
void SPIWriteData(uchar *wbuf,uint n)
{
    uchar i;
    PA6 = 0;    //Ƭѡ����
    for (i=0; i<255; i++)     //��ʱ�ȴ��ӻ�׼��
        ;
    for (i=0 ;i<n; i++)
    {
        SPITBW = *(wbuf+i);
        while(!IDIF);
        CLRWDT();
    }
    PA6 = 1;
}

/**********************************************
��������void SPIReadData(uchar *rbuf,uint n)
��  ����SPI���ݽ��ճ���
����ֵ��������ʼ��ַ�ͷ��͵����ݸ���
���ֵ�����յ�������
����ֵ����
**********************************************/
void SPIReadData(uchar *rbuf,uint n)
{
    uint i;
    PA6 = 0;        //Ƭѡ����
    for (i = 0;i<1000;i++)    //��ʱ�ȴ��ӻ�׼��
        ;

    rxcnt = 0;      //���ռ�����λ
    REN = 1;        //������ʱ�򿪽���

    for (i=0; i<n; i++)
    {
		SPITBW = 0xFF;  //д����
        while(!IDIF);      //�ȴ��������

        if (RBIE == 0)
        {
            while (!RBIF);          //�ȴ��������
            *(rbuf+i) = SPIRBR;     //������
        }
        CLRWDT();
    }
    PA6 = 1;
    REN = 0;  
}

/**********************************************
��������void isr(void) interrupt 
��  ���������жϷ������
����ֵ����
���ֵ����
����ֵ����
**********************************************/
void isr(void) interrupt
{
    if (RBIE==1 && RBIF==1)     //SPI�����ж�
    {
        rxbuf[rxcnt++] = SPIRBR;
        if (rxcnt > RXBUF_SIZE - 1)
            rxcnt = 0;
    }

    SPI_GIEIF = 0;//���жϱ�־
}

/**********************************************
��������void main(void) 
��  ����������
����ֵ����
���ֵ����
����ֵ����
**********************************************/
void main(void) 
{
    uint i;
    GPIOInit();
    Init_spi();
    SPI_GIEIE = 1;  //��SPI�ж�
    GIE = 1;    //�����ж�

    while(1)
    {
		SPIReadData(rxbuf,8);
		for(i = 0;i<10000;i++);

		SPIWriteData(txbuf,8);
		for(i = 0;i<10000;i++);

		CLRWDT();
    }
}
