/**************************************************************************
* 版权声明：Copyright@2020 上海东软载波微电子有限公司
* 文件名称：radio.h
* 功能描述：radio函数
* 函数列表：hw2000b_rf_power_test
			hw2000b_tx_nack
			hw2000b_tx_ack_1000
			hw2000b_rx_test
			hw2000b_set_speed
			hw2000b_set_power
			hw2000b_set_freq
* 文件作者：weiww  
* 文件版本：1.0 
* 完成日期：2020-04-01	
* 修订历史：
* 修订日期：
**************************************************************************/
#ifndef _RADIO_H_
#define _RADIO_H_

#include "type.h"

typedef enum {
    FRAME_NACK_1000,		//发送1000包NACK数据
	FRAME_ACK_1000,			//发送1000包ACK数据
	FRAME_INFINITE,			//不停发送ACK数据
    FRAME_MODE_MAX,
} frame_mode_t;

typedef enum {
    PER_TEST_MODE,			//PER测试
	ACK_TEST_MODE,			//ACK测试
	RX_TEST_MODE_MAX,
} rx_test_mode_t;


typedef enum {
	SPEED_1MBPS_MODE,		//1Mbps
	SPEED_250KBPS_MODE,		//250kbps

	POWER_MAX_MODE,			//最大发射功率
	POWER_5DBM_MODE,		//5dBm
	POWER_0DBM_MODE,		//0dBm
	POWER_N10DBM_MODE,		//-10dBm
	POWER_N20DBM_MODE,		//-20dBm

    FREQ_2403_MODE,			//2.403GHz
	FREQ_2420_MODE,			//2.4020Hz
	FREQ_2450_MODE,			//2.450GHz
	FREQ_2460_MODE,			//2.460GHz
	FREQ_2483_MODE,			//2.483GHz

	CONFIG_MODE_MAX,
} config_mode_t;

void hw2000b_set_config(uint8_t cfg);

/**************************************************************************
* 函数名称：hw2000b_rf_power_test
* 功能描述：RF功率测试
* 输入参数：无
* 返回参数：无
**************************************************************************/
void hw2000b_rf_power_test(void);

/**************************************************************************
* 函数名称：hw2000b_tx_nack_1000
* 功能描述：发送1000包无ACK数据
* 输入参数：mode 发送模式（参考frame_mode_t）：发送1000包NACK数据；不停发送NACK数据
* 返回参数：无
**************************************************************************/
void hw2000b_tx_nack(uint8_t mode);

/**************************************************************************
* 函数名称：hw2000b_tx_ack_1000
* 功能描述：发送1000包含ACK的数据
* 输入参数：无
* 返回参数：无
**************************************************************************/
void hw2000b_tx_ack_1000(void);

/**************************************************************************
* 函数名称：hw2000b_rx_test
* 功能描述：接收测试
* 输入参数：mode 接收测试模式（参考rx_test_mode_t）：PER测试；ACK测试。
* 返回参数：无
**************************************************************************/
void hw2000b_rx_test(uint8_t mode);

void hw2000b_temp_monitor_central(void);

void hw2000b_temp_monitor_periph(uint8_t pipe);

/**************************************************************************
* 函数名称：hw2000b_set_config
* 功能描述：rf参数设置配置
* 输入参数：cfg 参数设置（参考config_mode_t）
* 返回参数：无
**************************************************************************/
void hw2000b_set_config(uint8_t cfg);

void hw2000b_set_tx_packet(void);

#endif



