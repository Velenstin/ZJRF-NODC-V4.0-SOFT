/**************************************************************************
* ��Ȩ������Copyright@2020 �Ϻ������ز�΢�������޹�˾
* �ļ����ƣ�lcd.h
* ����������lcd����
* �����б�lcd_init
			lcd_clear
			lcd_print
			lcd_menu_logo
			lcd_menu_init
			lcd_print_menu
* �ļ����ߣ�lihb
* �ļ��汾��1.0 
* ������ڣ�2022-08-10
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
#ifndef _LCD_H_
#define _LCD_H_

#include "type.h"

typedef enum {
    ES7W8020_TEST_ID = 0,
    TX_TEST_ID,
	FRAME_SEND_ID,
	RX_TEST_ID,
	CONFIGURE_ID,
	CONFIG_SPEED_ID,
	CONFIG_POWER_ID,
	CONFIG_FREQ_ID,
	EXT_FUNC_ID,
    TEMP_MONITOR_ID,
    MONITOR_PERIPH_SEL_ID,

    MENU_ID_MAX,
} menu_id_t;

typedef struct menu{
    const char *banner0;
    const char *banner1;
    struct menu *m1;
    const char *banner2;
    struct menu *m2;
    const char *banner3;
    struct menu *m3;
    const char *banner4;
    struct menu *m4;
    const char *banner5;
    struct menu *m5;
    const char *banner6;

    uint8_t scroll;
    uint8_t size;
    uint8_t id;
    struct menu *back;
} menu_t;

#define  LCD_BLK					PA1
#define  LCD_SDA					PB0
#define  LCD_RES					PC1
#define  LCD_SCK					PB1
#define  LCD_CS					PB2
#define  LCD_DC					PA6


#define USE_HORIZONTAL 3  //���ú�������������ʾ 0��1Ϊ���� 2��3Ϊ����

#if USE_HORIZONTAL==0||USE_HORIZONTAL==1
#define LCD_W 128
#define LCD_H 160

#else
#define LCD_W 160
#define LCD_H 128
#endif

//-----------------OLED�˿ڶ���----------------  					   
#define OLED_SCLK_Clr() LCD_SCK = 0//CLK
#define OLED_SCLK_Set() LCD_SCK = 1

#define OLED_SDIN_Clr() LCD_SDA = 0//DIN
#define OLED_SDIN_Set() LCD_SDA = 1

#define OLED_RST_Clr()  LCD_RES = 0//RES
#define OLED_RST_Set()  LCD_RES = 1

#define OLED_DC_Clr()   LCD_DC = 0//DC
#define OLED_DC_Set()   LCD_DC = 1
 		     
#define OLED_CS_Clr()   LCD_CS = 0//CS
#define OLED_CS_Set()   LCD_CS = 1

#define OLED_BLK_Clr()  LCD_BLK = 0//BLK
#define OLED_BLK_Set()  LCD_BLK = 1

#define OLED_CMD  0	//д����
#define OLED_DATA 1	//д����

extern  uint16_t _back_color;   //����ɫ

void LCD_Writ_Bus(uint8_t dat);
void LCD_WR_DATA8(uint8_t dat);
void LCD_WR_DATA(uint16_t dat);
void LCD_WR_REG(uint8_t dat);
void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);
void Lcd_Init(void);
void LCD_Clear(uint16_t Color);
void LCD_ShowChinese(uint16_t x,uint16_t y,uint8_t index,uint8_t size,uint16_t color);
void LCD_DrawPoint(uint16_t x,uint16_t y,uint16_t color);
void LCD_DrawPoint_big(uint16_t x,uint16_t y,uint16_t color);
void LCD_Fill(uint16_t xsta,uint16_t ysta,uint16_t xend,uint16_t yend,uint16_t color);
void LCD_DrawLine(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color);
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,uint16_t color);
void Draw_Circle(uint16_t x0,uint16_t y0,uint8_t r,uint16_t color);
void LCD_ShowChar(uint16_t x,uint16_t y,uint8_t num,uint8_t mode,uint16_t color);
void LCD_ShowString(uint16_t x,uint16_t y,const uint8_t *p,uint16_t color);
uint32_t mypow(uint8_t m,uint8_t n);
void LCD_ShowNum(uint16_t x,uint16_t y,uint16_t num,uint8_t len,uint16_t color);
void LCD_ShowNum1(uint16_t x,uint16_t y,float num,uint8_t len,uint16_t color);

uint8_t lcd_print(uint8_t row, const char *str, uint8_t converse);//��ӡ����ָ��ָ����ַ���
uint8_t lcd_print_string(uint8_t row, uint8_t *str, uint8_t converse);//��ӡ�ɱ��ַ�������
uint8_t lcd_print_num(uint8_t row, uint8_t idx, uint16_t num);
void LCD_ShowChar1809(uint16_t x,uint16_t y,uint8_t num,uint8_t mode,uint16_t color);
void LCD_ShowChines1818(uint16_t x,uint16_t y,uint8_t index, uint16_t color);

void lcd_menu_logo(void);

void lcd_menu_init(void);

void lcd_print_menu(menu_t *curmenu);

void lcd_hw3000_menu_init(void);

void lcd_hw2000b_menu_init(void);

void lcd_show_temperature(void);


//������ɫ
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE           	 0x001F  
#define BRED             0XF81F
#define GRED 			       0XFFE0
#define GBLUE			       0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			     0XBC40 //��ɫ
#define BRRED 			     0XFC07 //�غ�ɫ
#define GRAY  			     0X8430 //��ɫ
//GUI��ɫ

#define DARKBLUE      	 0X01CF	//����ɫ
#define LIGHTBLUE      	 0X7D7C	//ǳ��ɫ  
#define GRAYBLUE       	 0X5458 //����ɫ
//������ɫΪPANEL����ɫ 
 
#define LIGHTGREEN     	 0X841F //ǳ��ɫ
#define LGRAY 			     0XC618 //ǳ��ɫ(PANNEL),���屳��ɫ

#define LGRAYBLUE        0XA651 //ǳ����ɫ(�м����ɫ)
#define LBBLUE           0X2B12 //ǳ����ɫ(ѡ����Ŀ�ķ�ɫ)

#endif
