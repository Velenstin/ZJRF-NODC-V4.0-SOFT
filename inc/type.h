/**************************************************************************
* ��Ȩ������Copyright@2019 �Ϻ������ز�΢�������޹�˾
* �ļ����ƣ�type.h
* �������������ú궨��
* �����б�
* �ļ����ߣ�Ljj  
* �ļ��汾�� 
* ������ڣ�2023-08-23	
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
#ifndef _TYPE_H_
#define _TYPE_H_

#define BIT0 (1 << 0)
#define BIT1 (1 << 1)
#define BIT2 (1 << 2)
#define BIT3 (1 << 3)
#define BIT4 (1 << 4)
#define BIT5 (1 << 5)
#define BIT6 (1 << 6)
#define BIT7 (1 << 7)

#define NULL 0

#define TRUE    1
#define FALSE   0

#define SUCCEED 1
#define FAILED  0

#define NOP()   __Asm nop
#define SLEEP() __Asm IDLE
#define CWDT()  __Asm CWDT
#define EI()    GIE = 1
#define DI()    GIE = 0
    
typedef unsigned char   uint8_t;  //8λ�޷�����
typedef unsigned short  uint16_t; //16λ�޷�����
typedef unsigned long   uint32_t; //32λ�޷�����
 
typedef volatile unsigned char  vuint8_t;  //ÿ�δӵ�ַ��ȡ8λ�޷�����
typedef volatile unsigned short vuint16_t; //ÿ�δӵ�ַ��ȡ16λ�޷�����
typedef volatile unsigned long  vuint32_t; //ÿ�δӵ�ַ��ȡ32λ�޷�����
 
typedef signed char  int8_t;   //8λ�з�����
typedef signed short int16_t;  //16λ�з�����
typedef signed long  int32_t;  //32λ�з�����
 
typedef volatile signed char  vint8_t;    //ÿ�δӵ�ַ��ȡ8λ�з�����
typedef volatile signed short vint16_t;   //ÿ�δӵ�ַ��ȡ16λ�з�����
typedef volatile signed long  vint32_t;   //ÿ�δӵ�ַ��ȡ32λ�з�����

typedef enum {
    HW2000B = 0,
    HW3000,
    NO_DEVICE,
    DEVICE_MAX,
} device_t;

#endif
