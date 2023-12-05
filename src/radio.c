/**************************************************************************
* 版权声明：Copyright@2020 上海东软载波微电子有限公司
* 文件名称：radio.c
* 功能描述：radio函数
* 函数列表：hw2000b_set_tx_packet
			num_to_char
			hw2000b_rf_power_test
			hw2000b_tx_nack
			hw2000b_tx_ack_1000
			hw2000b_rx_test
			hw2000b_set_speed
			hw2000b_set_power
			hw2000b_set_freq
* 文件作者：lihb
* 文件版本：1.0 
* 完成日期：2022-08-10	
* 修订历史：
* 修订日期：
**************************************************************************/
#include "type.h"
#include "string.h"
#include "spi.h"
#include "radio.h"
#include "hw2000b.h"
#include "timer.h"
#include "io.h"
#include "ram.h"


extern	sbit	_back_key_request;
extern	sbit	_ok_key_request;
extern	sbit	_scroll_key_request;
extern	sbit	_hw2000b_irq_request;	//射频中断标志
extern	sbit	_speed_flag;		//speed flag   0x00:1Mbps   0x01:250Kbps

extern	uint16_t	_tx_count;		//发送包数计数
extern	uint16_t	_rx_count;		//接收包数计数
extern	uint16_t	_ack_count;		//ACK发送包数计数
extern	uint8_t		_rf_buffer[64];	//射频数据数组

/**************************************************************************
* 函数名称：hw2000b_set_tx_packet
* 功能描述：设置射频发送包
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_set_tx_packet(void)
{
    uint8_t i;

	_rf_buffer[0] = 20;
	for (i = 1; i < 16; i++)
        _rf_buffer[i] = i;

	_rf_buffer[16]++ ;
	_tx_count++;
    _rf_buffer[17] = (_tx_count>>8) & 0xFF;
    _rf_buffer[18] =  _tx_count & 0xFF;

	_rf_buffer[19] = 0;
	_rf_buffer[20] = 0;
}

/**************************************************************************
* 函数名称：hw2000b_rf_power_test
* 功能描述：RF功率测试
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_rf_power_test(void)
{
	uint16_t i;
	const char *banner0;
	const char *banner1;

	banner0 = "RF Power         ";
	banner1 = "Single Wave      ";

	lcd_print(0, banner0, 0);
	lcd_print(1, banner1, 0);

	hw2000b_power_test();
	i = 0;
	while(1) {
		tx_led_on();
		uint8_t banner[18]= "                 ";
		banner[i] = '>';
		i++;
		i %= 17;
		lcd_print_string(2, banner, 0);
		delay_ms(100);

		if (_back_key_request) {
			hw2000b_cancel_sw();
			tx_led_off();
			break;
		}
	}
}

/**************************************************************************
* 函数名称：hw2000b_tx_nack_1000
* 功能描述：发送1000包无ACK数据
* 输入参数：mode 发送模式（参考frame_mode_t）：发送1000包NACK数据；不停发送NACK数据
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_tx_nack(uint8_t mode)
{
	uint16_t i;
	uint8_t banner0[18]    = "Frame Send       ";
	const char *banner1;
	uint8_t banner2[18] = "now:00000        ";

	if(mode == FRAME_NACK_1000) {
		banner1 = "all:01000        ";
	} else if(mode == FRAME_INFINITE) {
		banner1 = "Infinite         ";
	}

	lcd_print_string(0, banner0, 0);
	lcd_print(1, banner1, 0);
	lcd_print_string(2, banner2, 0);
	
	i = 0;
	_tx_count = 0;
	while(1) {
		tx_led_on();
		hw2000b_set_tx_packet();
        _rf_buffer[19] = 0x03;
        _rf_buffer[20] = 0xE8;
		hw2000b_tx_data(_rf_buffer, 21); //tx function

		i++;

		lcd_print_num(2, 4, i);

		delay_ms(10);
		tx_led_off();
		delay_ms(10);
		if((mode == FRAME_NACK_1000) && (i == 1000)) {
			break;
		}
		if(_back_key_request) {
			break;
		}
	}
}

/**************************************************************************
* 函数名称：hw2000b_tx_ack_1000
* 功能描述：发送1000包含ACK的数据
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_tx_ack_1000(void)
{
	uint16_t i;
	uint8_t banner0[18] = "Frame Send       ";
	uint8_t banner1[18] = "all:01000        ";
	uint8_t banner2[18] = "now:00000        ";
	uint8_t banner3[18] = "ACK:00000        ";

	lcd_print_string(0, banner0, 0);
	lcd_print_string(1, banner1, 0);
	lcd_print_string(2, banner2, 0);
	lcd_print_string(3, banner3, 0);
	
	_tx_count = 0;
	_ack_count = 0;
	hw2000b_write_reg(0x3C, 0x3003);
	for(i=0; i<1000; i++) {
		tx_led_on();
		hw2000b_set_tx_packet();
		hw2000b_tx_data(_rf_buffer, 21); //tx function
		
		lcd_print_num(2, 4, i+1);

		lcd_print_num(3, 4, _ack_count);
							
		delay_ms(10);
		tx_led_off();
		delay_ms(10);
		if (_back_key_request) {
			break;
		}
	}
	hw2000b_write_reg(0x3C, 0x3000);
}

/**************************************************************************
* 函数名称：hw2000b_rx_test
* 功能描述：接收测试
* 输入参数：mode 接收测试模式（参考rx_test_mode_t）：PER测试；ACK测试。
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_rx_test(uint8_t mode)
{
	uint16_t reg, rx_cnt;
	const char *banner0;
	const char *banner1;
	uint8_t banner2[18];

	if(mode == PER_TEST_MODE) {
		banner0 = "PER Test         ";
		banner1 = "Rec PKG Num      ";
	} else if(mode == ACK_TEST_MODE) {
		banner0 = "ACK Test         ";
		banner1 = "Rec PKG Num      ";
		hw2000b_write_reg(0x3C, 0x3003);
	}
	strcpy_c((char*)banner2, "00000       ");

	lcd_print(0, banner0, 0);
	lcd_print(1, banner1, 0);
	lcd_print_string(2, banner2, 0);

	rx_cnt = 0;
	
	while(1) {
		memset(_rf_buffer, 0, 64);
		_hw2000b_irq_request = 0;
		hw2000b_write_reg(0x36, 0x0080); //FIFO0 enable
		hw2000b_write_reg(0x37, 0x0000); //FIFO1 disable
		hw2000b_write_reg(0x21, 0x0080); //RX enable 
		while ((!_hw2000b_irq_request)&&(!_back_key_request));

		if(!_back_key_request){
			reg = hw2000b_read_reg(0x36);
			if ((reg & 0x2000) == 0){     
				rx_led_on();
				hw2000b_read_fifo(0x32, _rf_buffer, 21);
				rx_cnt++;	
				
				lcd_print_num(2, 0, rx_cnt);

				delay_ms(5);
				rx_led_off();
			}
		}
		hw2000b_write_reg(0x21, 0x0000); //TX disable
		hw2000b_write_reg(0x23, 0x431B); //Soft reset
		hw2000b_write_reg(0x23, 0x031B); 
		if (_back_key_request){
			break;
		}
	}
	hw2000b_write_reg(0x3C, 0x3000);
}

/**************************************************************************
* hw2000b_temp_monitor_central
* 功能描述：一对多通信中的主机
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_temp_monitor_central(void)
{
	uint16_t j, k;
    uint16_t temperature;
	uint16_t reg;
	uint32_t time;
	uint8_t banner_c[18];
    uint8_t banner_p[18];
	const char *banner0;
	uint8_t index;

	banner0 = "Central           ";

	strcpy_c((char*)banner_c, "Central:          ");
	strcpy_c((char*)banner_p, "PIPE :            ");

	lcd_print(0, banner0, 0);
	lcd_print_string(1, banner_c, 0);
	banner_p[4] = 0 + '0';
	lcd_print_string(2, banner_p, 0);
	banner_p[4] = 1 + '0';
	lcd_print_string(3, banner_p, 0);
	banner_p[4] = 2 + '0';
	lcd_print_string(4, banner_p, 0);
	banner_p[4] = 3 + '0';
	lcd_print_string(5, banner_p, 0);

	temperature = 0;
	while(1) {
		index = 8;
		if(temperature > 0x7FFF) {
            banner_c[index++] = '-';
            j = ~temperature + 1;
        } else {
            banner_c[index++] = ' ';
            j = temperature;
        }
		j %= 1000;
        banner_c[index++] = (j / 100) + 48;
        j %= 100;
        banner_c[index++] = (j / 10) + 48;
        j %= 10;
        banner_c[index++] = '.';
        banner_c[index++] = j + 48;
        banner_c[index++] = 0xA1;   //℃ 0xA1E6
        banner_c[index++] = 0xE6;
        lcd_print_string(1, banner_c, 0);

		 mmemset( _rf_buffer, 0, 64 );  //clear hw2000b Buffer 
        _hw2000b_irq_request = 0;
        hw2000b_write_reg(0x3C, 0xF000);
        hw2000b_write_reg(0x36, 0x0080); //FIFO0 enable
        hw2000b_write_reg(0x37, 0x0000); //FIFO1 disable
        hw2000b_write_reg(0x21, 0x0080); //RX enable 

		time = 0xFFFFFFFF - 4800000;
		while ((!_hw2000b_irq_request)&&(!_back_key_request)&&(time++));

		if((!_back_key_request) && (time != 1)){
            reg = hw2000b_read_reg(0x36);
            if ((reg & 0x2000) == 0){     
                rx_led_on();
                hw2000b_read_fifo(0x32, _rf_buffer, 5); 
                if((_rf_buffer[3] == 0xA1) && (_rf_buffer[4] == 0xE6)) {
                
                    j = (_rf_buffer[1] << 8) + _rf_buffer[2];
                    index = 6;
                    if(j > 0x7FFF) {
                        banner_p[index++] = '-';
                        j = ~j + 1;
                    } else {
                        banner_p[index++] = ' ';
                        j = j;
                    }
                    j %= 1000;
                    banner_p[index++] = (j / 100) + 48;
                    j %= 100;
                    banner_p[index++] = (j / 10) + 48;
                    j %= 10;
                    banner_p[index++] = '.';
                    banner_p[index++] = j + 48;
                    banner_p[index++] = 0xA1;   //℃ 0xA1E6
                    banner_p[index++] = 0xE6;
                    
                    k = (reg & 0x0E00) >> 9;
                    banner_p[4] = k + '0';
                    lcd_print_string(k + 2, banner_p, 0);
                }
            }
        }
		hw2000b_write_reg(0x3D, 0x0008); // clear int0
        hw2000b_write_reg(0x21, 0x0000); //RX disable 

		if(time < 50000) {		//10ms
			delay_ms(10);
		}
        rx_led_off();
        temperature = 0;

		if (_back_key_request){
            break;
        }

	}
}

/**************************************************************************
* hw2000b_temp_monitor_periph
* 功能描述：一对多通信中的从机
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_temp_monitor_periph(uint8_t pipe)
{
	uint16_t j;
    uint16_t temperature;
    uint8_t banner[18];
	uint8_t banner0[18];
	const char *banner1;

	if (pipe > 3) {
        pipe = 0;
    }

	banner1 = "Temperature:     ";

	strcpy_c((char*)banner0, "PIPE :          ");
	banner0[4] = pipe + '0';

	lcd_print_string(1, banner0, 0);
	lcd_print(1, banner1, 0);


	temperature = 0;

	while(1) {
		_rf_buffer[0] = 4;
        _rf_buffer[1] = temperature >> 8;
        _rf_buffer[2] = temperature;
        _rf_buffer[3] = 0xA1;
        _rf_buffer[4] = 0xE6;

		hw2000b_write_reg(0x3C, 0x0000 | (1 << (pipe + 12))); //pipe0 enable, pipe0 ack disable;
        hw2000b_write_reg(0x36, 0x0080 | (pipe << 1));
		hw2000b_tx_data(_rf_buffer, 5); //tx function

		if(temperature > 0x7FFF) {
            banner[0] = '-';
            j = ~temperature + 1;
        } else {
            banner[0] = ' ';
            j = temperature;
        }
        banner[1] = (j / 100) + 48;
        j %= 100;
        banner[2] = (j / 10) + 48;
        j %= 10;
        banner[3] = '.';
        banner[4] = j + 48;
        banner[5] = 0xA1;   //℃ 0xA1E6
        banner[6] = 0xE6;
        banner[7] = ' ';
        banner[8] = ' ';
        lcd_print_string(2, banner, 0);

		delay_ms(10);
        tx_led_off();

		temperature = 0;

		for(j=0; j<10; j++) {
			delay_ms(100);
			if (_back_key_request) {
				break;
			}
		}

		if (_back_key_request) {
			hw2000b_write_reg(0x3C, 0x3000);
			break;
		}
	}
}

/**************************************************************************
* 函数名称：hw2000b_set_config
* 功能描述：rf参数设置配置
* 输入参数：cfg 参数设置（参考config_mode_t）
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_set_config(uint8_t cfg)
{
	const char *banner0 = "                 ";

	if(cfg == SPEED_1MBPS_MODE) {
		hw2000b_port_init();
		banner0 = "1Mbps Set!       ";
		hw2000b_init_1m();
		_speed_flag = SPEED_1MBPS_MODE;

	} else if(cfg == SPEED_250KBPS_MODE){
		hw2000b_port_init();
		banner0 = "250kbps set!     ";
		hw2000b_init_250k();
		_speed_flag = SPEED_250KBPS_MODE;

	} else if(cfg == POWER_MAX_MODE) {
		banner0 = "8dBm set!        ";
		hw2000b_set_power_max();

	}else if(cfg == POWER_5DBM_MODE) {
		banner0 = "5dBm set!        ";
		hw2000b_set_power_5();

	}else if(cfg == POWER_0DBM_MODE){
		banner0 = "0dBm set!        ";
		hw2000b_set_power_0();

	}else if(cfg == POWER_N10DBM_MODE) {
		banner0 = "-10dBm set!      ";
		hw2000b_set_power_negative_10();

	} else if(cfg == POWER_N20DBM_MODE){
		banner0 = "-20dBm set!      ";
		hw2000b_set_power_negative_20();

	} else if(cfg == FREQ_2403_MODE) {
		banner0 = "2.403GHz set!     ";
		hw2000b_set_frequence_2403();

	}else if(cfg == FREQ_2420_MODE){
		banner0 = "2.420GHz set!     ";
		hw2000b_set_frequence_2420();

	} else if(cfg == FREQ_2450_MODE){
		banner0 = "2.450GHz set!     ";
		hw2000b_set_frequence_2450();

	} else if(cfg == FREQ_2460_MODE){
		banner0 = "2.460GHz set!     ";
		hw2000b_set_frequence_2460();

	}else if(cfg == FREQ_2483_MODE){
		banner0 = "2.483GHz set!     ";
		hw2000b_set_frequence_2483();

	}
	
	lcd_print(0, banner0, 0);
}

