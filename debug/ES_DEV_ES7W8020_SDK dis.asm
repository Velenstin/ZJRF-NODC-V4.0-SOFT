;The Num of Instruction(Size):1148. The Max Address(Begin with 0):14356 

                MCU  ES7P0693

A    equ    0
R    equ    1
HRAM_0X0  equ  0X0
HRAM_0X1  equ  0X1
HRAM_0X10  equ  0X10
HRAM_0X11  equ  0X11
HRAM_0X12  equ  0X12
HRAM_0X13  equ  0X13
HRAM_0X14  equ  0X14
HRAM_0X15  equ  0X15
HRAM_0X18  equ  0X18
HRAM_0X19  equ  0X19
HRAM_0X1A  equ  0X1a
HRAM_0X1B  equ  0X1b
HRAM_0X1C  equ  0X1c
HRAM_0X2  equ  0X2
HRAM_0X23  equ  0X23
HRAM_0X3  equ  0X3
HRAM_0X4  equ  0X4
HRAM_0X4A  equ  0X4a
HRAM_0X5  equ  0X5
HRAM_0X52  equ  0X52
HRAM_0X6  equ  0X6
HRAM_0X7  equ  0X7
HRAM_0X8  equ  0X8
HRAM_0X80  equ  0X80
HRAM_0X81  equ  0X81
HRAM_0X82  equ  0X82
HRAM_0X83  equ  0X83
HRAM_0X84  equ  0X84
HRAM_0X85  equ  0X85
HRAM_0X86  equ  0X86
HRAM_0X87  equ  0X87
HRAM_0X88  equ  0X88
HRAM_0X89  equ  0X89
HRAM_0X8A  equ  0X8a
HRAM_0X8B  equ  0X8b
HRAM_0X8C  equ  0X8c
HRAM_0X8D  equ  0X8d
HRAM_0X8E  equ  0X8e
HRAM_0X8F  equ  0X8f
HRAM_0X9  equ  0X9
HRAM_0X90  equ  0X90
HRAM_0X91  equ  0X91
HRAM_0X92  equ  0X92
HRAM_0X93  equ  0X93
HRAM_0X96  equ  0X96
HRAM_0X98  equ  0X98
HRAM_0X99  equ  0X99
HRAM_0X9A  equ  0X9a
HRAM_0X9B  equ  0X9b
HRAM_0X9C  equ  0X9c
HRAM_0X9D  equ  0X9d
HRAM_0X9E  equ  0X9e
HRAM_0XA  equ  0Xa
HRAM_0XA1  equ  0Xa1
HRAM_0XA2  equ  0Xa2
HRAM_0XA3  equ  0Xa3
HRAM_0XA4  equ  0Xa4
HRAM_0XA6  equ  0Xa6
HRAM_0XA7  equ  0Xa7
HRAM_0XA8  equ  0Xa8
HRAM_0XA9  equ  0Xa9
HRAM_0XAA  equ  0Xaa
HRAM_0XAD  equ  0Xad
HRAM_0XAE  equ  0Xae
HRAM_0XAF  equ  0Xaf
HRAM_0XB  equ  0Xb
HRAM_0XB2  equ  0Xb2
HRAM_0XB6  equ  0Xb6
HRAM_0XBC  equ  0Xbc
HRAM_0XBD  equ  0Xbd
HRAM_0XBE  equ  0Xbe
HRAM_0XC  equ  0Xc
HRAM_0XC0  equ  0Xc0
HRAM_0XC1  equ  0Xc1
HRAM_0XC2  equ  0Xc2
HRAM_0XC3  equ  0Xc3
HRAM_0XC4  equ  0Xc4
HRAM_0XC5  equ  0Xc5
HRAM_0XCF  equ  0Xcf
HRAM_0XD  equ  0Xd
HRAM_0XD0  equ  0Xd0
HRAM_0XD2  equ  0Xd2
HRAM_0XD3  equ  0Xd3
HRAM_0XE  equ  0Xe
HRAM_0XF  equ  0Xf

                ORG             0X00
HADR_0X0:
:0X0  6101                      CALL            HADR_0X101
:0X1  c7b9f000                  AJMP            HADR_0XB9
                                ORG             0X3
:0X3  6800                      GOTO            HADR_0X0
:0X4  c180                      PUSH
:0X5  e787                      CLR             HRAM_0X87
:0X6  e783                      CLR             HRAM_0X83
:0X7  5081                      MOV             HRAM_0X81,      A
:0X8  e600                      MOVA            HRAM_0X0
:0X9  5082                      MOV             HRAM_0X82,      A
:0Xa  e601                      MOVA            HRAM_0X1
:0Xb  500f                      MOV             HRAM_0XF,       A
:0Xc  e611                      MOVA            HRAM_0X11
:0Xd  5010                      MOV             HRAM_0X10,      A
HADR_0XE:
:0Xe  e612                      MOVA            HRAM_0X12
:0Xf  5090                      MOV             HRAM_0X90,      A
:0X10  e613                     MOVA            HRAM_0X13
HADR_0X11:
:0X11  5091                     MOV             HRAM_0X91,      A
:0X12  e614                     MOVA            HRAM_0X14
:0X13  500b                     MOV             HRAM_0XB,       A
:0X14  e60d                     MOVA            HRAM_0XD
:0X15  500c                     MOV             HRAM_0XC,       A
:0X16  e60e                     MOVA            HRAM_0XE
:0X17  5007                     MOV             HRAM_0X7,       A
:0X18  e603                     MOVA            HRAM_0X3
:0X19  5008                     MOV             HRAM_0X8,       A
:0X1a  e604                     MOVA            HRAM_0X4
:0X1b  5009                     MOV             HRAM_0X9,       A
:0X1c  e605                     MOVA            HRAM_0X5
:0X1d  500a                     MOV             HRAM_0XA,       A
:0X1e  e606                     MOVA            HRAM_0X6
;}
;
;/**************************************************************************
;* 函数名称：isr
;* 功能描述：中断入口函数
;* 输入参数：无
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void isr(void) interrupt
;{
;	uint8_t y;
;
;
;    if(PIE0==1 && PIF0==1)
:0X1f  e500                     MOVI            0X0
:0X20  989b                     JBC             HRAM_0X9B,      0
:0X21  e501                     MOVI            0X1
:0X22  ea01                     SECTION         0X1
:0X23  e611                     MOVA            HRAM_0X11
:0X24  5011                     MOV             HRAM_0X11,      A
:0X25  e301                     XORI            0X1
:0X26  9284                     JBS             HRAM_0X84,      2
:0X27  6831                     GOTO            HADR_0X31
:0X28  e500                     MOVI            0X0
:0X29  989c                     JBC             HRAM_0X9C,      0
:0X2a  e501                     MOVI            0X1
:0X2b  e611                     MOVA            HRAM_0X11
:0X2c  5011                     MOV             HRAM_0X11,      A
:0X2d  e301                     XORI            0X1
:0X2e  9284                     JBS             HRAM_0X84,      2
:0X2f  6831                     GOTO            HADR_0X31
;    {
;        PIF0 = 0;					//清除外部中断
:0X30  a89c                     BCC             HRAM_0X9C,      0
HADR_0X31:
;    }
:0X31  e500                     MOVI            0X0
:0X32  9999                     JBC             HRAM_0X99,      1
:0X33  e501                     MOVI            0X1
:0X34  e611                     MOVA            HRAM_0X11
:0X35  5011                     MOV             HRAM_0X11,      A
:0X36  e301                     XORI            0X1
:0X37  9284                     JBS             HRAM_0X84,      2
:0X38  6851                     GOTO            HADR_0X51
:0X39  e500                     MOVI            0X0
:0X3a  999a                     JBC             HRAM_0X9A,      1
:0X3b  e501                     MOVI            0X1
:0X3c  e611                     MOVA            HRAM_0X11
:0X3d  5011                     MOV             HRAM_0X11,      A
:0X3e  e301                     XORI            0X1
:0X3f  9284                     JBS             HRAM_0X84,      2
:0X40  6851                     GOTO            HADR_0X51
;    {
;        T8NIF = 0;					//清标志位
:0X41  a99a                     BCC             HRAM_0X9A,      1
;        T8N = 131;					//进中断先赋计数器初值
:0X42  e583                     MOVI            0X83
:0X43  e6bd                     MOVA            HRAM_0XBD
;
;		if (timer_cnt < 250)
:0X44  e5fa                     MOVI            0XFA
:0X45  ee18                     SUB             HRAM_0X18,      A
:0X46  9884                     JBC             HRAM_0X84,      0
:0X47  6851                     GOTO            HADR_0X51
;		{
;			timer_cnt++;
:0X48  5518                     INC             HRAM_0X18,      R
;			if (timer_cnt >= 4)		//两字节间隔8ms
:0X49  e504                     MOVI            0X4
:0X4a  ee18                     SUB             HRAM_0X18,      A
:0X4b  9084                     JBS             HRAM_0X84,      0
:0X4c  6851                     GOTO            HADR_0X51
;			{
;				timer_cnt = 250;
:0X4d  e5fa                     MOVI            0XFA
:0X4e  e618                     MOVA            HRAM_0X18
;				RX_OK_flag = 1;		//置位完成标志
:0X4f  e501                     MOVI            0X1
:0X50  e600                     MOVA            HRAM_0X0
HADR_0X51:
;			}
;		
;		}
;    }
:0X51  e500                     MOVI            0X0
:0X52  999d                     JBC             HRAM_0X9D,      1
:0X53  e501                     MOVI            0X1
:0X54  e611                     MOVA            HRAM_0X11
:0X55  5011                     MOV             HRAM_0X11,      A
:0X56  e301                     XORI            0X1
:0X57  9284                     JBS             HRAM_0X84,      2
:0X58  6880                     GOTO            HADR_0X80
:0X59  e500                     MOVI            0X0
:0X5a  999e                     JBC             HRAM_0X9E,      1
:0X5b  e501                     MOVI            0X1
:0X5c  e611                     MOVA            HRAM_0X11
:0X5d  5011                     MOV             HRAM_0X11,      A
:0X5e  e301                     XORI            0X1
:0X5f  9284                     JBS             HRAM_0X84,      2
:0X60  6880                     GOTO            HADR_0X80
;    {
;		timer_cnt = 0;				//重新计数
:0X61  e718                     CLR             HRAM_0X18
;		rxbuf[rxbuf[0] + 1] = RX0B;
:0X62  5023                     MOV             HRAM_0X23,      A
:0X63  e001                     ADDI            0X1
:0X64  e611                     MOVA            HRAM_0X11
:0X65  e712                     CLR             HRAM_0X12
:0X66  b112                     RLB             HRAM_0X12,      R,              0X1
:0X67  5011                     MOV             HRAM_0X11,      A
:0X68  e0a3                     ADDI            0XA3
:0X69  e613                     MOVA            HRAM_0X13
:0X6a  5012                     MOV             HRAM_0X12,      A
:0X6b  c300                     ADDCI           0X0
:0X6c  e614                     MOVA            HRAM_0X14
:0X6d  5014                     MOV             HRAM_0X14,      A
:0X6e  e682                     MOVA            HRAM_0X82
:0X6f  5013                     MOV             HRAM_0X13,      A
:0X70  e681                     MOVA            HRAM_0X81
:0X71  a483                     BSS             HRAM_0X83,      4
:0X72  50cf                     MOV             HRAM_0XCF,      A
:0X73  e680                     MOVA            HRAM_0X80
:0X74  c201                     ISTEP           0X1
;		rxbuf[0] = rxbuf[0] + 1;
:0X75  5023                     MOV             HRAM_0X23,      A
:0X76  e001                     ADDI            0X1
:0X77  e611                     MOVA            HRAM_0X11
:0X78  5011                     MOV             HRAM_0X11,      A
:0X79  e623                     MOVA            HRAM_0X23
;
;		if(rxbuf[0] > 30)			//接收限制
:0X7a  5023                     MOV             HRAM_0X23,      A
:0X7b  ce1e                     SUBI            0X1E
:0X7c  9884                     JBC             HRAM_0X84,      0
:0X7d  6880                     GOTO            HADR_0X80
;		{
;			rxbuf[0] = 30;
:0X7e  e51e                     MOVI            0X1E
:0X7f  e623                     MOVA            HRAM_0X23
HADR_0X80:
;		}
;    }
:0X80  9499                     JBS             HRAM_0X99,      4
:0X81  688b                     GOTO            HADR_0X8B
:0X82  94a3                     JBS             HRAM_0XA3,      4
:0X83  688b                     GOTO            HADR_0X8B
:0X84  949a                     JBS             HRAM_0X9A,      4
:0X85  688b                     GOTO            HADR_0X8B
;    {
;		KIF = 0;       //清除外部中断
:0X86  ac9a                     BCC             HRAM_0X9A,      4
;		if(IRQ)
:0X87  93a9                     JBS             HRAM_0XA9,      3
:0X88  688b                     GOTO            HADR_0X8B
;		{
;			_hw2000b_irq_request = 1;
:0X89  ea00                     SECTION         0X0
:0X8a  a015                     BSS             HRAM_0X15,      0
HADR_0X8B:
;		}
;    }
;
;}
:0X8b  ea00                     SECTION         0X0
:0X8c  ac83                     BCC             HRAM_0X83,      4
:0X8d  688e                     GOTO            HADR_0X8E
HADR_0X8E:
:0X8e  ffff                     NOP
:0X8f  ffff                     NOP
:0X90  5003                     MOV             HRAM_0X3,       A
:0X91  e607                     MOVA            HRAM_0X7
:0X92  5004                     MOV             HRAM_0X4,       A
:0X93  e608                     MOVA            HRAM_0X8
:0X94  5005                     MOV             HRAM_0X5,       A
:0X95  e609                     MOVA            HRAM_0X9
:0X96  5006                     MOV             HRAM_0X6,       A
:0X97  e60a                     MOVA            HRAM_0XA
:0X98  5012                     MOV             HRAM_0X12,      A
:0X99  e610                     MOVA            HRAM_0X10
:0X9a  5011                     MOV             HRAM_0X11,      A
:0X9b  e60f                     MOVA            HRAM_0XF
:0X9c  500d                     MOV             HRAM_0XD,       A
:0X9d  e60b                     MOVA            HRAM_0XB
:0X9e  e688                     MOVA            HRAM_0X88
:0X9f  500e                     MOV             HRAM_0XE,       A
:0Xa0  e60c                     MOVA            HRAM_0XC
:0Xa1  e689                     MOVA            HRAM_0X89
:0Xa2  5001                     MOV             HRAM_0X1,       A
:0Xa3  e682                     MOVA            HRAM_0X82
:0Xa4  5000                     MOV             HRAM_0X0,       A
:0Xa5  e681                     MOVA            HRAM_0X81
:0Xa6  5014                     MOV             HRAM_0X14,      A
:0Xa7  e691                     MOVA            HRAM_0X91
:0Xa8  5013                     MOV             HRAM_0X13,      A
:0Xa9  e690                     MOVA            HRAM_0X90
:0Xaa  c184                     TBR
:0Xab  c181                     POP
:0Xac  c189                     RETIE
HADR_0XAD:
:0Xad  5f86                     ADD             HRAM_0X86,      R
:0Xae  e403                     RETIA           0X3
:0Xaf  e482                     RETIA           0X82
:0Xb0  e401                     RETIA           0X1
:0Xb1  e400                     RETIA           0X0
:0Xb2  e480                     RETIA           0X80
:0Xb3  e401                     RETIA           0X1
:0Xb4  e400                     RETIA           0X0
:0Xb5  e481                     RETIA           0X81
:0Xb6  e401                     RETIA           0X1
:0Xb7  e400                     RETIA           0X0
:0Xb8  e400                     RETIA           0X0
HADR_0XB9:
;
;
;/**************************************************************************
;* 函数名称：main
;* 功能描述：工程入口
;* 输入参数：无
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void main(void) 
;{
;    GPIOInit();										//初始化GPIO
:0Xb9  e783                     CLR             HRAM_0X83
:0Xba  ec00                     PAGE            0X0
:0Xbb  6347                     CALL            HADR_0X347
:0Xbc  ec00                     PAGE            0X0
;	WDT_Init();										//初始化看门狗
:0Xbd  ec00                     PAGE            0X0
:0Xbe  637f                     CALL            HADR_0X37F
:0Xbf  ec00                     PAGE            0X0
;	UART_Init();									//初始化串口
:0Xc0  ec00                     PAGE            0X0
:0Xc1  6384                     CALL            HADR_0X384
:0Xc2  ec00                     PAGE            0X0
;	TIME_Init();									//初始化定时器
:0Xc3  ec00                     PAGE            0X0
:0Xc4  638f                     CALL            HADR_0X38F
:0Xc5  ec00                     PAGE            0X0
;
;	rxbuf[0] = 0;									//清串口计数值
:0Xc6  e500                     MOVI            0X0
:0Xc7  20a3                     MOVAR           HRAM_0XA3
;	RX_OK_flag = 0;									//清串口接收完成标志
:0Xc8  ea01                     SECTION         0X1
:0Xc9  e700                     CLR             HRAM_0X0
;	sleep_flag = 1;									//上电休眠
:0Xca  e501                     MOVI            0X1
:0Xcb  e602                     MOVA            HRAM_0X2
;
;	spi_init();										//初始化SPI端口
:0Xcc  ec00                     PAGE            0X0
:0Xcd  639c                     CALL            HADR_0X39C
:0Xce  ec00                     PAGE            0X0
;
;	hw2000b_port_init();							//初始化射频端口
:0Xcf  ec00                     PAGE            0X0
:0Xd0  613b                     CALL            HADR_0X13B
:0Xd1  ec00                     PAGE            0X0
;	hw2000b_init_250k();							//初始化射频参数
:0Xd2  ec00                     PAGE            0X0
:0Xd3  614e                     CALL            HADR_0X14E
:0Xd4  ec00                     PAGE            0X0
;	hw2000b_power_down();							//关闭射频模块
:0Xd5  ec00                     PAGE            0X0
:0Xd6  62e7                     CALL            HADR_0X2E7
:0Xd7  ec00                     PAGE            0X0
;
;	GIE = 1;										//全局中断使能
:0Xd8  a796                     BSS             HRAM_0X96,      7
HADR_0XD9:
;
;	while(1) 
:0Xd9  ea01                     SECTION         0X1
:0Xda  5002                     MOV             HRAM_0X2,       A
:0Xdb  9a84                     JBC             HRAM_0X84,      2
:0Xdc  68e2                     GOTO            HADR_0XE2
;		{
;			sleep();							//进入睡眠函数
:0Xdd  ec00                     PAGE            0X0
:0Xde  6359                     CALL            HADR_0X359
:0Xdf  ec00                     PAGE            0X0
;			sleep_flag = 0;						//清睡眠标志位
:0Xe0  ea01                     SECTION         0X1
:0Xe1  e702                     CLR             HRAM_0X2
HADR_0XE2:
;		}
:0Xe2  5000                     MOV             HRAM_0X0,       A
:0Xe3  9a84                     JBC             HRAM_0X84,      2
:0Xe4  68ff                     GOTO            HADR_0XFF
;		{
;			RX_OK_flag = 0;						//清接收完成标志位
:0Xe5  e700                     CLR             HRAM_0X0
;			CLRWDT();
:0Xe6  c18b                     CWDT
;
;			hw2000b_power_on();					//打开射频模块
:0Xe7  ec00                     PAGE            0X0
:0Xe8  630a                     CALL            HADR_0X30A
:0Xe9  ec00                     PAGE            0X0
;			hw2000b_tx_data(rxbuf, rxbuf[0] + 1);	//发送串口数据
:0Xea  e5a3                     MOVI            0XA3
:0Xeb  2085                     MOVAR           HRAM_0X85
:0Xec  e500                     MOVI            0X0
:0Xed  2086                     MOVAR           HRAM_0X86
:0Xee  78a3                     MOVRA           HRAM_0XA3
:0Xef  e001                     ADDI            0X1
:0Xf0  2087                     MOVAR           HRAM_0X87
:0Xf1  ea01                     SECTION         0X1
:0Xf2  e708                     CLR             HRAM_0X8
:0Xf3  b108                     RLB             HRAM_0X8,       R,              0X1
:0Xf4  ec00                     PAGE            0X0
:0Xf5  624e                     CALL            HADR_0X24E
:0Xf6  ec00                     PAGE            0X0
;			hw2000b_power_down();				//关闭射频模块
:0Xf7  ec00                     PAGE            0X0
:0Xf8  62e7                     CALL            HADR_0X2E7
:0Xf9  ec00                     PAGE            0X0
;			CLRWDT();
:0Xfa  c18b                     CWDT
;
;			rxbuf[0] = 0;						//清除计数值
:0Xfb  e500                     MOVI            0X0
:0Xfc  20a3                     MOVAR           HRAM_0XA3
;
;			sleep_flag = 1;						//置睡眠标志位
:0Xfd  e501                     MOVI            0X1
:0Xfe  2082                     MOVAR           HRAM_0X82
HADR_0XFF:
;		}
:0Xff  c18b                     CWDT
;	}
:0X100  68d9                    GOTO            HADR_0XD9
HADR_0X101:
:0X101  e783                    CLR             HRAM_0X83
:0X102  e500                    MOVI            0X0
:0X103  e687                    MOVA            HRAM_0X87
:0X104  e500                    MOVI            0X0
:0X105  e607                    MOVA            HRAM_0X7
:0X106  5007                    MOV             HRAM_0X7,       A
:0X107  ec00                    PAGE            0X0
:0X108  60ad                    CALL            HADR_0XAD
:0X109  e608                    MOVA            HRAM_0X8
:0X10a  5108                    MOV             HRAM_0X8,       R
:0X10b  9a84                    JBC             HRAM_0X84,      2
:0X10c  c183                    RET
HADR_0X10D:
:0X10d  5507                    INC             HRAM_0X7,       R
:0X10e  5007                    MOV             HRAM_0X7,       A
:0X10f  ec00                    PAGE            0X0
:0X110  60ad                    CALL            HADR_0XAD
:0X111  e609                    MOVA            HRAM_0X9
:0X112  5507                    INC             HRAM_0X7,       R
:0X113  5007                    MOV             HRAM_0X7,       A
:0X114  ec00                    PAGE            0X0
:0X115  60ad                    CALL            HADR_0XAD
:0X116  e60a                    MOVA            HRAM_0XA
:0X117  611b                    CALL            HADR_0X11B
:0X118  5708                    JDEC            HRAM_0X8,       R
:0X119  690d                    GOTO            HADR_0X10D
:0X11a  c183                    RET
HADR_0X11B:
:0X11b  5009                    MOV             HRAM_0X9,       A
:0X11c  e681                    MOVA            HRAM_0X81
:0X11d  e500                    MOVI            0X0
:0X11e  e682                    MOVA            HRAM_0X82
:0X11f  5507                    INC             HRAM_0X7,       R
:0X120  5007                    MOV             HRAM_0X7,       A
:0X121  ec00                    PAGE            0X0
:0X122  60ad                    CALL            HADR_0XAD
:0X123  e680                    MOVA            HRAM_0X80
:0X124  5509                    INC             HRAM_0X9,       R
:0X125  570a                    JDEC            HRAM_0XA,       R
:0X126  691b                    GOTO            HADR_0X11B
:0X127  c183                    RET
:0X128  5f86                    ADD             HRAM_0X86,      R
:0X129  0000                    UserData	       0X0                                 ; !! Unknown Command
:0X12a  0000                    UserData	       0X0                                 ; !! Unknown Command
:0X12b  0000                    UserData	       0X0                                 ; !! Unknown Command
:0X12c  0001                    UserData	       0X1                                 ; !! Unknown Command
:0X12d  0002                    UserData	       0X2                                 ; !! Unknown Command
:0X12e  000a                    UserData	       0Xa                                 ; !! Unknown Command
:0X12f  0012                    UserData	       0X12                                ; !! Unknown Command
:0X130  0212                    UserData	       0X212                               ; !! Unknown Command
:0X131  0412                    UserData	       0X412                               ; !! Unknown Command
:0X132  064a                    UserData	       0X64a                               ; !! Unknown Command
:0X133  084a                    JCCRE           HRAM_0X4A,      0
:0X134  0a4a                    JCCRE           HRAM_0X4A,      2
:0X135  0a52                    JCCRE           HRAM_0X52,      2
:0X136  0a92                    JCCRE           HRAM_0X92,      2
:0X137  0c92                    UserData	       0Xc92                               ; !! Unknown Command
:0X138  0cd2                    UserData	       0Xcd2                               ; !! Unknown Command
:0X139  0cda                    UserData	       0Xcda                               ; !! Unknown Command
:0X13a  0ce3                    UserData	       0Xce3                               ; !! Unknown Command
HADR_0X13B:
;/**************************************************************************
;* 版权声明：Copyright@2019 上海东软载波微电子有限公司
;* 文件名称：hw2000b.c
;* 功能描述：RF函数
;* 函数列表：hw2000b_port_init
;			hw2000b_init_1m
;			hw2000b_init_250k
;			hw2000b_set_osc_16M
;			hw2000b_set_power_max
;			hw2000b_set_power_0
;			hw2000b_set_power_negative_20
;			hw2000b_set_frequence_2403
;			hw2000b_set_frequence_2450
;			hw2000b_set_frequence_2483
;			hw2000b_power_test
;			hw2000b_cancel_sw
;			hw2000b_tx_data
;			hw2000b_rx_enable
;			hw2000b_rx_data
;			hw2000b_power_down
;			hw2000b_power_on
;* 文件作者：Ljj  
;* 文件版本： 
;* 完成日期：2023-08-23	
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;#include <hic.h>
;#include "type.h"
;#include "hw2000b.h"
;#include "spi.h"
;#include "timer.h"
;
;const uint16_t agcTab[18] = {0x0000, 0x0000, 0x0000, 0x0001, 0x0002, 0x000A,
;                             0x0012, 0x0212, 0x0412, 0x064A, 0x084A, 0x0A4A,
;                             0x0A52, 0x0A92, 0x0C92, 0x0CD2, 0x0CDA, 0x0CE3
;};
;extern	sbit		_hw2000b_irq_request;
;
;extern	uint16_t	_ack_count;
;
;//uint16_t reg_value1;
;
;/**************************************************************************
;* 函数名称：hw2000b_port_init
;* 功能描述：初始化hw2000b接口
;* 输入参数：无
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void hw2000b_port_init(void)
;{
;	CE = 0;
:0X13b  e783                    CLR             HRAM_0X83
:0X13c  afa9                    BCC             HRAM_0XA9,      7
;	delay_ms(3);
:0X13d  e503                    MOVI            0X3
:0X13e  ea01                    SECTION         0X1
:0X13f  e609                    MOVA            HRAM_0X9
:0X140  e500                    MOVI            0X0
:0X141  e60a                    MOVA            HRAM_0XA
:0X142  ec00                    PAGE            0X0
:0X143  6437                    CALL            HADR_0X437
:0X144  ec00                    PAGE            0X0
;	CE = 1;
:0X145  a7a9                    BSS             HRAM_0XA9,      7
;	delay_ms(3);
:0X146  e503                    MOVI            0X3
:0X147  2089                    MOVAR           HRAM_0X89
:0X148  e500                    MOVI            0X0
:0X149  208a                    MOVAR           HRAM_0X8A
:0X14a  ec00                    PAGE            0X0
:0X14b  6437                    CALL            HADR_0X437
:0X14c  ec00                    PAGE            0X0
;}
:0X14d  c183                    RET
HADR_0X14E:
;
;void reg_read_write_test()
;{
;	uint8_t i=0;
;    hw2000b_write_reg(0x4C, 0x55AA);	//close write protection
;    uint16_t all_reg_value[0x6a+1] = {0};
;    for(i=0;i<=0x6a;i++)
;    {
;        all_reg_value[i] = hw2000b_read_reg(i);
;    }
;    //write 0 to all reg 
;    for(i=0;i<=0x6a;i++)
;    {
;        if(i != 0x4C)
;        {
;            hw2000b_write_reg(i,0x0000);
;        }
;        all_reg_value[i] = hw2000b_read_reg(i);
;    }
;    
;    //write 1 to all reg 
;    for(i=0;i<=0x6a;i++)
;    {
;        if(i != 0x4C && i != 0x4F)
;        {
;            hw2000b_write_reg(i,0xffff);
;        } else if(i == 0x4F)
;                {
;                    hw2000b_write_reg(i,0x0000);
;                }
;        all_reg_value[i] = hw2000b_read_reg(i);
;    }
;    
;    all_reg_value[0] = hw2000b_read_reg(0);//breakpoint test
;}
;/**************************************************************************
;* 函数名称：hw2000b_init_1m
;* 功能描述：初始化hw2000b，速率为1M，晶振12M,最大功率
;* 输入参数：无
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void hw2000b_init_1m(void)
;{
;    uint8_t i;
;
;	hw2000b_write_reg(0x4C, 0x55AA);		//open write protection
;	for (i = 0; i < 18; i++) {
;        hw2000b_write_reg(0x50 + i, agcTab[i]);            
;    }
;
;	hw2000b_write_reg(0x0F, 0xFC04);//ES7W8020
;
;    hw2000b_write_reg(0x01, 0x4D58);//ES7W8020
;    hw2000b_write_reg(0x02, 0x04CC);//ES7W8020
;    hw2000b_write_reg(0x08, 0xB6C4);//ES7W8020
;	hw2000b_write_reg(0x09, 0xB442);//ES7W8020
;    hw2000b_write_reg(0x4A, 0x326C);//ES7W8020
;
;    hw2000b_write_reg(0x0B, 0x0873);//ES7W8020    8dBm
;    hw2000b_write_reg(0x49, 0x1330);//ES7W8020
;    hw2000b_write_reg(0x27, 0x8F20);//ES7W8020
;	hw2000b_write_reg(0x48, 0x4300);//ES7W8020
;	hw2000b_write_reg(0x26, 0x000C);//ES7W8020
;
;    hw2000b_write_reg(0x28, 0x8401);//sync_thres 1bit
;    hw2000b_write_reg(0x2C, 0x918B);
;    hw2000b_write_reg(0x1B, 0xE754);
;    hw2000b_write_reg(0x06, 0xB000);
;    hw2000b_write_reg(0x07, 0x54E0);
;    hw2000b_write_reg(0x1C, 0x51A0);
;    hw2000b_write_reg(0x19, 0x2084);
;    hw2000b_write_reg(0x20, 0xF000);//preamble:16 bytes, sync:48 bits
;    hw2000b_write_reg(0x2A, 0xC07D);//rate:1Mbps, ACK_time:28us
;}
;
;/**************************************************************************
;* 函数名称：hw2000b_init_250k
;* 功能描述：初始化hw2000b，速率为250k,晶振12M，最大功率
;* 输入参数：无
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void hw2000b_init_250k(void)
;{
;    uint8_t i;
;
;	hw2000b_write_reg(0x4C, 0x55AA);		//open write project
:0X14e  e783                    CLR             HRAM_0X83
:0X14f  e54c                    MOVI            0X4C
:0X150  ea01                    SECTION         0X1
:0X151  e60e                    MOVA            HRAM_0XE
:0X152  e5aa                    MOVI            0XAA
:0X153  e60f                    MOVA            HRAM_0XF
:0X154  e555                    MOVI            0X55
:0X155  e610                    MOVA            HRAM_0X10
:0X156  ec00                    PAGE            0X0
:0X157  63b0                    CALL            HADR_0X3B0
:0X158  ec00                    PAGE            0X0
;	for (i = 0; i < 18; i++) {
:0X159  ea01                    SECTION         0X1
:0X15a  e709                    CLR             HRAM_0X9
HADR_0X15B:
:0X15b  e512                    MOVI            0X12
:0X15c  ee09                    SUB             HRAM_0X9,       A
:0X15d  9884                    JBC             HRAM_0X84,      0
:0X15e  6987                    GOTO            HADR_0X187
;        hw2000b_write_reg(0x50 + i, agcTab[i]);
:0X15f  5009                    MOV             HRAM_0X9,       A
:0X160  e050                    ADDI            0X50
:0X161  e60e                    MOVA            HRAM_0XE
:0X162  e70b                    CLR             HRAM_0XB
:0X163  5009                    MOV             HRAM_0X9,       A
:0X164  e60a                    MOVA            HRAM_0XA
:0X165  a884                    BCC             HRAM_0X84,      0
:0X166  b00a                    RLB             HRAM_0XA,       A,              0X1
:0X167  e60c                    MOVA            HRAM_0XC
:0X168  b00b                    RLB             HRAM_0XB,       A,              0X1
:0X169  e60d                    MOVA            HRAM_0XD
:0X16a  500c                    MOV             HRAM_0XC,       A
:0X16b  e052                    ADDI            0X52
:0X16c  e60a                    MOVA            HRAM_0XA
:0X16d  500d                    MOV             HRAM_0XD,       A
:0X16e  c302                    ADDCI           0X2
:0X16f  e60b                    MOVA            HRAM_0XB
:0X170  500a                    MOV             HRAM_0XA,       A
:0X171  200f                    MOVAR           HRAM_0XF
:0X172  500b                    MOV             HRAM_0XB,       A
:0X173  2010                    MOVAR           HRAM_0X10
:0X174  ec07                    PAGE            0X7
:0X175  ea00                    SECTION         0X0
:0X176  6000                    CALL            HADR_0X0
:0X177  ec00                    PAGE            0X0
:0X178  e607                    MOVA            HRAM_0X7
:0X179  ec07                    PAGE            0X7
:0X17a  6000                    CALL            HADR_0X0
:0X17b  ec00                    PAGE            0X0
:0X17c  e608                    MOVA            HRAM_0X8
:0X17d  5007                    MOV             HRAM_0X7,       A
:0X17e  208f                    MOVAR           HRAM_0X8F
:0X17f  5008                    MOV             HRAM_0X8,       A
:0X180  2090                    MOVAR           HRAM_0X90
:0X181  ec00                    PAGE            0X0
:0X182  63b0                    CALL            HADR_0X3B0
:0X183  ec00                    PAGE            0X0
:0X184  ea01                    SECTION         0X1
:0X185  5509                    INC             HRAM_0X9,       R
;    }
:0X186  695b                    GOTO            HADR_0X15B
HADR_0X187:
;
;	hw2000b_write_reg(0x0F, 0xFC04);//ES7W8020
:0X187  e50f                    MOVI            0XF
:0X188  e60e                    MOVA            HRAM_0XE
:0X189  e504                    MOVI            0X4
:0X18a  e60f                    MOVA            HRAM_0XF
:0X18b  e5fc                    MOVI            0XFC
:0X18c  e610                    MOVA            HRAM_0X10
:0X18d  ec00                    PAGE            0X0
:0X18e  63b0                    CALL            HADR_0X3B0
:0X18f  ec00                    PAGE            0X0
;
;    hw2000b_write_reg(0x01, 0x4D58);//ES7W8020
:0X190  e501                    MOVI            0X1
:0X191  208e                    MOVAR           HRAM_0X8E
:0X192  e558                    MOVI            0X58
:0X193  208f                    MOVAR           HRAM_0X8F
:0X194  e54d                    MOVI            0X4D
:0X195  2090                    MOVAR           HRAM_0X90
:0X196  ec00                    PAGE            0X0
:0X197  63b0                    CALL            HADR_0X3B0
:0X198  ec00                    PAGE            0X0
;    hw2000b_write_reg(0x02, 0x04CC);//ES7W8020
:0X199  e502                    MOVI            0X2
:0X19a  208e                    MOVAR           HRAM_0X8E
:0X19b  e5cc                    MOVI            0XCC
:0X19c  208f                    MOVAR           HRAM_0X8F
:0X19d  e504                    MOVI            0X4
:0X19e  2090                    MOVAR           HRAM_0X90
:0X19f  ec00                    PAGE            0X0
:0X1a0  63b0                    CALL            HADR_0X3B0
:0X1a1  ec00                    PAGE            0X0
;    hw2000b_write_reg(0x08, 0xB6C4);//ES7W8020
:0X1a2  e508                    MOVI            0X8
:0X1a3  208e                    MOVAR           HRAM_0X8E
:0X1a4  e5c4                    MOVI            0XC4
:0X1a5  208f                    MOVAR           HRAM_0X8F
:0X1a6  e5b6                    MOVI            0XB6
:0X1a7  2090                    MOVAR           HRAM_0X90
:0X1a8  ec00                    PAGE            0X0
:0X1a9  63b0                    CALL            HADR_0X3B0
:0X1aa  ec00                    PAGE            0X0
;	hw2000b_write_reg(0x09, 0xB442);//ES7W8020  
:0X1ab  e509                    MOVI            0X9
:0X1ac  208e                    MOVAR           HRAM_0X8E
:0X1ad  e542                    MOVI            0X42
:0X1ae  208f                    MOVAR           HRAM_0X8F
:0X1af  e5b4                    MOVI            0XB4
:0X1b0  2090                    MOVAR           HRAM_0X90
:0X1b1  ec00                    PAGE            0X0
:0X1b2  63b0                    CALL            HADR_0X3B0
:0X1b3  ec00                    PAGE            0X0
;    hw2000b_write_reg(0x4A, 0x326C);//ES7W8020 
:0X1b4  e54a                    MOVI            0X4A
:0X1b5  208e                    MOVAR           HRAM_0X8E
:0X1b6  e56c                    MOVI            0X6C
:0X1b7  208f                    MOVAR           HRAM_0X8F
:0X1b8  e532                    MOVI            0X32
:0X1b9  2090                    MOVAR           HRAM_0X90
:0X1ba  ec00                    PAGE            0X0
:0X1bb  63b0                    CALL            HADR_0X3B0
:0X1bc  ec00                    PAGE            0X0
;
;    hw2000b_write_reg(0x0B, 0x0873);//ES7W8020   tx power:8dBm
:0X1bd  e50b                    MOVI            0XB
:0X1be  208e                    MOVAR           HRAM_0X8E
:0X1bf  e573                    MOVI            0X73
:0X1c0  208f                    MOVAR           HRAM_0X8F
:0X1c1  e508                    MOVI            0X8
:0X1c2  2090                    MOVAR           HRAM_0X90
:0X1c3  ec00                    PAGE            0X0
:0X1c4  63b0                    CALL            HADR_0X3B0
:0X1c5  ec00                    PAGE            0X0
;    hw2000b_write_reg(0x49, 0x1330);//ES7W8020   
:0X1c6  e549                    MOVI            0X49
:0X1c7  208e                    MOVAR           HRAM_0X8E
:0X1c8  e530                    MOVI            0X30
:0X1c9  208f                    MOVAR           HRAM_0X8F
:0X1ca  e513                    MOVI            0X13
:0X1cb  2090                    MOVAR           HRAM_0X90
:0X1cc  ec00                    PAGE            0X0
:0X1cd  63b0                    CALL            HADR_0X3B0
:0X1ce  ec00                    PAGE            0X0
;    hw2000b_write_reg(0x27, 0x8F20);//ES7W8020   
:0X1cf  e527                    MOVI            0X27
:0X1d0  208e                    MOVAR           HRAM_0X8E
:0X1d1  e520                    MOVI            0X20
:0X1d2  208f                    MOVAR           HRAM_0X8F
:0X1d3  e58f                    MOVI            0X8F
:0X1d4  2090                    MOVAR           HRAM_0X90
:0X1d5  ec00                    PAGE            0X0
:0X1d6  63b0                    CALL            HADR_0X3B0
:0X1d7  ec00                    PAGE            0X0
;	hw2000b_write_reg(0x48, 0x4300);//ES7W8020
:0X1d8  e548                    MOVI            0X48
:0X1d9  208e                    MOVAR           HRAM_0X8E
:0X1da  e500                    MOVI            0X0
:0X1db  208f                    MOVAR           HRAM_0X8F
:0X1dc  e543                    MOVI            0X43
:0X1dd  2090                    MOVAR           HRAM_0X90
:0X1de  ec00                    PAGE            0X0
:0X1df  63b0                    CALL            HADR_0X3B0
:0X1e0  ec00                    PAGE            0X0
;	hw2000b_write_reg(0x26, 0x000C);//ES7W8020
:0X1e1  e526                    MOVI            0X26
:0X1e2  208e                    MOVAR           HRAM_0X8E
:0X1e3  e50c                    MOVI            0XC
:0X1e4  208f                    MOVAR           HRAM_0X8F
:0X1e5  e500                    MOVI            0X0
:0X1e6  2090                    MOVAR           HRAM_0X90
:0X1e7  ec00                    PAGE            0X0
:0X1e8  63b0                    CALL            HADR_0X3B0
:0X1e9  ec00                    PAGE            0X0
;
;    hw2000b_write_reg(0x28, 0x8401);//sync_thres:1bit
:0X1ea  e528                    MOVI            0X28
:0X1eb  208e                    MOVAR           HRAM_0X8E
:0X1ec  e501                    MOVI            0X1
:0X1ed  208f                    MOVAR           HRAM_0X8F
:0X1ee  e584                    MOVI            0X84
:0X1ef  2090                    MOVAR           HRAM_0X90
:0X1f0  ec00                    PAGE            0X0
:0X1f1  63b0                    CALL            HADR_0X3B0
:0X1f2  ec00                    PAGE            0X0
;    hw2000b_write_reg(0x2C, 0x918B);	
:0X1f3  e52c                    MOVI            0X2C
:0X1f4  208e                    MOVAR           HRAM_0X8E
:0X1f5  e58b                    MOVI            0X8B
:0X1f6  208f                    MOVAR           HRAM_0X8F
:0X1f7  e591                    MOVI            0X91
:0X1f8  2090                    MOVAR           HRAM_0X90
:0X1f9  ec00                    PAGE            0X0
:0X1fa  63b0                    CALL            HADR_0X3B0
:0X1fb  ec00                    PAGE            0X0
;	hw2000b_write_reg(0x2A, 0x40FF);//rate:250kbps     ACK_time:1000us
:0X1fc  e52a                    MOVI            0X2A
:0X1fd  208e                    MOVAR           HRAM_0X8E
:0X1fe  e5ff                    MOVI            0XFF
:0X1ff  208f                    MOVAR           HRAM_0X8F
:0X200  e540                    MOVI            0X40
:0X201  2090                    MOVAR           HRAM_0X90
:0X202  ec00                    PAGE            0X0
:0X203  63b0                    CALL            HADR_0X3B0
:0X204  ec00                    PAGE            0X0
;	hw2000b_write_reg(0x1A, 0x0D31);
:0X205  e51a                    MOVI            0X1A
:0X206  208e                    MOVAR           HRAM_0X8E
:0X207  e531                    MOVI            0X31
:0X208  208f                    MOVAR           HRAM_0X8F
:0X209  e50d                    MOVI            0XD
:0X20a  2090                    MOVAR           HRAM_0X90
:0X20b  ec00                    PAGE            0X0
:0X20c  63b0                    CALL            HADR_0X3B0
:0X20d  ec00                    PAGE            0X0
;	hw2000b_write_reg(0x19, 0x0884);
:0X20e  e519                    MOVI            0X19
:0X20f  208e                    MOVAR           HRAM_0X8E
:0X210  e584                    MOVI            0X84
:0X211  208f                    MOVAR           HRAM_0X8F
:0X212  e508                    MOVI            0X8
:0X213  2090                    MOVAR           HRAM_0X90
:0X214  ec00                    PAGE            0X0
:0X215  63b0                    CALL            HADR_0X3B0
:0X216  ec00                    PAGE            0X0
;	hw2000b_write_reg(0x20, 0xF000);//preamble:16 bytes  sync:48 bits
:0X217  e520                    MOVI            0X20
:0X218  208e                    MOVAR           HRAM_0X8E
:0X219  e500                    MOVI            0X0
:0X21a  208f                    MOVAR           HRAM_0X8F
:0X21b  e5f0                    MOVI            0XF0
:0X21c  2090                    MOVAR           HRAM_0X90
:0X21d  ec00                    PAGE            0X0
:0X21e  63b0                    CALL            HADR_0X3B0
:0X21f  ec00                    PAGE            0X0
;
;	hw2000b_write_reg(0x3C, 0x1001);//Enable PIPE0、PIPE0 ACK
:0X220  e53c                    MOVI            0X3C
:0X221  208e                    MOVAR           HRAM_0X8E
:0X222  e501                    MOVI            0X1
:0X223  208f                    MOVAR           HRAM_0X8F
:0X224  e510                    MOVI            0X10
:0X225  2090                    MOVAR           HRAM_0X90
:0X226  ec00                    PAGE            0X0
:0X227  63b0                    CALL            HADR_0X3B0
:0X228  ec00                    PAGE            0X0
;
;	// pipe 0 addr set 
;    hw2000b_write_reg(0x40, 0x1122); 
:0X229  e540                    MOVI            0X40
:0X22a  208e                    MOVAR           HRAM_0X8E
:0X22b  e522                    MOVI            0X22
:0X22c  208f                    MOVAR           HRAM_0X8F
:0X22d  e511                    MOVI            0X11
:0X22e  2090                    MOVAR           HRAM_0X90
:0X22f  ec00                    PAGE            0X0
:0X230  63b0                    CALL            HADR_0X3B0
:0X231  ec00                    PAGE            0X0
;    hw2000b_write_reg(0x41, 0x3344); 
:0X232  e541                    MOVI            0X41
:0X233  208e                    MOVAR           HRAM_0X8E
:0X234  e544                    MOVI            0X44
:0X235  208f                    MOVAR           HRAM_0X8F
:0X236  e533                    MOVI            0X33
:0X237  2090                    MOVAR           HRAM_0X90
:0X238  ec00                    PAGE            0X0
:0X239  63b0                    CALL            HADR_0X3B0
:0X23a  ec00                    PAGE            0X0
;    hw2000b_write_reg(0x42, 0x5566); 
:0X23b  e542                    MOVI            0X42
:0X23c  208e                    MOVAR           HRAM_0X8E
:0X23d  e566                    MOVI            0X66
:0X23e  208f                    MOVAR           HRAM_0X8F
:0X23f  e555                    MOVI            0X55
:0X240  2090                    MOVAR           HRAM_0X90
:0X241  ec00                    PAGE            0X0
:0X242  63b0                    CALL            HADR_0X3B0
:0X243  ec00                    PAGE            0X0
;
;	hw2000b_write_reg(0x23, 0x0500);//re_tx_times:5
:0X244  e523                    MOVI            0X23
:0X245  208e                    MOVAR           HRAM_0X8E
:0X246  e500                    MOVI            0X0
:0X247  208f                    MOVAR           HRAM_0X8F
:0X248  e505                    MOVI            0X5
:0X249  2090                    MOVAR           HRAM_0X90
:0X24a  ec00                    PAGE            0X0
:0X24b  63b0                    CALL            HADR_0X3B0
:0X24c  ec00                    PAGE            0X0
;	//reg_value1 = hw2000b_read_reg(0x28);
;
;	//if(reg_value1 != 0x2103)
;	//{
;	//hw2000b_write_reg(0x20, 0xF000);//preamble:16 bytes  sync:48 bits
;	//}
;}
:0X24d  c183                    RET
HADR_0X24E:
;
;/**************************************************************************
;* 函数名称：hw2000b_set_osc_16M
;* 功能描述：16M晶振设置
;* 输入参数：无
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void hw2000b_set_osc_16M(void)
;{
;    hw2000b_write_reg(0x04, 0x4800);
;    hw2000b_write_reg(0x22, 0x2030);
;    hw2000b_write_reg(0x1C, 0x5198);
;}
;
;/**************************************************************************
;* 函数名称：hw2000b_set_power_max
;* 功能描述：设置发射功率为最大发射功率
;* 输入参数：无
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void hw2000b_set_power_max(void)
;{
;    hw2000b_write_reg(0x4C, 0x55AA);		//open write project
;	hw2000b_write_reg(0x0B, 0x0873);//9
;}
;
;/**************************************************************************
;* 函数名称：hw2000b_set_power_5
;* 功能描述：设置发射功率为5dBm
;* 输入参数：无
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void hw2000b_set_power_5(void)
;{
;    hw2000b_write_reg(0x4C, 0x55AA);        //open write project
;    hw2000b_write_reg(0x0B, 0x085F);
;}
;
;/**************************************************************************
;* 函数名称：hw2000b_set_power_0
;* 功能描述：设置发射功率为0dBm
;* 输入参数：无
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void hw2000b_set_power_0(void)
;{
;    hw2000b_write_reg(0x4C, 0x55AA);		//open write project
;	hw2000b_write_reg(0x0B, 0x0851);
;}
;
;/**************************************************************************
;* 函数名称：hw2000b_set_power_negative_10
;* 功能描述：设置发射功率为-10dBm
;* 输入参数：无
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void hw2000b_set_power_negative_10(void)
;{
;    hw2000b_write_reg(0x4C, 0x55AA);        //open write project
;    hw2000b_write_reg(0x0B, 0x0845); 
;}
;
;/**************************************************************************
;* 函数名称：hw2000b_set_power_negative_20
;* 功能描述：设置发射功率为-20dBm
;* 输入参数：无
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void hw2000b_set_power_negative_20(void)
;{
;    hw2000b_write_reg(0x4C, 0x55AA);		//open write project
;	hw2000b_write_reg(0x0B, 0x0842);
;}
;
;/**************************************************************************
;* 函数名称：hw2000b_set_frequence_2403
;* 功能描述：设置发射频点为2.403GHz
;* 输入参数：无
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void hw2000b_set_frequence_2403(void)
;{
;    hw2000b_write_reg(0x22, 0x1801); //12M OSC
;}
;/**************************************************************************
;* 函数名称：hw2000b_set_frequence_2420
;* 功能描述：设置发射频点为2.420GHz
;* 输入参数：无
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void hw2000b_set_frequence_2420(void)
;{
;    hw2000b_write_reg(0x22, 0x1814); //12M OSC
;}
;/**************************************************************************
;* 函数名称：hw2000b_set_frequence_2450
;* 功能描述：设置发射频点为2.450GHz
;* 输入参数：无
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void hw2000b_set_frequence_2450(void)
;{
;    hw2000b_write_reg(0x22, 0x1830); //12M OSC
;}
;
;/**************************************************************************
;* 函数名称：hw2000b_set_frequence_2460
;* 功能描述：设置发射频点为2.460GHz
;* 输入参数：无
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void hw2000b_set_frequence_2460(void)
;{
;    hw2000b_write_reg(0x22, 0x183C); //12M OSC
;}
;
;/**************************************************************************
;* 函数名称：hw2000b_set_frequence_2483
;* 功能描述：设置发射频点为2.483GHz
;* 输入参数：无
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void hw2000b_set_frequence_2483(void)
;{
;    hw2000b_write_reg(0x22, 0x1851); //12M OSC
;}
;
;
;/**************************************************************************
;* 函数名称：hw2000b_power_test
;* 功能描述：单载波模式，供用户测试功率使用
;* 输入参数：无
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void hw2000b_power_test(void)
;{
;	//发送单载波
;	uint16_t reg_val;
;	reg_val = hw2000b_read_reg(0x1C);
;	hw2000b_write_reg(0x1C, reg_val & 0xFE7F); //寄存器的第7、8位置0  
;	hw2000b_write_reg(0x29, 0x0000); //MCU control  
;	hw2000b_write_reg(0x21, 0x0100); //TX enable	       
;	hw2000b_write_reg(0x36, 0x0081);
;
;	while(1)
;	{
;	;
;	}
;
;}
;
;/**************************************************************************
;* 函数名称：hw2000b_cancel_sw
;* 功能描述：取消单载波模式
;* 输入参数：无
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void hw2000b_cancel_sw(void)
;{
;    uint16_t reg_val;
;    
;    hw2000b_write_reg(0x36, 0x0090);
;    hw2000b_write_reg(0x21, 0x0000); //TX disable
;    hw2000b_write_reg(0x29, 0x1800); //MCU control    
;    hw2000b_write_reg(0x3D, 0x0008); //clear int0
;    reg_val = hw2000b_read_reg(0x1C);
;    hw2000b_write_reg(0x1C, reg_val|0x0180); //bit7 1, bit8 1
;}
;
;/**************************************************************************
;* 函数名称：hw2000b_tx_data
;* 功能描述：发送处理函数
;* 输入参数：uint8_t *data, data[0]是数据长度
;* 返回参数：
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void hw2000b_tx_data(uint8_t *buf, uint16_t size)
;{
;	uint16_t reg;
;	_hw2000b_irq_request = 0;
:0X24e  e783                    CLR             HRAM_0X83
:0X24f  a815                    BCC             HRAM_0X15,      0
;	
;    hw2000b_write_reg(0x21, 0x0100);	//TX enable
:0X250  e521                    MOVI            0X21
:0X251  208e                    MOVAR           HRAM_0X8E
:0X252  e500                    MOVI            0X0
:0X253  208f                    MOVAR           HRAM_0X8F
:0X254  e501                    MOVI            0X1
:0X255  2090                    MOVAR           HRAM_0X90
:0X256  ec00                    PAGE            0X0
:0X257  63b0                    CALL            HADR_0X3B0
:0X258  ec00                    PAGE            0X0
;    delay_us(5);						//delete if lower spi rate,
:0X259  e505                    MOVI            0X5
:0X25a  2089                    MOVAR           HRAM_0X89
:0X25b  e500                    MOVI            0X0
:0X25c  208a                    MOVAR           HRAM_0X8A
:0X25d  ec00                    PAGE            0X0
:0X25e  6454                    CALL            HADR_0X454
:0X25f  ec00                    PAGE            0X0
;	hw2000b_write_reg(0x3B, 0x8000);	//clear TX FIFO
:0X260  e53b                    MOVI            0X3B
:0X261  208e                    MOVAR           HRAM_0X8E
:0X262  e500                    MOVI            0X0
:0X263  208f                    MOVAR           HRAM_0X8F
:0X264  e580                    MOVI            0X80
:0X265  2090                    MOVAR           HRAM_0X90
:0X266  ec00                    PAGE            0X0
:0X267  63b0                    CALL            HADR_0X3B0
:0X268  ec00                    PAGE            0X0
;    hw2000b_write_fifo(0x32, buf, size);//write FIFO
:0X269  e532                    MOVI            0X32
:0X26a  2089                    MOVAR           HRAM_0X89
:0X26b  7885                    MOVRA           HRAM_0X85
:0X26c  208a                    MOVAR           HRAM_0X8A
:0X26d  7886                    MOVRA           HRAM_0X86
:0X26e  208b                    MOVAR           HRAM_0X8B
:0X26f  7887                    MOVRA           HRAM_0X87
:0X270  2085                    MOVAR           HRAM_0X85
:0X271  7885                    MOVRA           HRAM_0X85
:0X272  208c                    MOVAR           HRAM_0X8C
:0X273  ec00                    PAGE            0X0
:0X274  6407                    CALL            HADR_0X407
:0X275  ec00                    PAGE            0X0
;	reg = hw2000b_read_reg(0x36);
:0X276  e536                    MOVI            0X36
:0X277  2089                    MOVAR           HRAM_0X89
:0X278  ec00                    PAGE            0X0
:0X279  63d7                    CALL            HADR_0X3D7
:0X27a  ec00                    PAGE            0X0
:0X27b  2085                    MOVAR           HRAM_0X85
:0X27c  5008                    MOV             HRAM_0X8,       A
:0X27d  2086                    MOVAR           HRAM_0X86
;	hw2000b_write_reg(0x36, 0x0081|reg);//FIFO0 occupy
:0X27e  e536                    MOVI            0X36
:0X27f  208e                    MOVAR           HRAM_0X8E
:0X280  7885                    MOVRA           HRAM_0X85
:0X281  e181                    IORI            0X81
:0X282  2087                    MOVAR           HRAM_0X87
:0X283  7886                    MOVRA           HRAM_0X86
:0X284  e100                    IORI            0X0
:0X285  2088                    MOVAR           HRAM_0X88
:0X286  7887                    MOVRA           HRAM_0X87
:0X287  208f                    MOVAR           HRAM_0X8F
:0X288  7888                    MOVRA           HRAM_0X88
:0X289  2090                    MOVAR           HRAM_0X90
:0X28a  ec00                    PAGE            0X0
:0X28b  63b0                    CALL            HADR_0X3B0
:0X28c  ec00                    PAGE            0X0
;    hw2000b_write_reg(0x37, 0x0000);	//FIFO1 disable
:0X28d  e537                    MOVI            0X37
:0X28e  208e                    MOVAR           HRAM_0X8E
:0X28f  e500                    MOVI            0X0
:0X290  208f                    MOVAR           HRAM_0X8F
:0X291  e500                    MOVI            0X0
:0X292  2090                    MOVAR           HRAM_0X90
:0X293  ec00                    PAGE            0X0
:0X294  63b0                    CALL            HADR_0X3B0
:0X295  ec00                    PAGE            0X0
HADR_0X296:
;
;	while (!_hw2000b_irq_request);
:0X296  9015                    JBS             HRAM_0X15,      0
:0X297  6a96                    GOTO            HADR_0X296
;	
;	reg = hw2000b_read_reg(0x36);
:0X298  e536                    MOVI            0X36
:0X299  ea01                    SECTION         0X1
:0X29a  e609                    MOVA            HRAM_0X9
:0X29b  ec00                    PAGE            0X0
:0X29c  63d7                    CALL            HADR_0X3D7
:0X29d  ec00                    PAGE            0X0
:0X29e  2085                    MOVAR           HRAM_0X85
:0X29f  5008                    MOV             HRAM_0X8,       A
:0X2a0  2086                    MOVAR           HRAM_0X86
;    if ((reg & 0x8000) == 0x8000)		//rtx fail
:0X2a1  7885                    MOVRA           HRAM_0X85
:0X2a2  e200                    ANDI            0X0
:0X2a3  2087                    MOVAR           HRAM_0X87
:0X2a4  7886                    MOVRA           HRAM_0X86
:0X2a5  e280                    ANDI            0X80
:0X2a6  2088                    MOVAR           HRAM_0X88
:0X2a7  7887                    MOVRA           HRAM_0X87
:0X2a8  e300                    XORI            0X0
:0X2a9  9284                    JBS             HRAM_0X84,      2
:0X2aa  6ab0                    GOTO            HADR_0X2B0
:0X2ab  ea01                    SECTION         0X1
:0X2ac  5008                    MOV             HRAM_0X8,       A
:0X2ad  e380                    XORI            0X80
:0X2ae  9a84                    JBC             HRAM_0X84,      2
:0X2af  6acb                    GOTO            HADR_0X2CB
HADR_0X2B0:
;	{
;		//_ack_count--;					//添加重发超时处理代码
;	}
;	else
;	{	//ack mode:recieve ack    no ack mode:tx success
;		if((hw2000b_read_reg(0x3C) & 0x000F) != 0)	//recieve ack
:0X2b0  e53c                    MOVI            0X3C
:0X2b1  ea01                    SECTION         0X1
:0X2b2  e609                    MOVA            HRAM_0X9
:0X2b3  ec00                    PAGE            0X0
:0X2b4  63d7                    CALL            HADR_0X3D7
:0X2b5  ec00                    PAGE            0X0
:0X2b6  2085                    MOVAR           HRAM_0X85
:0X2b7  5008                    MOV             HRAM_0X8,       A
:0X2b8  2086                    MOVAR           HRAM_0X86
:0X2b9  7885                    MOVRA           HRAM_0X85
:0X2ba  e20f                    ANDI            0XF
:0X2bb  2087                    MOVAR           HRAM_0X87
:0X2bc  7886                    MOVRA           HRAM_0X86
:0X2bd  e200                    ANDI            0X0
:0X2be  2088                    MOVAR           HRAM_0X88
:0X2bf  ea01                    SECTION         0X1
:0X2c0  5007                    MOV             HRAM_0X7,       A
:0X2c1  5808                    IOR             HRAM_0X8,       A
:0X2c2  9a84                    JBC             HRAM_0X84,      2
:0X2c3  6ac9                    GOTO            HADR_0X2C9
;			{_ack_count++;}
:0X2c4  551b                    INC             HRAM_0X1B,      R
:0X2c5  9284                    JBS             HRAM_0X84,      2
:0X2c6  6ac8                    GOTO            HADR_0X2C8
:0X2c7  551c                    INC             HRAM_0X1C,      R
HADR_0X2C8:
:0X2c8  6acb                    GOTO            HADR_0X2CB
HADR_0X2C9:
;		else
:0X2c9  e71b                    CLR             HRAM_0X1B
:0X2ca  e71c                    CLR             HRAM_0X1C
HADR_0X2CB:
;	}
:0X2cb  e536                    MOVI            0X36
:0X2cc  e60e                    MOVA            HRAM_0XE
:0X2cd  e580                    MOVI            0X80
:0X2ce  e60f                    MOVA            HRAM_0XF
:0X2cf  e500                    MOVI            0X0
:0X2d0  e610                    MOVA            HRAM_0X10
:0X2d1  ec00                    PAGE            0X0
:0X2d2  63b0                    CALL            HADR_0X3B0
:0X2d3  ec00                    PAGE            0X0
;	hw2000b_write_reg(0x3D, 0x0008);	//clear int0
:0X2d4  e53d                    MOVI            0X3D
:0X2d5  208e                    MOVAR           HRAM_0X8E
:0X2d6  e508                    MOVI            0X8
:0X2d7  208f                    MOVAR           HRAM_0X8F
:0X2d8  e500                    MOVI            0X0
:0X2d9  2090                    MOVAR           HRAM_0X90
:0X2da  ec00                    PAGE            0X0
:0X2db  63b0                    CALL            HADR_0X3B0
:0X2dc  ec00                    PAGE            0X0
;	hw2000b_write_reg(0x21, 0x0000);	//TX disable
:0X2dd  e521                    MOVI            0X21
:0X2de  208e                    MOVAR           HRAM_0X8E
:0X2df  e500                    MOVI            0X0
:0X2e0  208f                    MOVAR           HRAM_0X8F
:0X2e1  e500                    MOVI            0X0
:0X2e2  2090                    MOVAR           HRAM_0X90
:0X2e3  ec00                    PAGE            0X0
:0X2e4  63b0                    CALL            HADR_0X3B0
:0X2e5  ec00                    PAGE            0X0
;	//hw2000b_write_reg(0x23, 0x431B); //Soft reset			//会增加功耗
;	//hw2000b_write_reg(0x23, 0x031B); 
;	//delay_us(20);//delete if lower spi rate,
;}
:0X2e6  c183                    RET
HADR_0X2E7:
;
;/**************************************************************************
;* 函数名称：hw2000b_rx_enable
;* 功能描述：接收使能
;* 输入参数：无
;* 返回参数：
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void hw2000b_rx_enable(void)
;{
;	hw2000b_write_reg(0x3D, 0x0008);
;	hw2000b_write_reg(0x21, 0x0000);
;	hw2000b_write_reg(0x36, 0x0080);
;	hw2000b_write_reg(0x37, 0x0000);
;	hw2000b_write_reg(0x21, 0x0080);
;}
;
;/**************************************************************************
;* 函数名称：hw2000b_rx_data
;* 功能描述：接收函数
;* 输入参数：data
;* 返回参数：0 success -1 failed
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;int8_t hw2000b_rx_data(uint8_t *data)
;{
;	uint16_t reg;
;
;	if(_hw2000b_irq_request){
;		_hw2000b_irq_request = 0;
;
;		reg = hw2000b_read_reg(0x36);
;		if ((reg & 0x2000) == 0){	//crc校验成功
;			hw2000b_read_fifo(0x32, data, 1); //将接收数据放到_data中
;			hw2000b_read_fifo(0x32, &data[1], data[0]); //将接收数据放到_data中
;		} else {
;			hw2000b_write_reg(0x3D, 0x0008); // 清INT0控制位
;			return -1;
;		}
;
;		hw2000b_write_reg(0x3D, 0x0008); // 清INT0控制位
;		//hw2000b_write_reg(0x21, 0x0000); //RX disable
;		return 0;
;	} else {
;		return -1;
;	}
;}
;
;/**************************************************************************
;* 函数名称：hw2000b_power_down
;* 功能描述：hw2000b进入power down
;* 输入参数：无
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void hw2000b_power_down(void)
;{
;	uint16_t reg_value;
;	
;	hw2000b_write_reg(0x21, 0x0000); // TX RX disable
:0X2e7  e783                    CLR             HRAM_0X83
:0X2e8  e521                    MOVI            0X21
:0X2e9  ea01                    SECTION         0X1
:0X2ea  e60e                    MOVA            HRAM_0XE
:0X2eb  e500                    MOVI            0X0
:0X2ec  e60f                    MOVA            HRAM_0XF
:0X2ed  e500                    MOVI            0X0
:0X2ee  e610                    MOVA            HRAM_0X10
:0X2ef  ec00                    PAGE            0X0
:0X2f0  63b0                    CALL            HADR_0X3B0
:0X2f1  ec00                    PAGE            0X0
;	reg_value = hw2000b_read_reg(0x23);
:0X2f2  e523                    MOVI            0X23
:0X2f3  2089                    MOVAR           HRAM_0X89
:0X2f4  ec00                    PAGE            0X0
:0X2f5  63d7                    CALL            HADR_0X3D7
:0X2f6  ec00                    PAGE            0X0
:0X2f7  2085                    MOVAR           HRAM_0X85
:0X2f8  5008                    MOV             HRAM_0X8,       A
:0X2f9  2086                    MOVAR           HRAM_0X86
;	hw2000b_write_reg(0x23, 0x8080 | reg_value);	//0x23寄存器第【15】位置1
:0X2fa  e523                    MOVI            0X23
:0X2fb  208e                    MOVAR           HRAM_0X8E
:0X2fc  7885                    MOVRA           HRAM_0X85
:0X2fd  e180                    IORI            0X80
:0X2fe  2087                    MOVAR           HRAM_0X87
:0X2ff  7886                    MOVRA           HRAM_0X86
:0X300  e180                    IORI            0X80
:0X301  2088                    MOVAR           HRAM_0X88
:0X302  7887                    MOVRA           HRAM_0X87
:0X303  208f                    MOVAR           HRAM_0X8F
:0X304  7888                    MOVRA           HRAM_0X88
:0X305  2090                    MOVAR           HRAM_0X90
:0X306  ec00                    PAGE            0X0
:0X307  63b0                    CALL            HADR_0X3B0
:0X308  ec00                    PAGE            0X0
;
;}
:0X309  c183                    RET
HADR_0X30A:
;
;/**************************************************************************
;* 函数名称：hw2000b_power_on
;* 功能描述：hw2000b从power down唤醒
;* 输入参数：无
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void hw2000b_power_on(void)
;{
;	uint16_t reg_value;
;	
;	reg_value = hw2000b_read_reg(0x23);
:0X30a  e783                    CLR             HRAM_0X83
:0X30b  e523                    MOVI            0X23
:0X30c  ea01                    SECTION         0X1
:0X30d  e609                    MOVA            HRAM_0X9
:0X30e  ec00                    PAGE            0X0
:0X30f  63d7                    CALL            HADR_0X3D7
:0X310  ec00                    PAGE            0X0
:0X311  2085                    MOVAR           HRAM_0X85
:0X312  5008                    MOV             HRAM_0X8,       A
:0X313  2086                    MOVAR           HRAM_0X86
;	hw2000b_write_reg(0x23, 0x7F7F & reg_value);	//0x23寄存器第【15】位置0
:0X314  e523                    MOVI            0X23
:0X315  208e                    MOVAR           HRAM_0X8E
:0X316  7885                    MOVRA           HRAM_0X85
:0X317  e27f                    ANDI            0X7F
:0X318  2087                    MOVAR           HRAM_0X87
:0X319  7886                    MOVRA           HRAM_0X86
:0X31a  e27f                    ANDI            0X7F
:0X31b  2088                    MOVAR           HRAM_0X88
:0X31c  7887                    MOVRA           HRAM_0X87
:0X31d  208f                    MOVAR           HRAM_0X8F
:0X31e  7888                    MOVRA           HRAM_0X88
:0X31f  2090                    MOVAR           HRAM_0X90
:0X320  ec00                    PAGE            0X0
:0X321  63b0                    CALL            HADR_0X3B0
:0X322  ec00                    PAGE            0X0
;
;	delay_ms(1);
:0X323  e501                    MOVI            0X1
:0X324  2089                    MOVAR           HRAM_0X89
:0X325  e500                    MOVI            0X0
:0X326  208a                    MOVAR           HRAM_0X8A
:0X327  ec00                    PAGE            0X0
:0X328  6437                    CALL            HADR_0X437
:0X329  ec00                    PAGE            0X0
;
;	hw2000b_write_reg(0x23, 0x431B); //Soft reset			//会增加功耗
:0X32a  e523                    MOVI            0X23
:0X32b  208e                    MOVAR           HRAM_0X8E
:0X32c  e51b                    MOVI            0X1B
:0X32d  208f                    MOVAR           HRAM_0X8F
:0X32e  e543                    MOVI            0X43
:0X32f  2090                    MOVAR           HRAM_0X90
:0X330  ec00                    PAGE            0X0
:0X331  63b0                    CALL            HADR_0X3B0
:0X332  ec00                    PAGE            0X0
;	hw2000b_write_reg(0x23, 0x031B); 	
:0X333  e523                    MOVI            0X23
:0X334  208e                    MOVAR           HRAM_0X8E
:0X335  e51b                    MOVI            0X1B
:0X336  208f                    MOVAR           HRAM_0X8F
:0X337  e503                    MOVI            0X3
:0X338  2090                    MOVAR           HRAM_0X90
:0X339  ec00                    PAGE            0X0
:0X33a  63b0                    CALL            HADR_0X3B0
:0X33b  ec00                    PAGE            0X0
;	delay_us(20);
:0X33c  e514                    MOVI            0X14
:0X33d  2089                    MOVAR           HRAM_0X89
:0X33e  e500                    MOVI            0X0
:0X33f  208a                    MOVAR           HRAM_0X8A
:0X340  ec00                    PAGE            0X0
:0X341  6454                    CALL            HADR_0X454
:0X342  ec00                    PAGE            0X0
;	hw2000b_init_250k();
:0X343  ec00                    PAGE            0X0
:0X344  614e                    CALL            HADR_0X14E
:0X345  ec00                    PAGE            0X0
;}
:0X346  c183                    RET
HADR_0X347:
;/**************************************************************************
;* 版权声明：Copyright@2019 上海东软载波微电子有限公司
;* 文件名称：io.c
;* 功能描述：io管脚
;* 函数列表：io_init
;* 文件作者：Ljj  
;* 文件版本： 
;* 完成日期：2023-08-23	
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;#include <hic.h>
;#include "io.h"
;
;/**************************************************************************
;* 函数名称：io_init
;* 功能描述：初始化IO
;* 输入参数：无
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/ 
;void GPIOInit(void)
;{
;	//PA0 PINT0, PA1 RX，PA2 TX， PA3 MRST，PA4 EN，PA5 ISPDA,   PA6 NC， PA7 NC
;	//PB0 PB0 NC,  PB1 NC，  PB2 NC，PB3 HW2000B_IRQ        PB4 HW2000B_SCK，PB5 HW2000B_MOSI，PB6 HW2000B_MISO，PB7 HW2000B_CE
;	//PC0 HW2000B_CSN，         PC1 ISPCK
;	ANSL = 0xFF;        //选择对应端口为数字IO功能
:0X347  e783                    CLR             HRAM_0X83
:0X348  e5ff                    MOVI            0XFF
:0X349  e6bc                    MOVA            HRAM_0XBC
;	ANSH = 0xFF;        //选择对应端口为数字IO功能
:0X34a  e5ff                    MOVI            0XFF
:0X34b  e68d                    MOVA            HRAM_0X8D
;
;    PAT = 0x0B;         //PA2 4 5 6 7输出，PA0 1 3输入  PINT0、RX0、MRST
:0X34c  e50b                    MOVI            0XB
:0X34d  e6ad                    MOVA            HRAM_0XAD
;    PBT = 0x48;			//PB0 1 2 4 5 7输出，PB3 6输入  IRQ、MISO
:0X34e  e548                    MOVI            0X48
:0X34f  e6ae                    MOVA            HRAM_0XAE
;    PCT = 0x00;			//PC0 1输出
:0X350  e7af                    CLR             HRAM_0XAF
;
;    PA = 0x00;
:0X351  e7a8                    CLR             HRAM_0XA8
;    PB = 0x00;
:0X352  e7a9                    CLR             HRAM_0XA9
;    PC = 0x00;
:0X353  e7aa                    CLR             HRAM_0XAA
;
;	PAPU = 0;		//禁止弱上拉
:0X354  e7b2                    CLR             HRAM_0XB2
;
;	KMSK4 = 1;   //KINT4取消屏蔽
:0X355  a4a3                    BSS             HRAM_0XA3,      4
;	INTF0 = 0x00;	//清除中断标志
:0X356  e79a                    CLR             HRAM_0X9A
;	INTE0 |= 0x10;	//使能KIE
:0X357  a499                    BSS             HRAM_0X99,      4
;
;}
:0X358  c183                    RET
HADR_0X359:
;/**************************************************************************
;* 版权声明：Copyright@2019 上海东软载波微电子有限公司
;* 文件名称：main.c
;* 功能描述：	
;* 函数列表：
;* 文件作者：Ljj  
;* 文件版本： 
;* 完成日期：2023-08-23	
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;#include <hic.h>
;#include "string.h" 
;#include "io.h"
;#include "hw2000b.h"
;#include "timer.h"
;#include "ram.h"
;#include "spi.h"
;
;#define CLRWDT()   {__Asm CWDT;}        //宏定义清狗指令
;
;uint16_t	_ack_count;
;sbit		_hw2000b_irq_request;	//射频中断标志
;sbit		rx_ok;
;
;uint8_t sleep_flag = 0;
;uint8_t RX_OK_flag = 0;
;
;uint8_t rxbuf[40];
;
;uint8_t timer_cnt;
;
;#define STARTADDR    0xC000     //宏定义数据区IAP操作起始地址
;#define ENDADDR      0xC002     //宏定义数据区IAP操作结束地址
;#define WRDATA       0x87654321     //宏定义待写入数据
;
;#define DATA_1_ADDR	0xC000
;#define DATA_2_ADDR	0xC001
;#define DATA_3_ADDR	0xC002
;
;uint8_t dataerr = 0;      //0：写入与读出相等，1：写入与读出不等
;
;uint8_t CallFlashEn,FlashEwEn;//软件锁变量
;
;
;static volatile unsigned int section8 FRAN @ 0xFF8E;
;static volatile unsigned int section8 FRA  @ 0xFF90;
;
;/******************************************************
;函数名：void StartIAP(void)
;描  述：开始IAP操作。注意：IAP固定操作格式，使用时不可改变
;输入值：无
;输出值：无
;返回值：无
;*******************************************************/
;void StartIAP(void)
;{
;    __asm{
;          MOVI 0x55
;          MOVA ROMCH
;          MOVI 0xFF     //8个NOP代替语句开始
;          SECSEL &FlashEwEn& % 0x80//选择变量所在的section
;          XOR &FlashEwEn& % 0x80,0//0xFF xor 0xAA = 0x55
;          SECSEL &CallFlashEn& % 0x80//选择变量所在的section
;          XOR &CallFlashEn& % 0x80,0//若CallFlashEn在调用函数前为0x55，0x55 xor 0x55 = 0x00
;          JBS PSW,Z//如果运算结果为0x00，则执行正确，跳至下一个NOP
;          GOTO $+3
;          NOP//8个NOP代替语句结束
;          MOVI 0xAA
;          MOVA ROMCH
;          MOVI 0xFF     //8个NOP代替语句开始
;          SECSEL &FlashEwEn& % 0x80//选择变量所在的section
;          XOR &FlashEwEn& % 0x80,0//0xFF xor 0xAA = 0x55
;          SECSEL &CallFlashEn& % 0x80//选择变量所在的section
;          XOR &CallFlashEn& % 0x80,0//若CallFlashEn在调用函数前为0x55，0x55 xor 0x55 = 0x00
;          JBS PSW,Z//如果运算结果为0x00，则执行正确，跳至下一个NOP
;          GOTO $+3
;          NOP//8个NOP代替语句结束
;          BSS ROMCL,WR     //触发编程操作
;          JBC ROMCL,WR
;          goto $-1         //等待操作结束
;        }
;}
;
;/*******************************************************
;函数名：void DataFlashErsPage(void)
;描  述：擦除DataFlash整页(256 word)，地址范围：0xC000~0xC1FF
;输入值：DataFlash地址addr，DataFlash取反地址addri
;输出值：无
;返回值：无
;*******************************************************/
;void DataFlashErsPage(unsigned int addr, unsigned int addri)
;{
;	unsigned char gie_bk = GIE;		//备份GIE
;    CLRWDT();
;	while(GIE == 1)GIE = 0;            //启动IAP前关闭全局中断
;	FlashEwEn = 0xAA;//设置软件锁变量
;
;    FPEE = 1;           //存储器擦除模式
;    FRAH = addr>>8;
;    FRAL = addr;
;    FRAHN = addri>>8;      //IAP擦除/编程必须满足地址取反逻辑
;    FRALN = addri;     
;
;    WREN = 1;           //使能擦除/编程功能
;    StartIAP();         //开始IAP操作
;	CallFlashEn = 0;//清零软件锁变量
;	FlashEwEn = 0;
;    ROMCL = 0x00;       //退出IAP
;	FRA = 0xFF12;//指到不用的地址空间
;	FRAN = 0x3456;//此处把地址反码赋成与0xFFFF和FRA无取反关系的值
;	GIE = gie_bk;       //恢复全局中断
;}
;
;/*******************************************************
;函数名：unsigned long DataFlashRdData(unsigned int addr)
;描  述：读Flash指定地址的数据
;输入值：DataFlash地址addr，地址范围：0xC000~0xC1FF
;输出值：无
;返回值：DataFlash指定地址的数据
;*******************************************************/
;unsigned long DataFlashRdData(unsigned int addr)
;{
;	unsigned long data;
;	unsigned char gie_bk = GIE;	  //备份GIE
;    CLRWDT();
;	while(GIE == 1)GIE = 0;
;    FRAL = addr;
;    FRAH = addr>>8;
;	DATARDTRG=1;
;	while(DATARDTRG);
;	DATARDEN=1;         //DATA区读出使能
;    __Asm TBR;          //查表读指令
;    data = ((unsigned long)ROMD1H<<24) | ((unsigned long)ROMD1L<<16) | ((unsigned long)ROMDH<<8) | ROMDL;
;	DATARDEN=0;         //DATA区读出禁止
;    GIE = gie_bk;       //恢复全局中断
;	return data;
;}
;
;/*******************************************************
;函数名：void DataFlashWrData(unsigned int addr, unsigned long word)
;描  述：写DataFlash指定地址的数据，地址范围：0xC000~0xC1FF
;输入值：DataFlash地址addr，DataFlash取反地址addri，待写的数据word
;输出值：无
;返回值：0:写入失败，1:写入成功
;*******************************************************/
;unsigned char DataFlashWrData(unsigned int addr, unsigned int addri, unsigned long word)
;{
;    unsigned char rmdh,rmdl,rmd1h,rmd1l;      //临时存放ROMDH、ROMDL值
;	unsigned char gie_bk = GIE;	  //备份GIE
;    CLRWDT();
;	while(GIE == 1)GIE = 0;            //启动IAP前关闭全局中断
;	FlashEwEn = 0xAA;//设置软件锁变量
;
;    FPEE = 0;           //存储器编程模式
;    ROMD1H = word>>24;    //写Word
;    ROMD1L = word>>16;
;    ROMDH = word>>8;
;    ROMDL = word;
;    FRAH = addr>>8;     //IAP编程地址
;    FRAL = addr;
;    FRAHN = addri>>8;      //IAP擦除/编程必须满足地址取反逻辑
;    FRALN = addri;       
;
;    WREN = 1;           //使能编程
;    StartIAP();         //开始IAP操作
;	CallFlashEn = 0;//清零软件锁变量
;	FlashEwEn = 0;
;    rmdh = ROMDH++;
;    rmdl = ROMDL++;
;    rmd1h = ROMD1H++;
;    rmd1l = ROMD1L++;
;	DATARDEN=1;      //DATA区读出使能
;    FRAH = addr>>8;
;    FRAL = addr;
;	DATARDTRG=1;     //DATA区读出触发
;	while(DATARDTRG);
;    __Asm TBR;          //查表读指令
;    if (ROMDH!=rmdh || ROMDL!=rmdl || ROMD1H!=rmd1h || ROMD1L!=rmd1l)
;	{
;        ROMCL = 0x00;       //退出IAP
;		return 0;
;	}
;	FRA = 0xFF12;//指到不用的地址空间
;	FRAN = 0x3456;//此处把地址反码赋成与0xFFFF和FRA无取反关系的值
;	ROMDH = 0xFF;//数据初始化为0xFF
;	ROMDL = 0xFF;//数据初始化为0xFF
;	ROMD1H = 0xFF;//数据初始化为0xFF
;	ROMD1L = 0xFF;//数据初始化为0xFF
;    ROMCL = 0x00;       //退出IAP
;	DATARDEN=0;   //DATA区读出禁止
;	GIE = gie_bk;       //恢复全局中断
;    return 1;
;}
;
;void Delay_20us(unsigned int a)
;{
;	uint16_t i;
;
;	for(;a>0;a--)
;	{
;        for(i = 0;i<10;i++);
;	}
;}
;
;/**********************************************
;函数名：void sleep(void)
;描  述：进入IDLE模式
;输入值：无
;输出值：无
;返回值：无
;**********************************************/
;void sleep(void)
;{
;	T8NEN = 0;				//禁能T8N
:0X359  e783                    CLR             HRAM_0X83
:0X35a  afbe                    BCC             HRAM_0XBE,      7
;    RX0EN = 0;				//禁能串口接收
:0X35b  a483                    BSS             HRAM_0X83,      4
:0X35c  afd0                    BCC             HRAM_0XD0,      7
;
;	INTC0 = 0xFF;			//PINT0-双沿中断
:0X35d  e5ff                    MOVI            0XFF
:0X35e  e698                    MOVA            HRAM_0X98
;	PIE0 = 1;				//打开PINT0管脚中断
:0X35f  a09b                    BSS             HRAM_0X9B,      0
;    PIF0 = 0;				//睡眠前清中断标志位
:0X360  a89c                    BCC             HRAM_0X9C,      0
;
;	KMSK4 = 0;				//KINT4屏蔽
:0X361  aca3                    BCC             HRAM_0XA3,      4
;	INTF0 = 0x00;			//清除中断标志
:0X362  e79a                    CLR             HRAM_0X9A
;	INTE0 = 0x00;			//禁能KIE
:0X363  e799                    CLR             HRAM_0X99
;
;	GIE = 0;				//关闭总中断
:0X364  af96                    BCC             HRAM_0X96,      7
;
;							
;	PWEN &= 0xFD;			//禁止IDLE状态下计数
:0X365  a9a7                    BCC             HRAM_0XA7,      1
;	WKDC = 0x1F;
:0X366  e51f                    MOVI            0X1F
:0X367  e6a6                    MOVA            HRAM_0XA6
;	PWRC = 0x8F;			//选择IDLE模式
:0X368  e58f                    MOVI            0X8F
:0X369  e6b6                    MOVA            HRAM_0XB6
;    __Asm IDLE;				//进入IDLE模式
:0X36a  c18a                    IDLE
;
;	GIE = 1;				//打开总中断
:0X36b  a796                    BSS             HRAM_0X96,      7
;
;	KMSK4 = 1;				//KINT4取消屏蔽
:0X36c  a4a3                    BSS             HRAM_0XA3,      4
;	INTF0 = 0x00;			//清除中断标志
:0X36d  e79a                    CLR             HRAM_0X9A
;	INTE0 |= 0x10;			//使能KIE
:0X36e  a499                    BSS             HRAM_0X99,      4
;
;	INTC0 = 0xFF;			//PINT0-双沿中断
:0X36f  e5ff                    MOVI            0XFF
:0X370  e698                    MOVA            HRAM_0X98
;	PIE0 = 0;				//关闭PINT0管脚中断
:0X371  a89b                    BCC             HRAM_0X9B,      0
;    PIF0 = 0;				//睡眠前清中断标志位
:0X372  a89c                    BCC             HRAM_0X9C,      0
;
;	T8NIE = 1;				//打开定时器溢出中断
:0X373  a199                    BSS             HRAM_0X99,      1
;	T8NIF = 0;				//清标志位
:0X374  a99a                    BCC             HRAM_0X9A,      1
;	T8N = 131;				//赋计数器初值   2ms
:0X375  e583                    MOVI            0X83
:0X376  e6bd                    MOVA            HRAM_0XBD
;	T8NEN = 1;				//使能T8N
:0X377  a7be                    BSS             HRAM_0XBE,      7
;
;	timer_cnt = 250;
:0X378  e5fa                    MOVI            0XFA
:0X379  ea01                    SECTION         0X1
:0X37a  e618                    MOVA            HRAM_0X18
;
;	RX0EN = 1;			//使能串口接收
:0X37b  a7d0                    BSS             HRAM_0XD0,      7
;}
:0X37c  ea00                    SECTION         0X0
:0X37d  ac83                    BCC             HRAM_0X83,      4
:0X37e  c183                    RET
HADR_0X37F:
;
;
;void WDT_Init(void)
;{
;    WDTC = 0x16;         //分频比1:128，使能WDT预分频器，看门狗溢出时间t=256*128/32000=1.024s
:0X37f  e783                    CLR             HRAM_0X83
:0X380  e516                    MOVI            0X16
:0X381  e6a4                    MOVA            HRAM_0XA4
;    PWEN &= 0xFD;
:0X382  a9a7                    BCC             HRAM_0XA7,      1
;    PWEN |= 0<<1;		//禁止IDLE状态下计数
;}
:0X383  c183                    RET
HADR_0X384:
;
;void UART_Init(void)
;{
;    RX0LEN = 0;     //8位数据接收格式
:0X384  e783                    CLR             HRAM_0X83
:0X385  a483                    BSS             HRAM_0X83,      4
:0X386  aed0                    BCC             HRAM_0XD0,      6
;    TX0LEN = 0;     //8位数据发送格式
:0X387  aed2                    BCC             HRAM_0XD2,      6
;	//BJT0EN = 1;		//波特率去抖使能
;    //BRGH0 = 0;      //波特率低速模式：波特率=Fosc/(64*BRRDIV))
;    //BR0R = 0xD0;    //波特率整数部分=16MHz/(64*1200bps)=208.3333
;	//BR0FRA = 0x05;	//波特率小数部分=16*0.3333 ≈ 5
;
;    //BRGH0 = 0;      //波特率低速模式：波特率=Fosc/(64*(BRR<7:0>+1))
;    //BR0R = 0x19;    //波特率=16MHz/(64*(25+1))≈9600bps
;
;    BRGH0 = 0;      //波特率低速模式：波特率=Fosc/(64*(BRR<7:0>+1))
:0X388  add2                    BCC             HRAM_0XD2,      5
;    BR0R = 0x33;    //波特率=16MHz/(64*(51+1))≈4800bps
:0X389  e533                    MOVI            0X33
:0X38a  e6d3                    MOVA            HRAM_0XD3
;
;	RX0TXEN = 1;		//串口管脚交互，RX0=0 ,TX0=1
:0X38b  a4d0                    BSS             HRAM_0XD0,      4
;
;	RX0IE = 1;			//接收中断
:0X38c  a19d                    BSS             HRAM_0X9D,      1
;	//RX0EN = 1;          //打开串口接收
;}
:0X38d  ac83                    BCC             HRAM_0X83,      4
:0X38e  c183                    RET
HADR_0X38F:
;
;void TIME_Init(void)
;{
;    T8NC = 0x0E;         //定时器模式，预分频1:(Fosc/2)/128
:0X38f  e783                    CLR             HRAM_0X83
:0X390  e50e                    MOVI            0XE
:0X391  e6be                    MOVA            HRAM_0XBE
;    T8N = 131;           //赋计数器初值   2ms
:0X392  e583                    MOVI            0X83
:0X393  e6bd                    MOVA            HRAM_0XBD
;    T8NIE = 1;           //打开定时器溢出中断
:0X394  a199                    BSS             HRAM_0X99,      1
;    T8NIF = 0;           //清溢出标志位
:0X395  a99a                    BCC             HRAM_0X9A,      1
;
;    T8NEN = 1;           //使能T8N
:0X396  a7be                    BSS             HRAM_0XBE,      7
;
;	timer_cnt = 250;	 //
:0X397  e5fa                    MOVI            0XFA
:0X398  ea01                    SECTION         0X1
:0X399  e618                    MOVA            HRAM_0X18
;}
:0X39a  ea00                    SECTION         0X0
:0X39b  c183                    RET
HADR_0X39C:
;/**************************************************************************
;* 版权声明：Copyright@2019 上海东软载波微电子有限公司
;* 文件名称：spi.c
;* 功能描述：spi通讯函数
;* 函数列表：spi_init			
;* 文件作者：Ljj  
;* 文件版本： 
;* 完成日期：2023-08-23	
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;#include <hic.h>
;#include "type.h"
;#include "spi.h"
;
;#define		CSN_0()		CSN = 0
;#define		CSN_1()		CSN = 1
;
;uint8_t		val_h, val_l;
;
;/**************************************************************************
;* 函数名称：spi_init
;* 功能描述：初始化spi
;* 输入参数：无
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void spi_init(void)
;{
;	TCSN = 0;
:0X39c  e783                    CLR             HRAM_0X83
:0X39d  a8af                    BCC             HRAM_0XAF,      0
;	TSCK = 0;
:0X39e  acae                    BCC             HRAM_0XAE,      4
;	TMOSI = 0;
:0X39f  adae                    BCC             HRAM_0XAE,      5
;	TMISO = 1;
:0X3a0  a6ae                    BSS             HRAM_0XAE,      6
;
;	CSN = 1;
:0X3a1  a0aa                    BSS             HRAM_0XAA,      0
;	SCK = 0;
:0X3a2  aca9                    BCC             HRAM_0XA9,      4
;	MOSI = 0;
:0X3a3  ada9                    BCC             HRAM_0XA9,      5
;
;	SPIRST = 1;			//复位SPI
:0X3a4  a483                    BSS             HRAM_0X83,      4
:0X3a5  a1c1                    BSS             HRAM_0XC1,      1
HADR_0X3A6:
;    while(SPIRST);
:0X3a6  99c1                    JBC             HRAM_0XC1,      1
:0X3a7  6ba6                    GOTO            HADR_0X3A6
;    SPICON0 = 0xF0;     //CKS = Fosc/4 = 32/8 = 4MHz，清空发送器、接收器，字节读写 0xF0:Fosc/16 0xE0:Fosc/8 0xD0:Fosc/4 0xC0:Fosc/2
:0X3a8  e5f0                    MOVI            0XF0
:0X3a9  e6c0                    MOVA            HRAM_0XC0
;    SPICON1 = 0x00;      //0:上升沿发送（先），下降沿接收（后）；
:0X3aa  e7c1                    CLR             HRAM_0XC1
;    MS = 0;				//0：主机模式，1：从机模式
:0X3ab  aac1                    BCC             HRAM_0XC1,      2
;    RBIE = 0;			//关闭接收中断	
:0X3ac  a9c2                    BCC             HRAM_0XC2,      1
;    SPIEN = 1;			//SPI使能
:0X3ad  a0c1                    BSS             HRAM_0XC1,      0
;}
:0X3ae  ac83                    BCC             HRAM_0X83,      4
:0X3af  c183                    RET
HADR_0X3B0:
;
;/**************************************************************************
;* 函数名称：hw2000b_write_reg
;* 功能描述：写hw2000b寄存器
;* 输入参数：addr  寄存器地址
;            value 寄存器值
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void hw2000b_write_reg(uint8_t addr, uint16_t data)
;{
;	addr |= 0x80;
:0X3b0  e783                    CLR             HRAM_0X83
:0X3b1  ea01                    SECTION         0X1
:0X3b2  a70e                    BSS             HRAM_0XE,       7
;	REN = 0;        //关闭接收
:0X3b3  a483                    BSS             HRAM_0X83,      4
:0X3b4  abc1                    BCC             HRAM_0XC1,      3
;
;	CSN_0();
:0X3b5  a8aa                    BCC             HRAM_0XAA,      0
;	SPITBW = addr;
:0X3b6  500e                    MOV             HRAM_0XE,       A
:0X3b7  e6c5                    MOVA            HRAM_0XC5
HADR_0X3B8:
;    while(!TBIF);
:0X3b8  90c3                    JBS             HRAM_0XC3,      0
:0X3b9  6bb8                    GOTO            HADR_0X3B8
;	SPITBW = data>>8;
:0X3ba  e508                    MOVI            0X8
:0X3bb  e001                    ADDI            0X1
:0X3bc  ea00                    SECTION         0X0
:0X3bd  e607                    MOVA            HRAM_0X7
:0X3be  788f                    MOVRA           HRAM_0X8F
:0X3bf  e608                    MOVA            HRAM_0X8
:0X3c0  7890                    MOVRA           HRAM_0X90
:0X3c1  e609                    MOVA            HRAM_0X9
:0X3c2  5007                    MOV             HRAM_0X7,       A
:0X3c3  6bc7                    GOTO            HADR_0X3C7
HADR_0X3C4:
:0X3c4  a884                    BCC             HRAM_0X84,      0
:0X3c5  d109                    RRB             HRAM_0X9,       R,              0X1
:0X3c6  d108                    RRB             HRAM_0X8,       R,              0X1
HADR_0X3C7:
:0X3c7  e0ff                    ADDI            0XFF
:0X3c8  9284                    JBS             HRAM_0X84,      2
:0X3c9  6bc4                    GOTO            HADR_0X3C4
:0X3ca  5008                    MOV             HRAM_0X8,       A
:0X3cb  e6c5                    MOVA            HRAM_0XC5
HADR_0X3CC:
;	while(!TBIF);
:0X3cc  90c3                    JBS             HRAM_0XC3,      0
:0X3cd  6bcc                    GOTO            HADR_0X3CC
;	SPITBW = data;
:0X3ce  ea01                    SECTION         0X1
:0X3cf  500f                    MOV             HRAM_0XF,       A
:0X3d0  e6c5                    MOVA            HRAM_0XC5
HADR_0X3D1:
;	while(!IDIF);
:0X3d1  94c3                    JBS             HRAM_0XC3,      4
:0X3d2  6bd1                    GOTO            HADR_0X3D1
;
;	CSN_1();
:0X3d3  a0aa                    BSS             HRAM_0XAA,      0
;}
:0X3d4  ea00                    SECTION         0X0
:0X3d5  ac83                    BCC             HRAM_0X83,      4
:0X3d6  c183                    RET
HADR_0X3D7:
;
;/**************************************************************************
;* 函数名称：hw2000b_read_reg
;* 功能描述：读hw2000b寄存器
;* 输入参数：addr  寄存器地址
;* 返回参数：value 寄存器值
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;uint16_t hw2000b_read_reg(uint8_t addr)
;{
;    CSN_0();
:0X3d7  e783                    CLR             HRAM_0X83
:0X3d8  a8aa                    BCC             HRAM_0XAA,      0
;	REN = 1;        //打开接收
:0X3d9  a483                    BSS             HRAM_0X83,      4
:0X3da  a3c1                    BSS             HRAM_0XC1,      3
;
;	SPITBW = addr;
:0X3db  ea01                    SECTION         0X1
:0X3dc  5009                    MOV             HRAM_0X9,       A
:0X3dd  e6c5                    MOVA            HRAM_0XC5
HADR_0X3DE:
;	while (!RBIF);   //等待接收完成
:0X3de  91c3                    JBS             HRAM_0XC3,      1
:0X3df  6bde                    GOTO            HADR_0X3DE
;	val_h = SPIRBR;  //读数据
:0X3e0  50c4                    MOV             HRAM_0XC4,      A
:0X3e1  e619                    MOVA            HRAM_0X19
;
;	SPITBW = 0xFF;
:0X3e2  e5ff                    MOVI            0XFF
:0X3e3  e6c5                    MOVA            HRAM_0XC5
HADR_0X3E4:
;	while (!RBIF);   //等待接收完成
:0X3e4  91c3                    JBS             HRAM_0XC3,      1
:0X3e5  6be4                    GOTO            HADR_0X3E4
;	val_h = SPIRBR;  //读数据
:0X3e6  50c4                    MOV             HRAM_0XC4,      A
:0X3e7  e619                    MOVA            HRAM_0X19
;
;	SPITBW = 0xFF;
:0X3e8  e5ff                    MOVI            0XFF
:0X3e9  e6c5                    MOVA            HRAM_0XC5
HADR_0X3EA:
;	while (!RBIF);   //等待接收完成
:0X3ea  91c3                    JBS             HRAM_0XC3,      1
:0X3eb  6bea                    GOTO            HADR_0X3EA
;	val_l = SPIRBR;  //读数据
:0X3ec  50c4                    MOV             HRAM_0XC4,      A
:0X3ed  e61a                    MOVA            HRAM_0X1A
;
;	CSN_1();
:0X3ee  a0aa                    BSS             HRAM_0XAA,      0
;	REN = 0;        //关闭接收
:0X3ef  abc1                    BCC             HRAM_0XC1,      3
;
;	return ((val_h <<8) + val_l);
:0X3f0  e70a                    CLR             HRAM_0XA
:0X3f1  5019                    MOV             HRAM_0X19,      A
:0X3f2  e609                    MOVA            HRAM_0X9
:0X3f3  5009                    MOV             HRAM_0X9,       A
:0X3f4  e60c                    MOVA            HRAM_0XC
:0X3f5  e70b                    CLR             HRAM_0XB
:0X3f6  e70a                    CLR             HRAM_0XA
:0X3f7  501a                    MOV             HRAM_0X1A,      A
:0X3f8  e609                    MOVA            HRAM_0X9
:0X3f9  5009                    MOV             HRAM_0X9,       A
:0X3fa  5e0b                    ADD             HRAM_0XB,       A
:0X3fb  e60d                    MOVA            HRAM_0XD
:0X3fc  500a                    MOV             HRAM_0XA,       A
:0X3fd  140c                    ADDC            HRAM_0XC,       A
:0X3fe  e60e                    MOVA            HRAM_0XE
:0X3ff  500d                    MOV             HRAM_0XD,       A
:0X400  2007                    MOVAR           HRAM_0X7
:0X401  500e                    MOV             HRAM_0XE,       A
:0X402  2008                    MOVAR           HRAM_0X8
:0X403  7807                    MOVRA           HRAM_0X7
:0X404  ea00                    SECTION         0X0
:0X405  ac83                    BCC             HRAM_0X83,      4
:0X406  c183                    RET
HADR_0X407:
;}
;
;/**************************************************************************
;* 函数名称：hw2000b_write_fifo
;* 功能描述：写hw2000b FIFO
;* 输入参数：addr   FIFO地址
;            data   数据地址
;            length 数据长度
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void hw2000b_write_fifo(uint8_t addr, uint8_t *data, uint8_t length)
;{
;	uint16_t i;	
;	addr |= 0x80;
:0X407  e783                    CLR             HRAM_0X83
:0X408  ea01                    SECTION         0X1
:0X409  a709                    BSS             HRAM_0X9,       7
;	REN = 0;        //关闭接收
:0X40a  a483                    BSS             HRAM_0X83,      4
:0X40b  abc1                    BCC             HRAM_0XC1,      3
;
;	CSN_0();
:0X40c  a8aa                    BCC             HRAM_0XAA,      0
;	SPITBW = addr;           //write addr
:0X40d  5009                    MOV             HRAM_0X9,       A
:0X40e  e6c5                    MOVA            HRAM_0XC5
;	
;	for (i = 0; i < length; i++) {
:0X40f  e70d                    CLR             HRAM_0XD
:0X410  e70e                    CLR             HRAM_0XE
HADR_0X411:
:0X411  e710                    CLR             HRAM_0X10
:0X412  500c                    MOV             HRAM_0XC,       A
:0X413  e60f                    MOVA            HRAM_0XF
:0X414  5010                    MOV             HRAM_0X10,      A
:0X415  ee0e                    SUB             HRAM_0XE,       A
:0X416  9284                    JBS             HRAM_0X84,      2
:0X417  6c1a                    GOTO            HADR_0X41A
:0X418  500f                    MOV             HRAM_0XF,       A
:0X419  ee0d                    SUB             HRAM_0XD,       A
HADR_0X41A:
:0X41a  9884                    JBC             HRAM_0X84,      0
:0X41b  6c31                    GOTO            HADR_0X431
HADR_0X41C:
;		while (!TBIF);       //waiting for spi txb empty
:0X41c  90c3                    JBS             HRAM_0XC3,      0
:0X41d  6c1c                    GOTO            HADR_0X41C
;		SPITBW = data[i];    //write  data
:0X41e  500a                    MOV             HRAM_0XA,       A
:0X41f  5e0d                    ADD             HRAM_0XD,       A
:0X420  e60f                    MOVA            HRAM_0XF
:0X421  500b                    MOV             HRAM_0XB,       A
:0X422  140e                    ADDC            HRAM_0XE,       A
:0X423  e610                    MOVA            HRAM_0X10
:0X424  5010                    MOV             HRAM_0X10,      A
:0X425  e682                    MOVA            HRAM_0X82
:0X426  500f                    MOV             HRAM_0XF,       A
:0X427  e681                    MOVA            HRAM_0X81
:0X428  5080                    MOV             HRAM_0X80,      A
:0X429  2007                    MOVAR           HRAM_0X7
:0X42a  7807                    MOVRA           HRAM_0X7
:0X42b  e6c5                    MOVA            HRAM_0XC5
:0X42c  550d                    INC             HRAM_0XD,       R
:0X42d  9284                    JBS             HRAM_0X84,      2
:0X42e  6c30                    GOTO            HADR_0X430
:0X42f  550e                    INC             HRAM_0XE,       R
HADR_0X430:
;	}
:0X430  6c11                    GOTO            HADR_0X411
HADR_0X431:
;	while (!IDIF);
:0X431  94c3                    JBS             HRAM_0XC3,      4
:0X432  6c31                    GOTO            HADR_0X431
;
;	CSN_1();
:0X433  a0aa                    BSS             HRAM_0XAA,      0
;}
:0X434  ea00                    SECTION         0X0
:0X435  ac83                    BCC             HRAM_0X83,      4
:0X436  c183                    RET
HADR_0X437:
;/**************************************************************************
;* 版权声明：Copyright@2019 上海东软载波微电子有限公司
;* 文件名称：timer.c
;* 功能描述：定时器函数
;* 函数列表：delay_ms
;			delay_us
;* 文件作者：Ljj  
;* 文件版本： 
;* 完成日期：2023-08-23	
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;#include <hic.h>
;#include "type.h"
;
;/**************************************************************************
;* 函数名称：delay_ms
;* 功能描述：毫秒级延时函数
;* 输入参数：ms   延时毫秒数，输入范围0-65535
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;//void delay_ms(uint16_t ms)
;//{
;    //uint16_t i;
;
;	//T8N = 130;		//定时时间: (255-130)*8us = 1000us=1ms
;    //T8NC = 0x8E;    //0x8D:预分频1:64 (32M/2/64)= 1/8M = 8us
;	//T8NIF = 0;
;	//T8NIE = 0;
;
;	//for (i = 0; i < ms; i++) {
;        //while(!T8NIF);
;		//T8NIF = 0;
;		//T8N += 130;
;    //}
;//}
;
;void delay_ms(uint16_t ms)
;{
;	uint16_t i;
;
;	for(;ms>0;ms--)
:0X437  e783                    CLR             HRAM_0X83
HADR_0X438:
:0X438  ea01                    SECTION         0X1
:0X439  5009                    MOV             HRAM_0X9,       A
:0X43a  580a                    IOR             HRAM_0XA,       A
:0X43b  9a84                    JBC             HRAM_0X84,      2
:0X43c  6c52                    GOTO            HADR_0X452
;	{
;		for(i = 0;i<500;i++);
:0X43d  e70b                    CLR             HRAM_0XB
:0X43e  e70c                    CLR             HRAM_0XC
HADR_0X43F:
:0X43f  e501                    MOVI            0X1
:0X440  ee0c                    SUB             HRAM_0XC,       A
:0X441  9284                    JBS             HRAM_0X84,      2
:0X442  6c45                    GOTO            HADR_0X445
:0X443  e5f4                    MOVI            0XF4
:0X444  ee0b                    SUB             HRAM_0XB,       A
HADR_0X445:
:0X445  9884                    JBC             HRAM_0X84,      0
:0X446  6c4c                    GOTO            HADR_0X44C
:0X447  550b                    INC             HRAM_0XB,       R
:0X448  9284                    JBS             HRAM_0X84,      2
:0X449  6c4b                    GOTO            HADR_0X44B
:0X44a  550c                    INC             HRAM_0XC,       R
HADR_0X44B:
:0X44b  6c3f                    GOTO            HADR_0X43F
HADR_0X44C:
;	}
:0X44c  5009                    MOV             HRAM_0X9,       A
:0X44d  9284                    JBS             HRAM_0X84,      2
:0X44e  6c50                    GOTO            HADR_0X450
:0X44f  110a                    DEC             HRAM_0XA,       R
HADR_0X450:
:0X450  1109                    DEC             HRAM_0X9,       R
:0X451  6c38                    GOTO            HADR_0X438
HADR_0X452:
;}
:0X452  ea00                    SECTION         0X0
:0X453  c183                    RET
HADR_0X454:
;
;/**************************************************************************
;* 函数名称：delay_us
;* 功能描述：微秒级延时函数
;* 输入参数：us   延时微妙数，输入范围0-65535
;* 返回参数：无
;* 函数作者：
;* 完成日期：
;* 修订历史：
;* 修订日期：
;**************************************************************************/
;void delay_us(uint16_t us)
;{
;	uint16_t i;
;	
;	for (i = 0; i < us; i++) {
:0X454  e783                    CLR             HRAM_0X83
:0X455  ea01                    SECTION         0X1
:0X456  e70b                    CLR             HRAM_0XB
:0X457  e70c                    CLR             HRAM_0XC
HADR_0X458:
:0X458  500a                    MOV             HRAM_0XA,       A
:0X459  ee0c                    SUB             HRAM_0XC,       A
:0X45a  9284                    JBS             HRAM_0X84,      2
:0X45b  6c5e                    GOTO            HADR_0X45E
:0X45c  5009                    MOV             HRAM_0X9,       A
:0X45d  ee0b                    SUB             HRAM_0XB,       A
HADR_0X45E:
:0X45e  9884                    JBC             HRAM_0X84,      0
:0X45f  6c65                    GOTO            HADR_0X465
:0X460  550b                    INC             HRAM_0XB,       R
:0X461  9284                    JBS             HRAM_0X84,      2
:0X462  6c64                    GOTO            HADR_0X464
:0X463  550c                    INC             HRAM_0XC,       R
HADR_0X464:
;	}
:0X464  6c58                    GOTO            HADR_0X458
HADR_0X465:
;}
:0X465  ea00                    SECTION         0X0
:0X466  c183                    RET
                                ORG             0X3800
:0X3800  a884                   BCC             HRAM_0X84,      0
:0X3801  7810                   MOVRA           HRAM_0X10
:0X3802  d185                   RRB             HRAM_0X85,      R,              0X1
:0X3803  e691                   MOVA            HRAM_0X91
:0X3804  780f                   MOVRA           HRAM_0XF
:0X3805  d185                   RRB             HRAM_0X85,      R,              0X1
:0X3806  e690                   MOVA            HRAM_0X90
:0X3807  c184                   TBR
:0X3808  990f                   JBC             HRAM_0XF,       1
:0X3809  680e                   GOTO            HADR_0XE
:0X380a  5092                   MOV             HRAM_0X92,      A
:0X380b  980f                   JBC             HRAM_0XF,       0
:0X380c  5093                   MOV             HRAM_0X93,      A
:0X380d  6811                   GOTO            HADR_0X11
:0X380e  50a1                   MOV             HRAM_0XA1,      A
:0X380f  980f                   JBC             HRAM_0XF,       0
:0X3810  50a2                   MOV             HRAM_0XA2,      A
:0X3811  550f                   INC             HRAM_0XF,       R
:0X3812  9a84                   JBC             HRAM_0X84,      2
:0X3813  5510                   INC             HRAM_0X10,      R
:0X3814  c183                   RET

                                END
