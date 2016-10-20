#ifndef __DGUS_H
#define __DGUS_H	 
#include "sys.h"

void blsj_to_ping(u16 addr,int32_t data,u8 length);    //地址    数据  变量字节数
u32 blsj_from_ping(u16 addr,u8 data);             //地址    变量字节数
void jcq_to_ping(u8 addr,u8 data);                 //地址    数据
void jcq_form_ping(u8 addr,u8 data);               //地址    数据

#endif
