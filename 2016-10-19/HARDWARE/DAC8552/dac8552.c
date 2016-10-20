#include "dac8552.h"
#include "delay.h"	 
void DAC8552_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}
///*******************************************
//		????:Write_DAC8552
//		?    ?:????,??????
//		?    ?:Command -> ??A/B,0x30=A?0x34=B   
//          	  Data -> ????
//		???  :?
//********************************************/
void Write_DAC8552(u8 Command, u16 Data)
{
	u8 i;

	CS=1;
	CS=0;

	for (i=0; i<8; i++)              //Write 8 bit command 
	{
		SCLK = 1;
		if (Command & 0x80)
		{
	     DIN = 1;
		}
		else
		{
			 DIN = 0;
		}
		SCLK = 0;
		Command <<= 1;
	}

	for (i=0; i<16; i++)             //write 16 bit data
	{
		SCLK = 1;
		if (Data & 0x8000)
		{
		DIN = 1;
		}
		else
		{
		DIN = 0;
		}
		SCLK = 0;
		Data <<= 1;
	}
	  CS=1;
}

///*******************************************
//		????:Voltage_Convert
//		?    ?:??????????????,??DA??
//		?    ?:Vref -> ????   
//          	  voltage -> ???????
//		???  :DA??
//********************************************/
u16 Voltage_Convert(float Vref, float voltage)
{
	u16 _D_;
	_D_ = (u16)(65536 * voltage / Vref);
    
	return _D_;
}
