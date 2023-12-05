/**************************************************************************
* ��Ȩ������Copyright@2019 �Ϻ������ز�΢�������޹�˾
* �ļ����ƣ�spi.c
* ����������spiͨѶ����
* �����б�spi_init			
* �ļ����ߣ�Ljj  
* �ļ��汾�� 
* ������ڣ�2023-08-23	
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
#include <hic.h>
#include "type.h"
#include "spi.h"

#define		CSN_0()		CSN = 0
#define		CSN_1()		CSN = 1

uint8_t		val_h, val_l;

/**************************************************************************
* �������ƣ�spi_init
* ������������ʼ��spi
* �����������
* ���ز�������
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
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

	SPIRST = 1;			//��λSPI
    while(SPIRST);
    SPICON0 = 0xF0;     //CKS = Fosc/4 = 32/8 = 4MHz����շ����������������ֽڶ�д 0xF0:Fosc/16 0xE0:Fosc/8 0xD0:Fosc/4 0xC0:Fosc/2
    SPICON1 = 0x00;      //0:�����ط��ͣ��ȣ����½��ؽ��գ��󣩣�
    MS = 0;				//0������ģʽ��1���ӻ�ģʽ
    RBIE = 0;			//�رս����ж�	
    SPIEN = 1;			//SPIʹ��
}

/**************************************************************************
* �������ƣ�hw2000b_write_reg
* ����������дhw2000b�Ĵ���
* ���������addr  �Ĵ�����ַ
            value �Ĵ���ֵ
* ���ز�������
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
void hw2000b_write_reg(uint8_t addr, uint16_t data)
{
	addr |= 0x80;
	REN = 0;        //�رս���

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
* �������ƣ�hw2000b_read_reg
* ������������hw2000b�Ĵ���
* ���������addr  �Ĵ�����ַ
* ���ز�����value �Ĵ���ֵ
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
uint16_t hw2000b_read_reg(uint8_t addr)
{
    CSN_0();
	REN = 1;        //�򿪽���

	SPITBW = addr;
	while (!RBIF);   //�ȴ��������
	val_h = SPIRBR;  //������

	SPITBW = 0xFF;
	while (!RBIF);   //�ȴ��������
	val_h = SPIRBR;  //������

	SPITBW = 0xFF;
	while (!RBIF);   //�ȴ��������
	val_l = SPIRBR;  //������

	CSN_1();
	REN = 0;        //�رս���

	return ((val_h <<8) + val_l);
}

/**************************************************************************
* �������ƣ�hw2000b_write_fifo
* ����������дhw2000b FIFO
* ���������addr   FIFO��ַ
            data   ���ݵ�ַ
            length ���ݳ���
* ���ز�������
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
void hw2000b_write_fifo(uint8_t addr, uint8_t *data, uint8_t length)
{
	uint16_t i;	
	addr |= 0x80;
	REN = 0;        //�رս���

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
* �������ƣ�hw2000b_read_fifo
* ����������дhw2000b FIFO
* ���������addr   FIFO��ַ
            data   ���ݵ�ַ
            length ���ݳ���
* ���ز�������
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
void hw2000b_read_fifo(uint8_t addr, uint8_t *data, uint8_t length)
{
	uint16_t i;

	SPIEN = 1;      //SPIʹ��
	REN = 1;        //�򿪽���

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
	REN = 0;        //�رս���
}

