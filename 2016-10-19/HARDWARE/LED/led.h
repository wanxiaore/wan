#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/2
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
#define LED0 PBout(5)// PB5
#define LED1 PEout(5)// PE5	

#define DIRECTION PCout(0)// PC0  �����������־λ

// #define LeftLimit  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_0)		  //����λ
// #define MiddleLimit  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_1)		//��λ
// #define RightLimit  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_2)		  //����λ

void LED_Init(void);//��ʼ��

		 				    
#endif
