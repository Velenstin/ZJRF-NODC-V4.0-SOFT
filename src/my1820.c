/**************************************************************************
* ��Ȩ������Copyright@2019 �Ϻ������ز�΢�������޹�˾
* �ļ����ƣ�MY1820.c
* ����������MY1820����
* �����б�MY1820_read_bit
			MY1820_read_byte
			MY1820_write_byte
			MY1820_rst
			MY1820_start
			MY1820_read_temp
* �ļ����ߣ�lihb
* �ļ��汾��1.0 
* ������ڣ�2022-08-10
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
#include <hic.h>
#include "timer.h"
#include "MY1820.h"

#define FILTER_N 15

void MY1820_Rst(void)
{
    MY1820_IO_OUT();   //����Ϊ���
    MY1820_GPIO = 0;
    delay_us(750);
    MY1820_GPIO = 1;
    delay_us(15);
}

//�ȴ�MY1820�Ļ�Ӧ
//����1:δ��⵽MY1820�Ĵ���
//����0:����
uint8_t MY1820_Check(void) 	   
{   
	uint8_t retry=0;
	MY1820_IO_IN();    //����Ϊ����
    while (MY1820_GPIO&&(retry<200))
	{
		retry++;
		delay_us(1);
	};	 
	if(retry>=200)return 1;
	else retry=0;
    while (!MY1820_GPIO&&retry<240)
	{
		retry++;
		delay_us(1);
	};
	if(retry>=240)return 1;	    
	return 0;
}

//��MY1820��ȡһ��λ
//����ֵ��1/0
uint8_t MY1820_Read_Bit(void) 
{
    uint8_t data;
    MY1820_IO_OUT();   //����Ϊ���
    MY1820_GPIO = 0;
	delay_us(2);
    MY1820_GPIO = 1;
	MY1820_IO_IN();    //����Ϊ����
	delay_us(12);
	if(MY1820_GPIO)
        data=1;
    else 
        data=0;	 
    delay_us(50);           
    return data;
}

//��MY1820��ȡһ���ֽ�
//����ֵ������������
uint8_t MY1820_Read_Byte(void)   
{        
  uint8_t i,j,dat;
  dat=0;
	for (i=1;i<=8;i++) 
	{
        j=MY1820_Read_Bit();
        dat=(j<<7)|(dat>>1);
    }						    
  return dat;
}

//дһ���ֽڵ�MY1820
//dat��Ҫд����ֽ�
void MY1820_Write_Byte(uint8_t dat)     
 {             
    uint8_t j;
    uint8_t testb;
    MY1820_IO_OUT();     //����Ϊ���
    for (j=1;j<=8;j++) 
	{
        testb=dat&0x01;
        dat=dat>>1;
        if(testb)       // д1
        {
            MY1820_GPIO = 0;
            delay_us(2);                            
            MY1820_GPIO = 1;
            delay_us(60);               
        }
        else            //д0
        {
            MY1820_GPIO = 0;
            delay_us(60);             
            MY1820_GPIO = 1;
            delay_us(2);                          
        }
    }
}
 
//��ʼ�¶�ת��
void MY1820_Start(void)
{   						               
    MY1820_Rst();	   
    MY1820_Check();	 
    MY1820_Write_Byte(0xcc);// skip rom
    MY1820_Write_Byte(0x44);// convert
}

//��ʼ��MY1820��IO�� DQ ͬʱ���DS�Ĵ���
//����1:������
//����0:����    	 
uint8_t MY1820_Init(void)
{
    MY1820_Rst();
    return MY1820_Check();
}

//��MY1820�õ��¶�ֵ
//���ȣ�0.01C
//����ֵ���¶�ֵ ��-550~1250�� 
int16_t MY1820_Get_Temp(void)
{
    uint16_t buf;
    int16_t temp;
    MY1820_Start ();           //��ʼת��
    //delay_ms(800);
    MY1820_Rst();
    MY1820_Check();	 
    MY1820_Write_Byte(0xcc);   // skip rom
    MY1820_Write_Byte(0xbe);   // convert	    
    buf = MY1820_Read_Byte();     // LSB   
    buf += MY1820_Read_Byte()<<8;     // MSB   
    if(buf > 0x07FF) {
        temp = ~buf+1;
    } else {
        temp = buf;
    }
    
    temp = temp * 0.625;
	temp *= 10;
    
    return temp;  
}
//���ȣ�0.1C
uint16_t MY1820_Get_Temp_By_Median_Average_Filter()
{
    uint16_t filter_buf[FILTER_N] = {0};
    uint16_t filter_temp = 0;
    uint32_t sum = 0;
    uint16_t value = 0;
	uint16_t i,j;
    for(i=0;i<FILTER_N;i++)
    {
        filter_buf[i] = MY1820_Get_Temp();
    }
    
    for(i=0;i<FILTER_N-1;i++)
    {
        for(j=0;j<FILTER_N-1-i;j++)
        {
            if(filter_buf[j]>filter_buf[j+1])
            {
                filter_temp = filter_buf[j];
                filter_buf[j] = filter_buf[j+1];
                filter_buf[j+1] = filter_temp;
            }
        }
    }
    
    for(i=3;i<FILTER_N-3;i++)
    {
        sum += filter_buf[i];
    }
    
    value = sum/(FILTER_N-6);
    
    return value / 10;
}

