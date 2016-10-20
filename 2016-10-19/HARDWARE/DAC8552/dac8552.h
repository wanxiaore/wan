#ifndef __DAC8552_H
#define __DAC8552_H
#include "sys.h"

#define DAC8552_CS_LOW()       GPIO_ResetBits(GPIOA, GPIO_Pin_12)
#define DAC8552_CS_HIGH()      GPIO_SetBits(GPIOA, GPIO_Pin_12) 	
//IO²Ù×÷º¯Êý	 
#define CS      PEout(13)
#define SCLK    PEout(14) 
#define DIN     PEout(15) 

void DAC8552_Init(void);
void Write_DAC8552(u8 Command, u16 Data);
u16 Voltage_Convert(float Vref, float voltage);
		 
#endif

