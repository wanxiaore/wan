#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ���������ɣ��������������κ���;
//ALIENTEKս��STM32������
//������������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/3
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) �������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////   	 

 
#define KEY2  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2)//��ȡ����2
#define KEY1  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1)//��ȡ����1 
#define KEY0  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_0)//��ȡ����0

void KEY_Init(void);//IO��ʼ��
u8 KEY_Scan(u8);  	//����ɨ�躯��					    
#endif