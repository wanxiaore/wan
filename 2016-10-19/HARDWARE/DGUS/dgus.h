#ifndef __DGUS_H
#define __DGUS_H	 
#include "sys.h"

void blsj_to_ping(u16 addr,int32_t data,u8 length);    //��ַ    ����  �����ֽ���
u32 blsj_from_ping(u16 addr,u8 data);             //��ַ    �����ֽ���
void jcq_to_ping(u8 addr,u8 data);                 //��ַ    ����
void jcq_form_ping(u8 addr,u8 data);               //��ַ    ����

#endif
