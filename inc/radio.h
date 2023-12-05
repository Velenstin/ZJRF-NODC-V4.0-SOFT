/**************************************************************************
* ��Ȩ������Copyright@2020 �Ϻ������ز�΢�������޹�˾
* �ļ����ƣ�radio.h
* ����������radio����
* �����б�hw2000b_rf_power_test
			hw2000b_tx_nack
			hw2000b_tx_ack_1000
			hw2000b_rx_test
			hw2000b_set_speed
			hw2000b_set_power
			hw2000b_set_freq
* �ļ����ߣ�weiww  
* �ļ��汾��1.0 
* ������ڣ�2020-04-01	
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
#ifndef _RADIO_H_
#define _RADIO_H_

#include "type.h"

typedef enum {
    FRAME_NACK_1000,		//����1000��NACK����
	FRAME_ACK_1000,			//����1000��ACK����
	FRAME_INFINITE,			//��ͣ����ACK����
    FRAME_MODE_MAX,
} frame_mode_t;

typedef enum {
    PER_TEST_MODE,			//PER����
	ACK_TEST_MODE,			//ACK����
	RX_TEST_MODE_MAX,
} rx_test_mode_t;


typedef enum {
	SPEED_1MBPS_MODE,		//1Mbps
	SPEED_250KBPS_MODE,		//250kbps

	POWER_MAX_MODE,			//����书��
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
* �������ƣ�hw2000b_rf_power_test
* ����������RF���ʲ���
* �����������
* ���ز�������
**************************************************************************/
void hw2000b_rf_power_test(void);

/**************************************************************************
* �������ƣ�hw2000b_tx_nack_1000
* ��������������1000����ACK����
* ���������mode ����ģʽ���ο�frame_mode_t��������1000��NACK���ݣ���ͣ����NACK����
* ���ز�������
**************************************************************************/
void hw2000b_tx_nack(uint8_t mode);

/**************************************************************************
* �������ƣ�hw2000b_tx_ack_1000
* ��������������1000����ACK������
* �����������
* ���ز�������
**************************************************************************/
void hw2000b_tx_ack_1000(void);

/**************************************************************************
* �������ƣ�hw2000b_rx_test
* �������������ղ���
* ���������mode ���ղ���ģʽ���ο�rx_test_mode_t����PER���ԣ�ACK���ԡ�
* ���ز�������
**************************************************************************/
void hw2000b_rx_test(uint8_t mode);

void hw2000b_temp_monitor_central(void);

void hw2000b_temp_monitor_periph(uint8_t pipe);

/**************************************************************************
* �������ƣ�hw2000b_set_config
* ����������rf������������
* ���������cfg �������ã��ο�config_mode_t��
* ���ز�������
**************************************************************************/
void hw2000b_set_config(uint8_t cfg);

void hw2000b_set_tx_packet(void);

#endif



