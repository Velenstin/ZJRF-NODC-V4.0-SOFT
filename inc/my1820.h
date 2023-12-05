/**************************************************************************
* ��Ȩ������Copyright@2019 �Ϻ������ز�΢�������޹�˾
* �ļ����ƣ�MY1820.h
* ����������io�ܽ�
* �����б�MY1820_start
			MY1820_read_temp
* �ļ����ߣ�lihb
* �ļ��汾��1.0 
* ������ڣ�2022-08-10
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
#ifndef _MY1820_H_
#define _MY1820_H_

#include "type.h"

#define	MY1820_DIR		PAT4
#define MY1820_GPIO PA4

//IO��������
#define MY1820_IO_IN()  MY1820_DIR = 1	//����ģʽ
#define MY1820_IO_OUT()  MY1820_DIR = 0	//���ģʽ
   	
uint8_t MY1820_Init(void);			//��ʼ��MY1820
int16_t MY1820_Get_Temp(void);	//��ȡ�¶�
void MY1820_Start(void);		//��ʼ�¶�ת��
void MY1820_Write_Byte(uint8_t dat);//д��һ���ֽ�
uint8_t MY1820_Read_Byte(void);		//����һ���ֽ�
uint8_t MY1820_Read_Bit(void);		//����һ��λ
uint8_t MY1820_Check(void);			//����Ƿ����MY1820
void MY1820_Rst(void);			//��λMY1820 
uint16_t MY1820_Get_Temp_By_Median_Average_Filter(void);

#endif
