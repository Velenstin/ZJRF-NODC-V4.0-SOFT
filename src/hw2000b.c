/**************************************************************************
* 版权声明：Copyright@2019 上海东软载波微电子有限公司
* 文件名称：hw2000b.c
* 功能描述：RF函数
* 函数列表：hw2000b_port_init
			hw2000b_init_1m
			hw2000b_init_250k
			hw2000b_set_osc_16M
			hw2000b_set_power_max
			hw2000b_set_power_0
			hw2000b_set_power_negative_20
			hw2000b_set_frequence_2403
			hw2000b_set_frequence_2450
			hw2000b_set_frequence_2483
			hw2000b_power_test
			hw2000b_cancel_sw
			hw2000b_tx_data
			hw2000b_rx_enable
			hw2000b_rx_data
			hw2000b_power_down
			hw2000b_power_on
* 文件作者：Ljj  
* 文件版本： 
* 完成日期：2023-08-23	
* 修订历史：
* 修订日期：
**************************************************************************/
#include <hic.h>
#include "type.h"
#include "hw2000b.h"
#include "spi.h"
#include "timer.h"

const uint16_t agcTab[18] = {0x0000, 0x0000, 0x0000, 0x0001, 0x0002, 0x000A,
                             0x0012, 0x0212, 0x0412, 0x064A, 0x084A, 0x0A4A,
                             0x0A52, 0x0A92, 0x0C92, 0x0CD2, 0x0CDA, 0x0CE3
};
extern	sbit		_hw2000b_irq_request;

extern	uint16_t	_ack_count;

//uint16_t reg_value1;

/**************************************************************************
* 函数名称：hw2000b_port_init
* 功能描述：初始化hw2000b接口
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_port_init(void)
{
	CE = 0;
	delay_ms(3);
	CE = 1;
	delay_ms(3);
}

void reg_read_write_test()
{
	uint8_t i=0;
    hw2000b_write_reg(0x4C, 0x55AA);	//close write protection
    uint16_t all_reg_value[0x6a+1] = {0};
    for(i=0;i<=0x6a;i++)
    {
        all_reg_value[i] = hw2000b_read_reg(i);
    }
    //write 0 to all reg 
    for(i=0;i<=0x6a;i++)
    {
        if(i != 0x4C)
        {
            hw2000b_write_reg(i,0x0000);
        }
        all_reg_value[i] = hw2000b_read_reg(i);
    }
    
    //write 1 to all reg 
    for(i=0;i<=0x6a;i++)
    {
        if(i != 0x4C && i != 0x4F)
        {
            hw2000b_write_reg(i,0xffff);
        } else if(i == 0x4F)
                {
                    hw2000b_write_reg(i,0x0000);
                }
        all_reg_value[i] = hw2000b_read_reg(i);
    }
    
    all_reg_value[0] = hw2000b_read_reg(0);//breakpoint test
}
/**************************************************************************
* 函数名称：hw2000b_init_1m
* 功能描述：初始化hw2000b，速率为1M，晶振12M,最大功率
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_init_1m(void)
{
    uint8_t i;

	hw2000b_write_reg(0x4C, 0x55AA);		//open write protection
	for (i = 0; i < 18; i++) {
        hw2000b_write_reg(0x50 + i, agcTab[i]);            
    }

	hw2000b_write_reg(0x0F, 0xFC04);//ES7W8020

    hw2000b_write_reg(0x01, 0x4D58);//ES7W8020
    hw2000b_write_reg(0x02, 0x04CC);//ES7W8020
    hw2000b_write_reg(0x08, 0xB6C4);//ES7W8020
	hw2000b_write_reg(0x09, 0xB442);//ES7W8020
    hw2000b_write_reg(0x4A, 0x326C);//ES7W8020

    hw2000b_write_reg(0x0B, 0x0873);//ES7W8020    8dBm
    hw2000b_write_reg(0x49, 0x1330);//ES7W8020
    hw2000b_write_reg(0x27, 0x8F20);//ES7W8020
	hw2000b_write_reg(0x48, 0x4300);//ES7W8020
	hw2000b_write_reg(0x26, 0x000C);//ES7W8020

    hw2000b_write_reg(0x28, 0x8401);//sync_thres 1bit
    hw2000b_write_reg(0x2C, 0x918B);
    hw2000b_write_reg(0x1B, 0xE754);
    hw2000b_write_reg(0x06, 0xB000);
    hw2000b_write_reg(0x07, 0x54E0);
    hw2000b_write_reg(0x1C, 0x51A0);
    hw2000b_write_reg(0x19, 0x2084);
    hw2000b_write_reg(0x20, 0xF000);//preamble:16 bytes, sync:48 bits
    hw2000b_write_reg(0x2A, 0xC07D);//rate:1Mbps, ACK_time:28us
}

/**************************************************************************
* 函数名称：hw2000b_init_250k
* 功能描述：初始化hw2000b，速率为250k,晶振12M，最大功率
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_init_250k(void)
{
    uint8_t i;

	hw2000b_write_reg(0x4C, 0x55AA);		//open write project
	for (i = 0; i < 18; i++) {
        hw2000b_write_reg(0x50 + i, agcTab[i]);
    }

	hw2000b_write_reg(0x0F, 0xFC04);//ES7W8020

    hw2000b_write_reg(0x01, 0x4D58);//ES7W8020
    hw2000b_write_reg(0x02, 0x04CC);//ES7W8020
    hw2000b_write_reg(0x08, 0xB6C4);//ES7W8020
	hw2000b_write_reg(0x09, 0xB442);//ES7W8020  
    hw2000b_write_reg(0x4A, 0x326C);//ES7W8020 

    hw2000b_write_reg(0x0B, 0x0873);//ES7W8020   tx power:8dBm
    hw2000b_write_reg(0x49, 0x1330);//ES7W8020   
    hw2000b_write_reg(0x27, 0x8F20);//ES7W8020   
	hw2000b_write_reg(0x48, 0x4300);//ES7W8020
	hw2000b_write_reg(0x26, 0x000C);//ES7W8020

    hw2000b_write_reg(0x28, 0x8401);//sync_thres:1bit
    hw2000b_write_reg(0x2C, 0x918B);	
	hw2000b_write_reg(0x2A, 0x40FF);//rate:250kbps     ACK_time:1000us
	hw2000b_write_reg(0x1A, 0x0D31);
	hw2000b_write_reg(0x19, 0x0884);
	hw2000b_write_reg(0x20, 0xF000);//preamble:16 bytes  sync:48 bits

	hw2000b_write_reg(0x3C, 0x1001);//Enable PIPE0、PIPE0 ACK

	// pipe 0 addr set 
    hw2000b_write_reg(0x40, 0x1122); 
    hw2000b_write_reg(0x41, 0x3344); 
    hw2000b_write_reg(0x42, 0x5566); 

	hw2000b_write_reg(0x23, 0x0500);//re_tx_times:5
	//reg_value1 = hw2000b_read_reg(0x28);

	//if(reg_value1 != 0x2103)
	//{
	//hw2000b_write_reg(0x20, 0xF000);//preamble:16 bytes  sync:48 bits
	//}
}

/**************************************************************************
* 函数名称：hw2000b_set_osc_16M
* 功能描述：16M晶振设置
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_set_osc_16M(void)
{
    hw2000b_write_reg(0x04, 0x4800);
    hw2000b_write_reg(0x22, 0x2030);
    hw2000b_write_reg(0x1C, 0x5198);
}

/**************************************************************************
* 函数名称：hw2000b_set_power_max
* 功能描述：设置发射功率为最大发射功率
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_set_power_max(void)
{
    hw2000b_write_reg(0x4C, 0x55AA);		//open write project
	hw2000b_write_reg(0x0B, 0x0873);//9
}

/**************************************************************************
* 函数名称：hw2000b_set_power_5
* 功能描述：设置发射功率为5dBm
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_set_power_5(void)
{
    hw2000b_write_reg(0x4C, 0x55AA);        //open write project
    hw2000b_write_reg(0x0B, 0x085F);
}

/**************************************************************************
* 函数名称：hw2000b_set_power_0
* 功能描述：设置发射功率为0dBm
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_set_power_0(void)
{
    hw2000b_write_reg(0x4C, 0x55AA);		//open write project
	hw2000b_write_reg(0x0B, 0x0851);
}

/**************************************************************************
* 函数名称：hw2000b_set_power_negative_10
* 功能描述：设置发射功率为-10dBm
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_set_power_negative_10(void)
{
    hw2000b_write_reg(0x4C, 0x55AA);        //open write project
    hw2000b_write_reg(0x0B, 0x0845); 
}

/**************************************************************************
* 函数名称：hw2000b_set_power_negative_20
* 功能描述：设置发射功率为-20dBm
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_set_power_negative_20(void)
{
    hw2000b_write_reg(0x4C, 0x55AA);		//open write project
	hw2000b_write_reg(0x0B, 0x0842);
}

/**************************************************************************
* 函数名称：hw2000b_set_frequence_2403
* 功能描述：设置发射频点为2.403GHz
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_set_frequence_2403(void)
{
    hw2000b_write_reg(0x22, 0x1801); //12M OSC
}
/**************************************************************************
* 函数名称：hw2000b_set_frequence_2420
* 功能描述：设置发射频点为2.420GHz
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_set_frequence_2420(void)
{
    hw2000b_write_reg(0x22, 0x1814); //12M OSC
}
/**************************************************************************
* 函数名称：hw2000b_set_frequence_2450
* 功能描述：设置发射频点为2.450GHz
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_set_frequence_2450(void)
{
    hw2000b_write_reg(0x22, 0x1830); //12M OSC
}

/**************************************************************************
* 函数名称：hw2000b_set_frequence_2460
* 功能描述：设置发射频点为2.460GHz
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_set_frequence_2460(void)
{
    hw2000b_write_reg(0x22, 0x183C); //12M OSC
}

/**************************************************************************
* 函数名称：hw2000b_set_frequence_2483
* 功能描述：设置发射频点为2.483GHz
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_set_frequence_2483(void)
{
    hw2000b_write_reg(0x22, 0x1851); //12M OSC
}


/**************************************************************************
* 函数名称：hw2000b_power_test
* 功能描述：单载波模式，供用户测试功率使用
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_power_test(void)
{
	//发送单载波
	uint16_t reg_val;
	reg_val = hw2000b_read_reg(0x1C);
	hw2000b_write_reg(0x1C, reg_val & 0xFE7F); //寄存器的第7、8位置0  
	hw2000b_write_reg(0x29, 0x0000); //MCU control  
	hw2000b_write_reg(0x21, 0x0100); //TX enable	       
	hw2000b_write_reg(0x36, 0x0081);

	while(1)
	{
	;
	}

}

/**************************************************************************
* 函数名称：hw2000b_cancel_sw
* 功能描述：取消单载波模式
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_cancel_sw(void)
{
    uint16_t reg_val;
    
    hw2000b_write_reg(0x36, 0x0090);
    hw2000b_write_reg(0x21, 0x0000); //TX disable
    hw2000b_write_reg(0x29, 0x1800); //MCU control    
    hw2000b_write_reg(0x3D, 0x0008); //clear int0
    reg_val = hw2000b_read_reg(0x1C);
    hw2000b_write_reg(0x1C, reg_val|0x0180); //bit7 1, bit8 1
}

/**************************************************************************
* 函数名称：hw2000b_tx_data
* 功能描述：发送处理函数
* 输入参数：uint8_t *data, data[0]是数据长度
* 返回参数：
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_tx_data(uint8_t *buf, uint16_t size)
{
	uint16_t reg;
	_hw2000b_irq_request = 0;
	
    hw2000b_write_reg(0x21, 0x0100);	//TX enable
    delay_us(5);						//delete if lower spi rate,
	hw2000b_write_reg(0x3B, 0x8000);	//clear TX FIFO
    hw2000b_write_fifo(0x32, buf, size);//write FIFO
	reg = hw2000b_read_reg(0x36);
	hw2000b_write_reg(0x36, 0x0081|reg);//FIFO0 occupy
    hw2000b_write_reg(0x37, 0x0000);	//FIFO1 disable

	while (!_hw2000b_irq_request);
	
	reg = hw2000b_read_reg(0x36);
    if ((reg & 0x8000) == 0x8000)		//rtx fail
	{
		//_ack_count--;					//添加重发超时处理代码
	}
	else
	{	//ack mode:recieve ack    no ack mode:tx success
		if((hw2000b_read_reg(0x3C) & 0x000F) != 0)	//recieve ack
			{_ack_count++;}
		else
			{_ack_count = 0;}
	}
    hw2000b_write_reg(0x36, 0x0080);	//FIFO0 no occupy
	hw2000b_write_reg(0x3D, 0x0008);	//clear int0
	hw2000b_write_reg(0x21, 0x0000);	//TX disable
	//hw2000b_write_reg(0x23, 0x431B); //Soft reset			//会增加功耗
	//hw2000b_write_reg(0x23, 0x031B); 
	//delay_us(20);//delete if lower spi rate,
}

/**************************************************************************
* 函数名称：hw2000b_rx_enable
* 功能描述：接收使能
* 输入参数：无
* 返回参数：
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_rx_enable(void)
{
	hw2000b_write_reg(0x3D, 0x0008);
	hw2000b_write_reg(0x21, 0x0000);
	hw2000b_write_reg(0x36, 0x0080);
	hw2000b_write_reg(0x37, 0x0000);
	hw2000b_write_reg(0x21, 0x0080);
}

/**************************************************************************
* 函数名称：hw2000b_rx_data
* 功能描述：接收函数
* 输入参数：data
* 返回参数：0 success -1 failed
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
int8_t hw2000b_rx_data(uint8_t *data)
{
	uint16_t reg;

	if(_hw2000b_irq_request){
		_hw2000b_irq_request = 0;

		reg = hw2000b_read_reg(0x36);
		if ((reg & 0x2000) == 0){	//crc校验成功
			hw2000b_read_fifo(0x32, data, 1); //将接收数据放到_data中
			hw2000b_read_fifo(0x32, &data[1], data[0]); //将接收数据放到_data中
		} else {
			hw2000b_write_reg(0x3D, 0x0008); // 清INT0控制位
			return -1;
		}

		hw2000b_write_reg(0x3D, 0x0008); // 清INT0控制位
		//hw2000b_write_reg(0x21, 0x0000); //RX disable
		return 0;
	} else {
		return -1;
	}
}

/**************************************************************************
* 函数名称：hw2000b_power_down
* 功能描述：hw2000b进入power down
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_power_down(void)
{
	uint16_t reg_value;
	
	hw2000b_write_reg(0x21, 0x0000); // TX RX disable
	reg_value = hw2000b_read_reg(0x23);
	hw2000b_write_reg(0x23, 0x8080 | reg_value);	//0x23寄存器第【15】位置1

}

/**************************************************************************
* 函数名称：hw2000b_power_on
* 功能描述：hw2000b从power down唤醒
* 输入参数：无
* 返回参数：无
* 函数作者：
* 完成日期：
* 修订历史：
* 修订日期：
**************************************************************************/
void hw2000b_power_on(void)
{
	uint16_t reg_value;
	
	reg_value = hw2000b_read_reg(0x23);
	hw2000b_write_reg(0x23, 0x7F7F & reg_value);	//0x23寄存器第【15】位置0

	delay_ms(1);

	hw2000b_write_reg(0x23, 0x431B); //Soft reset			//会增加功耗
	hw2000b_write_reg(0x23, 0x031B); 	
	delay_us(20);
	hw2000b_init_250k();
}
