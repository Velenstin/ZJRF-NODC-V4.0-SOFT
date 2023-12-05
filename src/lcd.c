/**************************************************************************
* 版权声明：Copyright@2020 上海东软载波微电子有限公司
* 文件名称：lcd.c
* 功能描述：lcd函数
* 函数列表：lcd_write_reg
			lcd_write_data8
			lcd_write_color
			lcd_write_colors
			LCD_Address_Set
			lcd_init
			lcd_clear
			lcd_fill
			lcd_show_char
			lcd_print
* 文件作者：lihb
* 文件版本：1.0 
* 完成日期：2022-8-10
* 修订历史：
* 修订日期：
**************************************************************************/
#include <hic.h>
#include "type.h"
#include "font.h"
#include "lcd.h"
#include "timer.h"
#include "radio.h"

uint16_t _back_color;   //背景色

static void oled_pin_init(void)
{

}



/******************************************************************************
      函数说明：LCD串行数据写入函数
      入口数据：dat  要写入的串行数据
      返回值：  无
******************************************************************************/
void LCD_Writ_Bus(uint8_t dat) 
{	
	uint8_t i;
	OLED_CS_Clr();
	for(i=0;i<8;i++)
	{			  
		OLED_SCLK_Clr();
		if(dat&0x80){
		   OLED_SDIN_Set();
		}
		else{
		   OLED_SDIN_Clr();
		}
		OLED_SCLK_Set();
		dat<<=1;
	}	
    OLED_CS_Set();
}


/******************************************************************************
      函数说明：LCD写入数据
      入口数据：dat 写入的数据
      返回值：  无
******************************************************************************/
void LCD_WR_DATA8(uint8_t dat)
{
	OLED_DC_Set();//写数据
	LCD_Writ_Bus(dat);
}


/******************************************************************************
      函数说明：LCD写入数据
      入口数据：dat 写入的数据
      返回值：  无
******************************************************************************/
void LCD_WR_DATA(uint16_t dat)
{
	OLED_DC_Set();//写数据
	LCD_Writ_Bus(dat>>8);
	LCD_Writ_Bus(dat);
}


/******************************************************************************
      函数说明：LCD写入命令
      入口数据：dat 写入的命令
      返回值：  无
******************************************************************************/
void LCD_WR_REG(uint8_t dat)
{
	OLED_DC_Clr();//写命令
	LCD_Writ_Bus(dat);
}


/******************************************************************************
      函数说明：设置起始和结束地址
      入口数据：x1,x2 设置列的起始和结束地址
                y1,y2 设置行的起始和结束地址
      返回值：  无
******************************************************************************/
void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
{
	if(USE_HORIZONTAL==0)
	{
		LCD_WR_REG(0x2a);//列地址设置
		LCD_WR_DATA(x1+2);
		LCD_WR_DATA(x2+2);
		LCD_WR_REG(0x2b);//行地址设置
		LCD_WR_DATA(y1+1);
		LCD_WR_DATA(y2+1);
		LCD_WR_REG(0x2c);//储存器写
	}
	else if(USE_HORIZONTAL==1)
	{
		LCD_WR_REG(0x2a);//列地址设置
		LCD_WR_DATA(x1+2);
		LCD_WR_DATA(x2+2);
		LCD_WR_REG(0x2b);//行地址设置
		LCD_WR_DATA(y1+1);
		LCD_WR_DATA(y2+1);
		LCD_WR_REG(0x2c);//储存器写
	}
	else if(USE_HORIZONTAL==2)
	{
		LCD_WR_REG(0x2a);//列地址设置
		LCD_WR_DATA(x1+1);
		LCD_WR_DATA(x2+1);
		LCD_WR_REG(0x2b);//行地址设置
		LCD_WR_DATA(y1+2);
		LCD_WR_DATA(y2+2);
		LCD_WR_REG(0x2c);//储存器写
	}
	else
	{
		LCD_WR_REG(0x2a);//列地址设置
		LCD_WR_DATA(x1+1);
		LCD_WR_DATA(x2+1);
		LCD_WR_REG(0x2b);//行地址设置
		LCD_WR_DATA(y1+2);
		LCD_WR_DATA(y2+2);
		LCD_WR_REG(0x2c);//储存器写
	}
}


/******************************************************************************
      函数说明：LCD初始化函数
      入口数据：无
      返回值：  无
******************************************************************************/
void Lcd_Init(void)
{
    oled_pin_init();
    
	OLED_RST_Clr();
	delay_ms(200);
	OLED_RST_Set();
	delay_ms(200);
	OLED_BLK_Clr();
	
//************* Start Initial Sequence **********//
LCD_WR_REG(0x11); //Sleep out 
delay_ms(120);              //Delay 120ms 
//------------------------------------ST7735S Frame Rate-----------------------------------------// 
LCD_WR_REG(0xB1); 
LCD_WR_DATA8(0x05); 
LCD_WR_DATA8(0x3C); 
LCD_WR_DATA8(0x3C); 
LCD_WR_REG(0xB2); 
LCD_WR_DATA8(0x05);
LCD_WR_DATA8(0x3C); 
LCD_WR_DATA8(0x3C); 
LCD_WR_REG(0xB3); 
LCD_WR_DATA8(0x05); 
LCD_WR_DATA8(0x3C); 
LCD_WR_DATA8(0x3C); 
LCD_WR_DATA8(0x05); 
LCD_WR_DATA8(0x3C); 
LCD_WR_DATA8(0x3C); 
//------------------------------------End ST7735S Frame Rate---------------------------------// 
LCD_WR_REG(0xB4); //Dot inversion 
LCD_WR_DATA8(0x03); 
//------------------------------------ST7735S Power Sequence---------------------------------// 
LCD_WR_REG(0xC0); 
LCD_WR_DATA8(0x28); 
LCD_WR_DATA8(0x08); 
LCD_WR_DATA8(0x04); 
LCD_WR_REG(0xC1); 
LCD_WR_DATA8(0XC0); 
LCD_WR_REG(0xC2); 
LCD_WR_DATA8(0x0D); 
LCD_WR_DATA8(0x00); 
LCD_WR_REG(0xC3); 
LCD_WR_DATA8(0x8D); 
LCD_WR_DATA8(0x2A); 
LCD_WR_REG(0xC4); 
LCD_WR_DATA8(0x8D); 
LCD_WR_DATA8(0xEE); 
//---------------------------------End ST7735S Power Sequence-------------------------------------// 
LCD_WR_REG(0xC5); //VCOM 
LCD_WR_DATA8(0x1A); 
LCD_WR_REG(0x36); //MX, MY, RGB mode 
if(USE_HORIZONTAL==0)LCD_WR_DATA8(0x00);
else if(USE_HORIZONTAL==1)LCD_WR_DATA8(0xC0);
else if(USE_HORIZONTAL==2)LCD_WR_DATA8(0x70);
else LCD_WR_DATA8(0xA0);
//------------------------------------ST7735S Gamma Sequence---------------------------------// 
LCD_WR_REG(0xE0); 
LCD_WR_DATA8(0x04); 
LCD_WR_DATA8(0x22); 
LCD_WR_DATA8(0x07); 
LCD_WR_DATA8(0x0A); 
LCD_WR_DATA8(0x2E); 
LCD_WR_DATA8(0x30); 
LCD_WR_DATA8(0x25); 
LCD_WR_DATA8(0x2A); 
LCD_WR_DATA8(0x28); 
LCD_WR_DATA8(0x26); 
LCD_WR_DATA8(0x2E); 
LCD_WR_DATA8(0x3A); 
LCD_WR_DATA8(0x00); 
LCD_WR_DATA8(0x01); 
LCD_WR_DATA8(0x03); 
LCD_WR_DATA8(0x13); 
LCD_WR_REG(0xE1); 
LCD_WR_DATA8(0x04); 
LCD_WR_DATA8(0x16); 
LCD_WR_DATA8(0x06); 
LCD_WR_DATA8(0x0D); 
LCD_WR_DATA8(0x2D); 
LCD_WR_DATA8(0x26); 
LCD_WR_DATA8(0x23); 
LCD_WR_DATA8(0x27); 
LCD_WR_DATA8(0x27); 
LCD_WR_DATA8(0x25); 
LCD_WR_DATA8(0x2D); 
LCD_WR_DATA8(0x3B); 
LCD_WR_DATA8(0x00); 
LCD_WR_DATA8(0x01); 
LCD_WR_DATA8(0x04); 
LCD_WR_DATA8(0x13); 
//------------------------------------End ST7735S Gamma Sequence-----------------------------// 
LCD_WR_REG(0x3A); //65k mode 
LCD_WR_DATA8(0x05); 
LCD_WR_REG(0x29); //Display on 
} 


/******************************************************************************
      函数说明：LCD清屏函数
      入口数据：无
      返回值：  无
******************************************************************************/
void LCD_Clear(uint16_t Color)
{
	uint16_t i,j;  	
	LCD_Address_Set(0,0,LCD_W-1,LCD_H-1);
    for(i=0;i<LCD_W;i++)
	  {
			for (j=0;j<LCD_H;j++)
				{
					LCD_WR_DATA(Color);
				}
	  }
}


/******************************************************************************
      函数说明：LCD显示汉字
      入口数据：x,y   起始坐标
                index 汉字的序号
                size  字号
      返回值：  无
******************************************************************************/
void LCD_ShowChinese(uint16_t x,uint16_t y,uint8_t index,uint8_t size,uint16_t color)	
{  
	/* uint8_t i,j;
	uint8_t *temp,size1;
	if(size==16){temp=Hzk16;}//选择字号
	if(size==32){temp=Hzk32;}
	LCD_Address_Set(x,y,x+size-1,y+size-1); //设置一个汉字的区域
	size1=size*size/8;//一个汉字所占的字节
	temp+=index*size1;//写入的起始位置
	for(j=0;j<size1;j++)
	{
		for(i=0;i<8;i++)
		{
			if((*temp&(1<<i))!=0)//从数据的低位开始读
			{
				LCD_WR_DATA(color);//点亮
			}
			else
			{
				LCD_WR_DATA(_back_color);//不点亮
			}
		}
		temp++;
	} */
}
void LCD_ShowChines1818(uint16_t x,uint16_t y,uint8_t index, uint16_t color)
{
	uint8_t temp;
    uint8_t pos,t;
    uint16_t pixel_idx;
    
    pixel_idx = 0;
    
    LCD_Address_Set(x, y, x+18-1, y+18-1); 
    for(pos = 0; pos < 54; pos++) {
        temp = _chinese_1818[index][pos];
        for(t = 0; t < 8; t++) {
            if((pos % 3 == 2) && (t > 1)) {
                break;
            }
            if(temp & 0x01) {
                LCD_WR_DATA(color);
            } else {
                LCD_WR_DATA(_back_color);
            } 
            temp >>= 1; 
            pixel_idx ++;
        }
    }
    
/*     lcd_writ_multi_color(pixel_buf, pixel_idx);  */
}
/******************************************************************************
      函数说明：LCD显示汉字
      入口数据：x,y   起始坐标
      返回值：  无
******************************************************************************/
void LCD_DrawPoint(uint16_t x,uint16_t y,uint16_t color)
{
	LCD_Address_Set(x,y,x,y);//设置光标位置 
	LCD_WR_DATA(color);
} 


/******************************************************************************
      函数说明：LCD画一个大的点
      入口数据：x,y   起始坐标
      返回值：  无
******************************************************************************/
void LCD_DrawPoint_big(uint16_t x,uint16_t y,uint16_t color)
{
	LCD_Fill(x-1,y-1,x+1,y+1,color);
} 


/******************************************************************************
      函数说明：在指定区域填充颜色
      入口数据：xsta,ysta   起始坐标
                xend,yend   终止坐标
      返回值：  无
******************************************************************************/
void LCD_Fill(uint16_t xsta,uint16_t ysta,uint16_t xend,uint16_t yend,uint16_t color)
{          
	uint16_t i,j; 
	LCD_Address_Set(xsta,ysta,xend,yend);      //设置光标位置 
	for(i=ysta;i<=yend;i++)
	{													   	 	
		for(j=xsta;j<=xend;j++)LCD_WR_DATA(color);//设置光标位置 	    
	} 					  	    
}


/******************************************************************************
      函数说明：画线
      入口数据：x1,y1   起始坐标
                x2,y2   终止坐标
      返回值：  无
******************************************************************************/
void LCD_DrawLine(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color)
{
	uint16_t t; 
	int xerr=0,yerr=0,delta_x,delta_y,distance;
	int incx,incy,uRow,uCol;
	delta_x=x2-x1; //计算坐标增量 
	delta_y=y2-y1;
	uRow=x1;//画线起点坐标
	uCol=y1;
	if(delta_x>0)incx=1; //设置单步方向 
	else if (delta_x==0)incx=0;//垂直线 
	else {incx=-1;delta_x=-delta_x;}
	if(delta_y>0)incy=1;
	else if (delta_y==0)incy=0;//水平线 
	else {incy=-1;delta_y=-delta_x;}
	if(delta_x>delta_y)distance=delta_x; //选取基本增量坐标轴 
	else distance=delta_y;
	for(t=0;t<distance+1;t++)
	{
		LCD_DrawPoint(uRow,uCol,color);//画点
		xerr+=delta_x;
		yerr+=delta_y;
		if(xerr>distance)
		{
			xerr-=distance;
			uRow+=incx;
		}
		if(yerr>distance)
		{
			yerr-=distance;
			uCol+=incy;
		}
	}
}


/******************************************************************************
      函数说明：画矩形
      入口数据：x1,y1   起始坐标
                x2,y2   终止坐标
      返回值：  无
******************************************************************************/
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,uint16_t color)
{
	LCD_DrawLine(x1,y1,x2,y1,color);
	LCD_DrawLine(x1,y1,x1,y2,color);
	LCD_DrawLine(x1,y2,x2,y2,color);
	LCD_DrawLine(x2,y1,x2,y2,color);
}


/******************************************************************************
      函数说明：画圆
      入口数据：x0,y0   圆心坐标
                r       半径
      返回值：  无
******************************************************************************/
void Draw_Circle(uint16_t x0,uint16_t y0,uint8_t r,uint16_t color)
{
	int a,b;
	a=0;b=r;	  
	while(a<=b)
	{
		LCD_DrawPoint(x0-b,y0-a,color);             //3           
		LCD_DrawPoint(x0+b,y0-a,color);             //0           
		LCD_DrawPoint(x0-a,y0+b,color);             //1                
		LCD_DrawPoint(x0-a,y0-b,color);             //2             
		LCD_DrawPoint(x0+b,y0+a,color);             //4               
		LCD_DrawPoint(x0+a,y0-b,color);             //5
		LCD_DrawPoint(x0+a,y0+b,color);             //6 
		LCD_DrawPoint(x0-b,y0+a,color);             //7
		a++;
		if((a*a+b*b)>(r*r))//判断要画的点是否过远
		{
			b--;
		}
	}
}


/******************************************************************************
      函数说明：显示字符
      入口数据：x,y    起点坐标
                num    要显示的字符
                mode   1叠加方式  0非叠加方式
      返回值：  无
******************************************************************************/
void LCD_ShowChar(uint16_t x,uint16_t y,uint8_t num,uint8_t mode,uint16_t color)
{
    uint8_t temp;
    uint8_t pos,t;
	  uint16_t x0=x;    
    if(x>LCD_W-16||y>LCD_H-16)return;	    //设置窗口		   
	num=num-' ';//得到偏移后的值
	LCD_Address_Set(x,y,x+8-1,y+16-1);      //设置光标位置 
	if(!mode) //非叠加方式
	{
		for(pos=0;pos<16;pos++)
		{ 
			temp=asc2_1608[(uint16_t)num*16+pos];		 //调用1608字体
			for(t=0;t<8;t++)
		    {                 
		        if(temp&0x01)LCD_WR_DATA(color);
				else LCD_WR_DATA(_back_color);
				temp>>=1;
				x++;
		    }
			x=x0;
			y++;
		}	
	}else//叠加方式
	{
		for(pos=0;pos<16;pos++)
		{
		    temp=asc2_1608[(uint16_t)num*16+pos];		 //调用1608字体
			for(t=0;t<8;t++)
		    {                 
		        if(temp&0x01)LCD_DrawPoint(x+t,y+pos,color);//画一个点     
		        temp>>=1; 
		    }
		}
	}   	   	 	  
}
void LCD_ShowChar1809(uint16_t x,uint16_t y,uint8_t num,uint8_t mode,uint16_t color)
{
	uint8_t temp;
    uint8_t pos,t;
	uint16_t x0=x;    
    if(x>LCD_W-9||y>LCD_H-18)return;	    //设置窗口		   
	num=num-' ';//得到偏移后的值
	LCD_Address_Set(x,y,x+9-1,y+18-1);      //设置光标位置 
	if(!mode) //非叠加方式
	{
		for(pos=0;pos<36;pos++)
		{ 
			temp=asc2_1809[(uint16_t)num*36+pos];		 //调用1809字体
			for(t=0;t<8;t++)
		    {
			    if((pos % 2 == 1) && (t > 0)) {
					y++;
					break;
				}    
		        if(temp&0x01)LCD_WR_DATA(color);
				else LCD_WR_DATA(_back_color);
				temp>>=1;
				x++;
		    }
			x=x0;
		}	
	}else//叠加方式
	{
		for(pos=0;pos<16;pos++)
		{
		    temp=asc2_1809[(uint16_t)num*16+pos];		 //调用1809字体
			for(t=0;t<8;t++)
		    {                 
		        if(temp&0x01)LCD_DrawPoint(x+t,y+pos,color);//画一个点     
		        temp>>=1; 
		    }
		}
	}
}


/******************************************************************************
      函数说明：显示字符串
      入口数据：x,y    起点坐标
                *p     字符串起始地址
      返回值：  无
******************************************************************************/
void LCD_ShowString(uint16_t x,uint16_t y,const uint8_t *p,uint16_t color)
{         
    while(*p!='\0')
    {       
        if(x>LCD_W-9){x=0;y+=18;}
        if(y>LCD_H-18){y=x=0;LCD_Clear(BLACK);}
        LCD_ShowChar1809(x,y,*p,0,color);
        x+=9;
        p++;
    }  
}


/******************************************************************************
      函数说明：显示数字
      入口数据：m底数，n指数
      返回值：  无
******************************************************************************/
uint32_t mypow(uint8_t m,uint8_t n)
{
	uint32_t result=1;	 
	while(n--)result*=m;    
	return result;
}


/******************************************************************************
      函数说明：显示数字
      入口数据：x,y    起点坐标
                num    要显示的数字
                len    要显示的数字个数
      返回值：  无
******************************************************************************/
void LCD_ShowNum(uint16_t x,uint16_t y,uint16_t num,uint8_t len,uint16_t color)
{         	
	uint8_t t,temp;
	uint8_t enshow=0;
	for(t=0;t<len;t++)
	{
		temp=(num/mypow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				LCD_ShowChar(x+8*t,y,' ',0,color);
				continue;
			}else enshow=1; 
		 	 
		}
	 	LCD_ShowChar(x+8*t,y,temp+48,0,color); 
	}
} 


/******************************************************************************
      函数说明：显示小数
      入口数据：x,y    起点坐标
                num    要显示的小数
                len    要显示的数字个数
      返回值：  无
******************************************************************************/
void LCD_ShowNum1(uint16_t x,uint16_t y,float num,uint8_t len,uint16_t color)
{         	
	uint8_t t,temp;
	uint16_t num1;
	num1=num*100;
	for(t=0;t<len;t++)
	{
		temp=(num1/mypow(10,len-t-1))%10;
		if(t==(len-2))
		{
			LCD_ShowChar(x+8*(len-2),y,'.',0,color);
			t++;
			len+=1;
		}
	 	LCD_ShowChar(x+8*t,y,temp+48,0,color);
	}
}

uint8_t lcd_print(uint8_t row, const char *str, uint8_t converse)
{
	uint16_t _back_color_buf;
    uint8_t i, len;
    
    len = 0;
    while (str[len] != '\0') {
        len++;
    }
    if(len > 17) {
        len = 17;
    }
    
    if(row * 18 > LCD_H-18) {
        return 0;
    }
    
    if(converse) {
        _back_color_buf = _back_color;
        _back_color = BLUE;
    }
    
    LCD_Fill(0, row*18, 3, row*18+17, _back_color);
    for(i = 0; i < len; i++) {
        if((str[i] == (char)0xA1) && (str[i+1] == (char)0xE6)) {    //℃
            LCD_ShowChines1818(i*9+4, row*18, 0, GRED);
            i++;
        } else if (str[i] > (char)128) {
            continue;
        } else {
            LCD_ShowChar1809(i*9+4, row*18, str[i], 0, GRED);
        }
        
    }
    LCD_Fill(LCD_W-3, row*18, LCD_W, row*18+17, _back_color);
    
    if(converse) {
        _back_color = _back_color_buf;
    }  
    return 1;
}

uint8_t lcd_print_string(uint8_t row, uint8_t *str, uint8_t converse)
{
	uint16_t _back_color_buf;
    uint8_t i, len;
    
    len = 0;
    while (str[len] != '\0') {
        len++;
    }
    if(len > 17) {
        len = 17;
    }
    
    if(row * 18 > LCD_H-18) {
        return 0;
    }
    
    if(converse) {
        _back_color_buf = _back_color;
        _back_color = DARKBLUE;
    }
    
    LCD_Fill(0, row*18, 3, row*18+17, _back_color);
    for(i = 0; i < len; i++) {
        if((str[i] == 0xA1) && (str[i+1] == 0xE6)) {    //℃
            LCD_ShowChines1818(i*9+4, row*18, 0, GRED);
            i++;
        } else if (str[i] > 128) {
            continue;
        } else {
            LCD_ShowChar1809(i*9+4, row*18, str[i], 0, GRED);
        }
        
    }
    LCD_Fill(LCD_W-3, row*18, LCD_W, row*18+17, _back_color);
    
    if(converse) {
        _back_color = _back_color_buf;
    }  
    return 1;
}

/**************************************************************************
* 函数名称：lcd_print_num
* 功能描述：LCD打印5位数字
* 输入参数：row 仅支持0、1、2、3
* 			idx 一行显示的偏移字符数
* 			num 显示的数字
* 返回参数：1 success   0 failed
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
uint8_t lcd_print_num(uint8_t row, uint8_t idx, uint16_t num)
{
	uint8_t banner[5];
	uint8_t i;

	if(row * 16 > LCD_H-16) {
        return 0;
    }

	banner[0] = (num / 10000) + 48;
	num %= 10000;
	banner[1] = (num / 1000) + 48;
	num %= 1000;
	banner[2] = (num / 100) + 48;
	num %= 100;
	banner[3] = (num / 10) + 48;
	num %= 10;
	banner[4] = num + 48;

	for(i = 0; i < 5; i++) {
		LCD_ShowChar1809((i+idx)*9+4, row*18, banner[i], 0, GRED);
    }

	return 1;
}
