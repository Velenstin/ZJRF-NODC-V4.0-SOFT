/**************************************************************************
* 版权声明：Copyright@2019 上海东软载波微电子有限公司
* 文件名称：MY1820.h
* 功能描述：io管脚
* 函数列表：MY1820_start
			MY1820_read_temp
* 文件作者：lihb
* 文件版本：1.0 
* 完成日期：2022-08-10
* 修订历史：
* 修订日期：
**************************************************************************/
#ifndef _MY1820_H_
#define _MY1820_H_

#include "type.h"

#define	MY1820_DIR		PAT4
#define MY1820_GPIO PA4

//IO方向设置
#define MY1820_IO_IN()  MY1820_DIR = 1	//输入模式
#define MY1820_IO_OUT()  MY1820_DIR = 0	//输出模式
   	
uint8_t MY1820_Init(void);			//初始化MY1820
int16_t MY1820_Get_Temp(void);	//获取温度
void MY1820_Start(void);		//开始温度转换
void MY1820_Write_Byte(uint8_t dat);//写入一个字节
uint8_t MY1820_Read_Byte(void);		//读出一个字节
uint8_t MY1820_Read_Bit(void);		//读出一个位
uint8_t MY1820_Check(void);			//检测是否存在MY1820
void MY1820_Rst(void);			//复位MY1820 
uint16_t MY1820_Get_Temp_By_Median_Average_Filter(void);

#endif
