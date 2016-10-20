#include "sys.h"
#include "dgus.h"
#include "usart.h"
#include "delay.h"

u8 seng_byte[10]={0x5a,0xa5,0,0,0,0,0,0,0};        
u8 read_byte[7]={0x5a,0xa5,0,0,0,0,0};

void blsj_to_ping(u16 addr,int32_t data,u8 length)
{
	u8 i;
	seng_byte[2]=0x03+length;
	seng_byte[3]=0x82;
	seng_byte[4]=addr>>8;
	seng_byte[5]=addr&0x00ff;
	if(length==2)
	{
 	seng_byte[6]=(data&0x0000ff00)>>8;
 	seng_byte[7]= data&0x000000ff;
	}
	if(length==4)
	{
	seng_byte[6]=data>>24;
	seng_byte[7]=(data&0x00ff0000)>>16;
	seng_byte[8]=(data&0x0000ff00)>>8;
	seng_byte[9]= data&0x000000ff;
	}
	for(i=0;i<6+length;++i)
	{
		USART_SendData(UART5, seng_byte[i]);//向串口5发送数据
		while(USART_GetFlagStatus(UART5,USART_FLAG_TC)!=SET);//等待发送结束
  }
}
u32 blsj_from_ping(u16 addr,u8 data)
{
	u8 i;
	u32 values;
	u8 k=3;
	read_byte[2]=0x04;
	read_byte[3]=0x83;
	read_byte[4]=addr>>8;
	read_byte[5]=addr&0x00ff;
	read_byte[6]=data;
	for(i=0;i<7;++i)
	{
		USART_SendData(UART5, read_byte[i]);//向串口5发送数据
		while(USART_GetFlagStatus(UART5,USART_FLAG_TC)!=SET);//等待发送结束
  }
	delay_us(100);
	while(k)
	{
		if(USART_RX_STA!=0)
		{
			if(data==1)
			values=(u16)USART_RX_BUF[0]<<8|(u16)USART_RX_BUF[1];
			else if(data==2)
			values=(u32)USART_RX_BUF[0]<<24|(u32)USART_RX_BUF[1]<<16|(u32)USART_RX_BUF[2]<<8|(u32)USART_RX_BUF[3];
			else 
			values=0;
			USART_RX_STA=0; 
			k=1;
    }
		k--;
		delay_us(100);
  }			 
  return values;
}
void jcq_to_ping(u8 addr,u8 data)
{
	u8 i;
	seng_byte[2]=0x03;
	seng_byte[3]=0x80;
	seng_byte[4]=addr;
	seng_byte[5]=data;
	for(i=0;i<6;++i)
	{
		USART_SendData(UART5, seng_byte[i]);//向串口5发送数据
		while(USART_GetFlagStatus(UART5,USART_FLAG_TC)!=SET);//等待发送结束
  }
}
void jcq_form_ping(u8 addr,u8 data)
{
	u8 i;
	read_byte[2]=0x03;
	read_byte[3]=0x80;
	read_byte[4]=addr;
	read_byte[5]=data;
	for(i=0;i<6;++i)
	{
		USART_SendData(UART5, read_byte[i]);//向串口5发送数据
		while(USART_GetFlagStatus(UART5,USART_FLAG_TC)!=SET);//等待发送结束
  }
}
