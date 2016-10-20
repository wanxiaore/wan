#include "di.h"
void DI_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructureE;
 GPIO_InitTypeDef  GPIO_InitStructureD;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);	 //ʹ��PD�˿�ʱ��
	
 GPIO_InitStructureE.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;				 
 GPIO_InitStructureE.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructureE.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOE, &GPIO_InitStructureE);					 //�����趨������ʼ��GPIOD
 GPIO_ResetBits(GPIOE,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9);						 //PE �����
	
 
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);	 //ʹ��PD�˿�ʱ��
	
 GPIO_InitStructureD.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;				 
 GPIO_InitStructureD.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructureD.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOD, &GPIO_InitStructureD);					 //�����趨������ʼ��GPIOD
 GPIO_ResetBits(GPIOD,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9);						 //PE �����
}
