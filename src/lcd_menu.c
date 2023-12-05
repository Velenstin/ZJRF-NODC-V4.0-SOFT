/**************************************************************************
* 版权声明：Copyright@2020 上海东软载波微电子有限公司
* 文件名称：lcd_menu.c
* 功能描述：LCD界面函数
* 函数列表：lcd_menu_logo
			lcd_print_menu
			lcd_menu_init
* 文件作者：lihb
* 文件版本：1.0 
* 完成日期：2022-08-10	
* 修订历史：
* 修订日期：
**************************************************************************/
#include "lcd.h"
#include "type.h"
#include <string.h>


#define pic_rad     0xFD75

extern   uint8_t    _rf_select;
extern const uint8_t logo_160_78[1560];

menu_t *_curmenu;
menu_t	*_menu_empty;
menu_t _menu[MENU_ID_MAX];


/**************************************************************************
* 函数名称：picture_print_point
* 功能描述：显示双色图的一个点
* 输入参数：x 图片的行偏移量
			y 图片的列偏移量
			picture 图片
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void picture_print_point(uint16_t x, uint16_t y, const uint8_t *picture)
{
	if ((1 << ((y * 160 + x) % 8)) == (picture[(y * 160 + x) / 8] & (1 << ((y * 160 + x) % 8)))) {
        LCD_DrawPoint(x, y + 1 + 27, WHITE);
    } else {
        LCD_DrawPoint(x, y + 1 + 27, RED);
    }
}

/**************************************************************************
* 函数名称：lcd_menu_logo
* 功能描述：显示logo
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void lcd_menu_logo(void)
{
    uint16_t i, j;

    for (i = 0; i < 40; i++) {
        for (j = 0; j < 78; j++) {
			picture_print_point(i, j, logo_160_78);
			picture_print_point(i + 40, j, logo_160_78);
			picture_print_point(i + 80, j, logo_160_78);
			picture_print_point(i + 120, j, logo_160_78);
        }
    }
}


/**************************************************************************
* 函数名称：lcd_print_menu
* 功能描述：显示一页界面
* 输入参数：menu
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void lcd_print_menu(menu_t *menu) 
{
	lcd_print(0, _curmenu->banner0, 0);
    lcd_print(1, _curmenu->banner1, (_curmenu->scroll == 1));
    lcd_print(2, _curmenu->banner2, (_curmenu->scroll == 2));
    lcd_print(3, _curmenu->banner3, (_curmenu->scroll == 3));
    lcd_print(4, _curmenu->banner4, (_curmenu->scroll == 4));
    lcd_print(5, _curmenu->banner5, (_curmenu->scroll == 5));
    lcd_print(6, _curmenu->banner6, 0);
}

/**************************************************************************
* 函数名称：lcd_menu_init
* 功能描述：界面初始化
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void lcd_menu_init(void)
{
	memset(_menu, 0, sizeof(_menu));

	_menu[ES7W8020_TEST_ID].banner0 = "ES7W8020 SDK     ";
	_menu[ES7W8020_TEST_ID].banner1 = "1.Tx Test        ";
	_menu[ES7W8020_TEST_ID].banner2 = "2.Rx Test        ";
	_menu[ES7W8020_TEST_ID].banner3 = "3.Extended Func  ";
	_menu[ES7W8020_TEST_ID].banner4 = "4.Configure      ";
	_menu[ES7W8020_TEST_ID].banner5 = "                 ";
	_menu[ES7W8020_TEST_ID].banner6 = "Back   Ok  Scroll";
	_menu[ES7W8020_TEST_ID].m1  = &_menu[TX_TEST_ID];
	_menu[ES7W8020_TEST_ID].m2  = &_menu[RX_TEST_ID];
	_menu[ES7W8020_TEST_ID].m3  = &_menu[EXT_FUNC_ID];
	_menu[ES7W8020_TEST_ID].m4  = &_menu[CONFIGURE_ID];
	_menu[ES7W8020_TEST_ID].m5  = 0;
	_menu[ES7W8020_TEST_ID].back = &_menu[ES7W8020_TEST_ID];
	_menu[ES7W8020_TEST_ID].id = ES7W8020_TEST_ID;
	_menu[ES7W8020_TEST_ID].scroll = 1;
	_menu[ES7W8020_TEST_ID].size = 4;

	_menu[TX_TEST_ID].banner0 = "Tx Test          ";
	_menu[TX_TEST_ID].banner1 = "1.RF Power       ";
	_menu[TX_TEST_ID].banner2 = "2.FrameSend      ";
	_menu[TX_TEST_ID].banner3 = "                 ";
	_menu[TX_TEST_ID].banner4 = "                 ";
	_menu[TX_TEST_ID].banner5 = "                 ";
	_menu[TX_TEST_ID].banner6 = "Back   Ok  Scroll";
	_menu[TX_TEST_ID].m1  = _menu_empty;
	_menu[TX_TEST_ID].m2  = &_menu[FRAME_SEND_ID];
	_menu[TX_TEST_ID].m3  = 0;
	_menu[TX_TEST_ID].m4  = 0;
	_menu[TX_TEST_ID].m5  = 0;
	_menu[TX_TEST_ID].back = &_menu[ES7W8020_TEST_ID];
	_menu[TX_TEST_ID].id = TX_TEST_ID;
	_menu[TX_TEST_ID].scroll = 2;
	_menu[TX_TEST_ID].size = 2;


	_menu[FRAME_SEND_ID].banner0 = "Frame Send       ";
	_menu[FRAME_SEND_ID].banner1 = "1.1000(NACK)     ";
	_menu[FRAME_SEND_ID].banner2 = "2.1000(ACK)      ";
	_menu[FRAME_SEND_ID].banner3 = "3.Infinite       ";
	_menu[FRAME_SEND_ID].banner4 = "                 ";
	_menu[FRAME_SEND_ID].banner5 = "                 ";
	_menu[FRAME_SEND_ID].banner6 = "Back   Ok  Scroll";
	_menu[FRAME_SEND_ID].m1  = _menu_empty;
	_menu[FRAME_SEND_ID].m2  = _menu_empty;
	_menu[FRAME_SEND_ID].m3  = _menu_empty;
	_menu[FRAME_SEND_ID].m4  = 0;
	_menu[FRAME_SEND_ID].m5  = 0;
	_menu[FRAME_SEND_ID].back = &_menu[TX_TEST_ID];
	_menu[FRAME_SEND_ID].id = FRAME_SEND_ID;
	_menu[FRAME_SEND_ID].scroll = 1;
	_menu[FRAME_SEND_ID].size = 3;

	_menu[RX_TEST_ID].banner0 = "Rx Test          ";
	_menu[RX_TEST_ID].banner1 = "1.PER(NO ACK)    ";
	_menu[RX_TEST_ID].banner2 = "2.PER(ACK)       ";
	_menu[RX_TEST_ID].banner3 = "                 ";
	_menu[RX_TEST_ID].banner4 = "                 ";
	_menu[RX_TEST_ID].banner5 = "                 ";
	_menu[RX_TEST_ID].banner6 = "Back   Ok  Scroll";
	_menu[RX_TEST_ID].m1  = _menu_empty;
	_menu[RX_TEST_ID].m2  = _menu_empty;
	_menu[RX_TEST_ID].m3  = 0;
	_menu[RX_TEST_ID].m4  = 0;
	_menu[RX_TEST_ID].m5  = 0;
	_menu[RX_TEST_ID].back = &_menu[ES7W8020_TEST_ID];
	_menu[RX_TEST_ID].id = RX_TEST_ID;
	_menu[RX_TEST_ID].scroll = 1;
	_menu[RX_TEST_ID].size = 2;

	_menu[EXT_FUNC_ID].banner0 = "Extended Func    ";
	_menu[EXT_FUNC_ID].banner1 = "1.Temp Monitor   ";
	_menu[EXT_FUNC_ID].banner2 = "                 ";
	_menu[EXT_FUNC_ID].banner3 = "                 ";
	_menu[EXT_FUNC_ID].banner4 = "                 ";
	_menu[EXT_FUNC_ID].banner5 = "                 ";
	_menu[EXT_FUNC_ID].banner6 = "Back   Ok  Scroll";
	_menu[EXT_FUNC_ID].m1  = &_menu[TEMP_MONITOR_ID];
	_menu[EXT_FUNC_ID].m2  = 0;
	_menu[EXT_FUNC_ID].m3  = 0;
	_menu[EXT_FUNC_ID].m4  = 0;
	_menu[EXT_FUNC_ID].m5  = 0;
	_menu[EXT_FUNC_ID].back = &_menu[ES7W8020_TEST_ID];
	_menu[EXT_FUNC_ID].id = EXT_FUNC_ID;
	_menu[EXT_FUNC_ID].scroll = 1;
	_menu[EXT_FUNC_ID].size = 1;

	_menu[TEMP_MONITOR_ID].banner0 = "Temp Monitor     ";
	_menu[TEMP_MONITOR_ID].banner1 = "1.Central        ";
	_menu[TEMP_MONITOR_ID].banner2 = "2.Peripheral     ";
	_menu[TEMP_MONITOR_ID].banner3 = "                 ";
	_menu[TEMP_MONITOR_ID].banner4 = "                 ";
	_menu[TEMP_MONITOR_ID].banner5 = "                 ";
	_menu[TEMP_MONITOR_ID].banner6 = "Back   Ok  Scroll";
	_menu[TEMP_MONITOR_ID].m1  = _menu_empty;
	_menu[TEMP_MONITOR_ID].m2  = &_menu[MONITOR_PERIPH_SEL_ID];
	_menu[TEMP_MONITOR_ID].m3  = 0;
	_menu[TEMP_MONITOR_ID].m4  = 0;
	_menu[TEMP_MONITOR_ID].m5  = 0;
	_menu[TEMP_MONITOR_ID].back = &_menu[EXT_FUNC_ID];
	_menu[TEMP_MONITOR_ID].id = TEMP_MONITOR_ID;
	_menu[TEMP_MONITOR_ID].scroll = 1;
	_menu[TEMP_MONITOR_ID].size = 2;

	_menu[MONITOR_PERIPH_SEL_ID].banner0 = "Peripheral       ";
	_menu[MONITOR_PERIPH_SEL_ID].banner1 = "1.PIPE0          ";
	_menu[MONITOR_PERIPH_SEL_ID].banner2 = "2.PIPE1          ";
	_menu[MONITOR_PERIPH_SEL_ID].banner3 = "3.PIPE2          ";
	_menu[MONITOR_PERIPH_SEL_ID].banner4 = "4.PIPE3          ";
	_menu[MONITOR_PERIPH_SEL_ID].banner5 = "                 ";
	_menu[MONITOR_PERIPH_SEL_ID].banner6 = "Back   Ok  Scroll";
	_menu[MONITOR_PERIPH_SEL_ID].m1  = _menu_empty;
	_menu[MONITOR_PERIPH_SEL_ID].m2  = _menu_empty;
	_menu[MONITOR_PERIPH_SEL_ID].m3  = _menu_empty;
	_menu[MONITOR_PERIPH_SEL_ID].m4  = _menu_empty;
	_menu[MONITOR_PERIPH_SEL_ID].m5  = 0;
	_menu[MONITOR_PERIPH_SEL_ID].back = &_menu[TEMP_MONITOR_ID];
	_menu[MONITOR_PERIPH_SEL_ID].id = MONITOR_PERIPH_SEL_ID;
	_menu[MONITOR_PERIPH_SEL_ID].scroll = 1;
	_menu[MONITOR_PERIPH_SEL_ID].size = 4;

	_menu[CONFIGURE_ID].banner0 = "Configure        ";
	_menu[CONFIGURE_ID].banner1 = "1.Data Rate      ";
	_menu[CONFIGURE_ID].banner2 = "2.TX Power       ";
	_menu[CONFIGURE_ID].banner3 = "3.Frequency      ";
	_menu[CONFIGURE_ID].banner4 = "                 ";
	_menu[CONFIGURE_ID].banner5 = "                 ";
	_menu[CONFIGURE_ID].banner6 = "Back   Ok  Scroll";
	_menu[CONFIGURE_ID].m1  = &_menu[CONFIG_SPEED_ID];
	_menu[CONFIGURE_ID].m2  = &_menu[CONFIG_POWER_ID];
	_menu[CONFIGURE_ID].m3  = &_menu[CONFIG_FREQ_ID];
	_menu[CONFIGURE_ID].m4  = 0;
	_menu[CONFIGURE_ID].m5  = 0;
	_menu[CONFIGURE_ID].back = &_menu[ES7W8020_TEST_ID];
	_menu[CONFIGURE_ID].id = CONFIGURE_ID;
	_menu[CONFIGURE_ID].scroll = 1;
	_menu[CONFIGURE_ID].size = 3;

	_menu[CONFIG_SPEED_ID].banner0 = "Data Rate        ";
	_menu[CONFIG_SPEED_ID].banner1 = "1.1Mbps          ";
	_menu[CONFIG_SPEED_ID].banner2 = "2.250Kbps        ";
	_menu[CONFIG_SPEED_ID].banner3 = "                 ";
	_menu[CONFIG_SPEED_ID].banner4 = "                 ";
	_menu[CONFIG_SPEED_ID].banner5 = "                 ";
	_menu[CONFIG_SPEED_ID].banner6 = "Back   Ok  Scroll";
	_menu[CONFIG_SPEED_ID].m1  = _menu_empty;
	_menu[CONFIG_SPEED_ID].m2  = _menu_empty;
	_menu[CONFIG_SPEED_ID].m3  = 0;
	_menu[CONFIG_SPEED_ID].m4  = 0;
	_menu[CONFIG_SPEED_ID].m5  = 0;
	_menu[CONFIG_SPEED_ID].back = &_menu[CONFIGURE_ID];
	_menu[CONFIG_SPEED_ID].id = CONFIG_SPEED_ID;
	_menu[CONFIG_SPEED_ID].scroll = 1;
	_menu[CONFIG_SPEED_ID].size = 2;

	_menu[CONFIG_POWER_ID].banner0 = "Power            ";
	_menu[CONFIG_POWER_ID].banner1 = "1.8dBm           ";
	_menu[CONFIG_POWER_ID].banner2 = "2.5dBm           ";
	_menu[CONFIG_POWER_ID].banner3 = "3.0dBm           ";
	_menu[CONFIG_POWER_ID].banner4 = "4.-10dBm         ";
	_menu[CONFIG_POWER_ID].banner5 = "5.-20dBm         ";
	_menu[CONFIG_POWER_ID].banner6 = "Back   Ok  Scroll";
	_menu[CONFIG_POWER_ID].m1  = _menu_empty;
	_menu[CONFIG_POWER_ID].m2  = _menu_empty;
	_menu[CONFIG_POWER_ID].m3  = _menu_empty;
	_menu[CONFIG_POWER_ID].m4  = _menu_empty;
	_menu[CONFIG_POWER_ID].m5  = _menu_empty;
	_menu[CONFIG_POWER_ID].back = &_menu[CONFIGURE_ID];
	_menu[CONFIG_POWER_ID].id = CONFIG_POWER_ID;
	_menu[CONFIG_POWER_ID].scroll = 1;
	_menu[CONFIG_POWER_ID].size = 5;

	_menu[CONFIG_FREQ_ID].banner0 = "Frequency        ";
	_menu[CONFIG_FREQ_ID].banner1 = "1.2.403GHz       ";
	_menu[CONFIG_FREQ_ID].banner2 = "2.2.420GHz       ";
	_menu[CONFIG_FREQ_ID].banner3 = "3.2.450GHz       ";
	_menu[CONFIG_FREQ_ID].banner4 = "4.2.460GHz       ";
	_menu[CONFIG_FREQ_ID].banner5 = "5.2.483GHz       ";
	_menu[CONFIG_FREQ_ID].banner6 = "Back   Ok  Scroll";
	_menu[CONFIG_FREQ_ID].m1  = _menu_empty;
	_menu[CONFIG_FREQ_ID].m2  = _menu_empty;
	_menu[CONFIG_FREQ_ID].m3  = _menu_empty;
	_menu[CONFIG_FREQ_ID].m4  = _menu_empty;
	_menu[CONFIG_FREQ_ID].m5  = _menu_empty;
	_menu[CONFIG_FREQ_ID].back = &_menu[CONFIGURE_ID];
	_menu[CONFIG_FREQ_ID].id = CONFIG_FREQ_ID;
	_menu[CONFIG_FREQ_ID].scroll = 3;
	_menu[CONFIG_FREQ_ID].size = 5;

	_curmenu = &_menu[0];

	lcd_print_menu(_curmenu);
}


