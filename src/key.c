/**************************************************************************
* 版权声明：Copyright@2020 上海东软载波微电子有限公司
* 文件名称：key.c
* 功能描述：按键处理函数
* 函数列表：back_key_task
			ok_key_task
			scroll_key_task
* 文件作者：lihb
* 文件版本：1.0 
* 完成日期：2022-08-10	
* 修订历史：
* 修订日期：
**************************************************************************/
#include <hic.h>
#include "string.h"
#include "type.h"
#include "lcd.h"
#include "radio.h"
#include "hw2000b.h"
#include "timer.h"


extern	menu_t	*_curmenu;
extern	menu_t	*_menu_empty;
extern	menu_t	_menu[MENU_ID_MAX];

extern	sbit	_menu_empty_flag;

extern	sbit	_back_key_request;
extern	sbit	_ok_key_request;
extern	sbit	_scroll_key_request;

/**************************************************************************
* 函数名称：back_key_task
* 功能描述：back按键处理
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void back_key_task(void)
{
	_back_key_request = 0;	
	if(_menu_empty_flag == 1) {
		_menu_empty_flag = 0;
		lcd_print_menu(_curmenu);
	} else {
		_curmenu = _curmenu->back;
		
		lcd_print_menu(_curmenu);
	}
}

/**************************************************************************
* 函数名称：ok_key_task
* 功能描述：ok按键处理
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void ok_key_task(void)
{
	_ok_key_request = 0;

	if(!_menu_empty_flag) {
		switch(_curmenu->scroll) {
			case 1:
				if(_curmenu->m1 == _menu_empty) {
					_menu_empty_flag = 1;
					LCD_Clear(BLACK);
				} else if (_curmenu->m1 != 0){
					_menu_empty_flag = 0;
					_curmenu = _curmenu->m1;
					lcd_print_menu(_curmenu);
				}
			

				if(_menu_empty_flag == 1) {
					switch(_curmenu->id) {
						case TX_TEST_ID:		//RF Power Test
							hw2000b_rf_power_test();
							break;

						case FRAME_SEND_ID:		//1000 NACK
							hw2000b_tx_nack(FRAME_NACK_1000);
							break;

						case RX_TEST_ID:		//PER Test
							hw2000b_rx_test(PER_TEST_MODE);
							break;

						case TEMP_MONITOR_ID:
							hw2000b_temp_monitor_central();
							break;

						case MONITOR_PERIPH_SEL_ID:
							hw2000b_temp_monitor_periph(0);
							break;

						case CONFIG_SPEED_ID:	//1Mbps
							hw2000b_set_config(SPEED_1MBPS_MODE);
							break;

						case CONFIG_POWER_ID:	//max power
							hw2000b_set_config(POWER_MAX_MODE);
							break;

						case CONFIG_FREQ_ID:	//2403mHz
							hw2000b_set_config(FREQ_2403_MODE);
							break;

						default:
							break;
					}
				}
				break;

			case 2:
				if(_curmenu->m2 == _menu_empty) {
					_menu_empty_flag = 1;
					LCD_Clear(BLACK);
				} else if (_curmenu->m2 != 0) {
					_menu_empty_flag = 0;
					_curmenu = _curmenu->m2;
					lcd_print_menu(_curmenu);
				}
			

				if(_menu_empty_flag == 1) {
					switch(_curmenu->id) {
						case FRAME_SEND_ID :		//tx 1000 ack
							hw2000b_tx_ack_1000();
							break;

						case RX_TEST_ID :			//ack test
							hw2000b_rx_test(ACK_TEST_MODE);
							break;

						case MONITOR_PERIPH_SEL_ID:
							hw2000b_temp_monitor_periph(1);
							break;

						case CONFIG_SPEED_ID:		//250kbps
							hw2000b_set_config(SPEED_250KBPS_MODE);
							break;

						case CONFIG_POWER_ID:	//5dBm
							hw2000b_set_config(POWER_5DBM_MODE);
							break;

						case CONFIG_FREQ_ID:	//2420mHz
							hw2000b_set_config(FREQ_2420_MODE);
							break;

						default:
							break;
					}
				}
				break;
			case 3:
				if(_curmenu->m3 == _menu_empty) {
					_menu_empty_flag = 1;
					LCD_Clear(BLACK);
				} else if (_curmenu->m3 != 0){
					_menu_empty_flag = 0;
					_curmenu = _curmenu->m3;
					lcd_print_menu(_curmenu);
				}
			

				if(_menu_empty_flag == 1) {
					switch(_curmenu->id) {
						case FRAME_SEND_ID :			//infinite
							hw2000b_tx_nack(FRAME_INFINITE);
							break;

						case MONITOR_PERIPH_SEL_ID:
							hw2000b_temp_monitor_periph(2);
							break;

						case CONFIG_POWER_ID:	//0dBm
							hw2000b_set_config(POWER_0DBM_MODE);
							break;

						case CONFIG_FREQ_ID:	//2450mHz
							hw2000b_set_config(FREQ_2450_MODE);
							break;

						default:
							break;
					}
				}
				break;

				case 4:
					if(_curmenu->m4 == _menu_empty) {
					_menu_empty_flag = 1;
					LCD_Clear(BLACK);
					} else if (_curmenu->m4 != 0){
						_menu_empty_flag = 0;
						_curmenu = _curmenu->m4;
						lcd_print_menu(_curmenu);
					}

					if(_menu_empty_flag == 1) {
						switch(_curmenu->id) {
							//case ES7W8020_TEST_ID:	
								//lcd_show_temperature();
								//break;

							case MONITOR_PERIPH_SEL_ID:
								hw2000b_temp_monitor_periph(3);
								break;

							case CONFIG_POWER_ID:	//5dBm
								hw2000b_set_config(POWER_N10DBM_MODE);
								break;

							case CONFIG_FREQ_ID:	//2460mHz
								hw2000b_set_config(FREQ_2460_MODE);
								break;

							default:
								break;
						}
					}
					break;

				case 5:
					if(_curmenu->m5 == _menu_empty) {
					_menu_empty_flag = 1;
					LCD_Clear(BLACK);
					} else if (_curmenu->m5 != 0){
						_menu_empty_flag = 0;
						_curmenu = _curmenu->m5;
						lcd_print_menu(_curmenu);
					}

					if(_menu_empty_flag == 1) {
						switch(_curmenu->id) {
							case CONFIG_POWER_ID:	//5dBm
								hw2000b_set_config(POWER_N20DBM_MODE);
								break;

							case CONFIG_FREQ_ID:	//2483mHz
								hw2000b_set_config(FREQ_2483_MODE);
								break;

							default:
								break;
						}
					}
					break;

			default:
				break;
		}
	}
}

/**************************************************************************
* 函数名称：scroll_key_task
* 功能描述：scroll按键处理
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void scroll_key_task(void)
{
	_scroll_key_request = 0;
	
	if(!_menu_empty_flag) {
		_curmenu->scroll++;
		if (_curmenu->scroll > _curmenu->size) {
			_curmenu->scroll = 1;
		}
		lcd_print_menu(_curmenu);
	}
}

