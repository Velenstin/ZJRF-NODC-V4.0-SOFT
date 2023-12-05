/**************************************************************************
* ��Ȩ������Copyright@2019 �Ϻ������ز�΢�������޹�˾
* �ļ����ƣ�hw2000b.c
* ����������RF����
* �����б�hw2000b_port_init
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
* �ļ����ߣ�Ljj  
* �ļ��汾�� 
* ������ڣ�2023-08-23	
* �޶���ʷ��
* �޶����ڣ�
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
* �������ƣ�hw2000b_port_init
* ������������ʼ��hw2000b�ӿ�
* �����������
* ���ز�������
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
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
* �������ƣ�hw2000b_init_1m
* ������������ʼ��hw2000b������Ϊ1M������12M,�����
* �����������
* ���ز�������
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
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
* �������ƣ�hw2000b_init_250k
* ������������ʼ��hw2000b������Ϊ250k,����12M�������
* �����������
* ���ز�������
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
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

	hw2000b_write_reg(0x3C, 0x1001);//Enable PIPE0��PIPE0 ACK

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
* �������ƣ�hw2000b_set_osc_16M
* ����������16M��������
* �����������
* ���ز�������
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
void hw2000b_set_osc_16M(void)
{
    hw2000b_write_reg(0x04, 0x4800);
    hw2000b_write_reg(0x22, 0x2030);
    hw2000b_write_reg(0x1C, 0x5198);
}

/**************************************************************************
* �������ƣ�hw2000b_set_power_max
* �������������÷��书��Ϊ����书��
* �����������
* ���ز�������
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
void hw2000b_set_power_max(void)
{
    hw2000b_write_reg(0x4C, 0x55AA);		//open write project
	hw2000b_write_reg(0x0B, 0x0873);//9
}

/**************************************************************************
* �������ƣ�hw2000b_set_power_5
* �������������÷��书��Ϊ5dBm
* �����������
* ���ز�������
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
void hw2000b_set_power_5(void)
{
    hw2000b_write_reg(0x4C, 0x55AA);        //open write project
    hw2000b_write_reg(0x0B, 0x085F);
}

/**************************************************************************
* �������ƣ�hw2000b_set_power_0
* �������������÷��书��Ϊ0dBm
* �����������
* ���ز�������
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
void hw2000b_set_power_0(void)
{
    hw2000b_write_reg(0x4C, 0x55AA);		//open write project
	hw2000b_write_reg(0x0B, 0x0851);
}

/**************************************************************************
* �������ƣ�hw2000b_set_power_negative_10
* �������������÷��书��Ϊ-10dBm
* �����������
* ���ز�������
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
void hw2000b_set_power_negative_10(void)
{
    hw2000b_write_reg(0x4C, 0x55AA);        //open write project
    hw2000b_write_reg(0x0B, 0x0845); 
}

/**************************************************************************
* �������ƣ�hw2000b_set_power_negative_20
* �������������÷��书��Ϊ-20dBm
* �����������
* ���ز�������
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
void hw2000b_set_power_negative_20(void)
{
    hw2000b_write_reg(0x4C, 0x55AA);		//open write project
	hw2000b_write_reg(0x0B, 0x0842);
}

/**************************************************************************
* �������ƣ�hw2000b_set_frequence_2403
* �������������÷���Ƶ��Ϊ2.403GHz
* �����������
* ���ز�������
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
void hw2000b_set_frequence_2403(void)
{
    hw2000b_write_reg(0x22, 0x1801); //12M OSC
}
/**************************************************************************
* �������ƣ�hw2000b_set_frequence_2420
* �������������÷���Ƶ��Ϊ2.420GHz
* �����������
* ���ز�������
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
void hw2000b_set_frequence_2420(void)
{
    hw2000b_write_reg(0x22, 0x1814); //12M OSC
}
/**************************************************************************
* �������ƣ�hw2000b_set_frequence_2450
* �������������÷���Ƶ��Ϊ2.450GHz
* �����������
* ���ز�������
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
void hw2000b_set_frequence_2450(void)
{
    hw2000b_write_reg(0x22, 0x1830); //12M OSC
}

/**************************************************************************
* �������ƣ�hw2000b_set_frequence_2460
* �������������÷���Ƶ��Ϊ2.460GHz
* �����������
* ���ز�������
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
void hw2000b_set_frequence_2460(void)
{
    hw2000b_write_reg(0x22, 0x183C); //12M OSC
}

/**************************************************************************
* �������ƣ�hw2000b_set_frequence_2483
* �������������÷���Ƶ��Ϊ2.483GHz
* �����������
* ���ز�������
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
void hw2000b_set_frequence_2483(void)
{
    hw2000b_write_reg(0x22, 0x1851); //12M OSC
}


/**************************************************************************
* �������ƣ�hw2000b_power_test
* �������������ز�ģʽ�����û����Թ���ʹ��
* �����������
* ���ز�������
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
void hw2000b_power_test(void)
{
	//���͵��ز�
	uint16_t reg_val;
	reg_val = hw2000b_read_reg(0x1C);
	hw2000b_write_reg(0x1C, reg_val & 0xFE7F); //�Ĵ����ĵ�7��8λ��0  
	hw2000b_write_reg(0x29, 0x0000); //MCU control  
	hw2000b_write_reg(0x21, 0x0100); //TX enable	       
	hw2000b_write_reg(0x36, 0x0081);

	while(1)
	{
	;
	}

}

/**************************************************************************
* �������ƣ�hw2000b_cancel_sw
* ����������ȡ�����ز�ģʽ
* �����������
* ���ز�������
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
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
* �������ƣ�hw2000b_tx_data
* �������������ʹ�����
* ���������uint8_t *data, data[0]�����ݳ���
* ���ز�����
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
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
		//_ack_count--;					//����ط���ʱ�������
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
	//hw2000b_write_reg(0x23, 0x431B); //Soft reset			//�����ӹ���
	//hw2000b_write_reg(0x23, 0x031B); 
	//delay_us(20);//delete if lower spi rate,
}

/**************************************************************************
* �������ƣ�hw2000b_rx_enable
* ��������������ʹ��
* �����������
* ���ز�����
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
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
* �������ƣ�hw2000b_rx_data
* �������������պ���
* ���������data
* ���ز�����0 success -1 failed
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
int8_t hw2000b_rx_data(uint8_t *data)
{
	uint16_t reg;

	if(_hw2000b_irq_request){
		_hw2000b_irq_request = 0;

		reg = hw2000b_read_reg(0x36);
		if ((reg & 0x2000) == 0){	//crcУ��ɹ�
			hw2000b_read_fifo(0x32, data, 1); //���������ݷŵ�_data��
			hw2000b_read_fifo(0x32, &data[1], data[0]); //���������ݷŵ�_data��
		} else {
			hw2000b_write_reg(0x3D, 0x0008); // ��INT0����λ
			return -1;
		}

		hw2000b_write_reg(0x3D, 0x0008); // ��INT0����λ
		//hw2000b_write_reg(0x21, 0x0000); //RX disable
		return 0;
	} else {
		return -1;
	}
}

/**************************************************************************
* �������ƣ�hw2000b_power_down
* ����������hw2000b����power down
* �����������
* ���ز�������
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
void hw2000b_power_down(void)
{
	uint16_t reg_value;
	
	hw2000b_write_reg(0x21, 0x0000); // TX RX disable
	reg_value = hw2000b_read_reg(0x23);
	hw2000b_write_reg(0x23, 0x8080 | reg_value);	//0x23�Ĵ����ڡ�15��λ��1

}

/**************************************************************************
* �������ƣ�hw2000b_power_on
* ����������hw2000b��power down����
* �����������
* ���ز�������
* �������ߣ�
* ������ڣ�
* �޶���ʷ��
* �޶����ڣ�
**************************************************************************/
void hw2000b_power_on(void)
{
	uint16_t reg_value;
	
	reg_value = hw2000b_read_reg(0x23);
	hw2000b_write_reg(0x23, 0x7F7F & reg_value);	//0x23�Ĵ����ڡ�15��λ��0

	delay_ms(1);

	hw2000b_write_reg(0x23, 0x431B); //Soft reset			//�����ӹ���
	hw2000b_write_reg(0x23, 0x031B); 	
	delay_us(20);
	hw2000b_init_250k();
}
