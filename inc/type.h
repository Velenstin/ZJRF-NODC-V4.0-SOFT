/**************************************************************************
* 版权声明：Copyright@2019 上海东软载波微电子有限公司
* 文件名称：type.h
* 功能描述：常用宏定义
* 函数列表：
* 文件作者：Ljj  
* 文件版本： 
* 完成日期：2023-08-23	
* 修订历史：
* 修订日期：
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
    
typedef unsigned char   uint8_t;  //8位无符号数
typedef unsigned short  uint16_t; //16位无符号数
typedef unsigned long   uint32_t; //32位无符号数
 
typedef volatile unsigned char  vuint8_t;  //每次从地址读取8位无符号数
typedef volatile unsigned short vuint16_t; //每次从地址读取16位无符号数
typedef volatile unsigned long  vuint32_t; //每次从地址读取32位无符号数
 
typedef signed char  int8_t;   //8位有符号数
typedef signed short int16_t;  //16位有符号数
typedef signed long  int32_t;  //32位有符号数
 
typedef volatile signed char  vint8_t;    //每次从地址读取8位有符号数
typedef volatile signed short vint16_t;   //每次从地址读取16位有符号数
typedef volatile signed long  vint32_t;   //每次从地址读取32位有符号数

typedef enum {
    HW2000B = 0,
    HW3000,
    NO_DEVICE,
    DEVICE_MAX,
} device_t;

#endif
