#include "sys.h"
#include "math.h"
#include "define.h"

#include "led.h"
#include "delay.h"
#include "key.h"
#include "usart.h"	 
#include "dac8552.h"
#include "adc.h"
#include "oct.h"
#include "dgus.h"
#include "do.h"
#include "di.h"
#include "24cxx.h"
#include "myiic.h"

int main(void)
 {	
	 delay_init();	    	   //延时函数初始化	  
	 NVIC_Configuration(); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	 
	 uart_init(115200);	 	   //上位机串口初始化为115200
	 uart3_init(115200);	 	 //NMEA0183串口初始化为115200
	 uart5_init(115200);	 	 //NMEA0183串口初始化为115200
	 
	 LED_Init();		  		   //初始化与LED连接的硬件接口
	 KEY_Init();				     //按键初始化	
	 DI_Init();
	 DO_Init();
	 Adc_Init();		  		    //ADC初始化
	 DAC8552_Init();		
   TIM5_Int_Init(9,7199);		//10Khz的计数频率，周期为(9+1)/10=1ms 
	 
	 WDojsfm=1;
	 WDopwfm=0;
	 WDoxyflqfm=1;
	 
	 ddlpwfz1=1;
	 ddlpwfz2=1;
	 ddlpwfz3=1;
	 ddlpwfz4=1;
	 Write_DAC8552(0x30, Voltage_Convert(5.00,3.50));
///////////////////////////////////////////////////////主循环///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
		while(1)
		{	     			
///////////////////读取AD///////////////////////////////////
			RAddyz= 48.0*(float)(Get_Adc_Average(0)-745)/2979.0;
			RAddlz=50.0*(float)(Get_Adc_Average(1)-745)/2979.0;
			RAdddlz=40.0*(float)(Get_Adc_Average(2)-745)/2979.0;
			RAdphz=14.0*(float)(Get_Adc_Average(3)-745)/2979.0;
			RAdrswdcgq=100.0*(float)(Get_Adc_Average(4)-745)/2979.0;
			RAdcswdcgq=100.0*(float)(Get_Adc_Average(5)-745)/2979.0;
			RAdhjwdcgq=100.0*(float)(Get_Adc_Average(6)-745)/2979.0;
			RAdhjsdcgq=100.0*(float)(Get_Adc_Average(7)-745)/2979.0;
			RAdbsssll=15.0*(float)(Get_Adc_Average(8)-745)/2979.0;
			RAdzd=100.0*(float)(Get_Adc_Average(9)-745)/2979.0;
			RAdorp=1000.0*(float)(Get_Adc_Average(10)-745)/2979.0;
			RAdpwssll=50.0*(float)(Get_Adc_Average(11)-745)/2979.0;
			RAdcllssll=50.0*(float)(Get_Adc_Average(12)-745)/2979.0;
			RAdxhsssll=50.0*(float)(Get_Adc_Average(13)-745)/2979.0;
////////////////////从触摸屏获取值////////////////////////////	
			gddjyxjgsj=blsj_from_ping(0x0000,1)*60000;
			gddjyxsj=blsj_from_ping(0x0000,1)*1000;
			pwfmyxsj=blsj_from_ping(0x0000,1)*1000;
			pwfmyxjgsj=blsj_from_ping(0x0000,1)*60000;
			djdyhyscz=blsj_from_ping(0x0000,1)*288;
			
			nsbs=blsj_from_ping(0x0000,1);
			fsxs=blsj_from_ping(0x0000,1);
			lcpwjgsj=blsj_from_ping(0x0000,1)*60;
			
			pwfs=blsj_from_ping(0x0000,1);
///////////////////////报警/////////////////////////
			if((RAdddlz>=gddlbjz||RAdzd>=gzdbjz)&&pwfs!=4)
			{
				bjzdspwfs=pwfs;
				pwfs=4;
			}
/////////////////控制电解电源恒流///////////////////
			if(djdyyxbz==1)
			{
				if(fabs(RAddlz-sddjdyz)>5)
				{
					if(RAddlz<sddjdyz) WAddjdyz++;
					else WAddjdyz--;
				}
			}
			if(djdyyxbz==0) WAddjdyz=0;
			
			if(pwfs==1)
			{
/////////////////////////分支1的步骤执行///////////////////
				if(ddlpwfz1==1)
				djdyyxbz=1;
				else if(ddlpwfz1==2)
				djdyyxbz=0;
				else
				djdyyxbz=1;
//////////////////////////分支2 的步骤执行/////////////////				
				if(RAdddlz>=ddlsdsx&&ddlpwfz2==1) sjbcbz2=1;
				if(ddlpwfz2==1&&sjbcjs2>=30000)
				{
					sjbcbz2=0;
					sjbcjs2=0;
					WDopwfm=1;
					WDopwdyx=1;
					ddlpwfz1=2;
					ddlpwfz2=2;
        }
				if(ddlpwfz2==2&&RAdddlz<=ddlsdxx) 
				{
					sjbcbz2=1;
					ddlpwfz2=3;
        }
				if(ddlpwfz2==3&&sjbcjs2>=15000)
				{
					sjbcbz2=0;
					sjbcjs2=0;
					WDopwfm=0;
					WDopwdyx=0;
					ddlpwfz2=4;
        }
				if(ddlpwfz2==4&&RDipwfmfk==0)
				{                                               
					sjbcbz2=1;
					ddlpwfz2=5;
				}
				if(ddlpwfz2==5&&sjbcjs2>=15000)
				{
					sjbcbz2=0;
					sjbcjs2=0;
					ddlpwfz1=3;
				}
//////////////////////////分支3的步骤执行///////////////////////////////
				if(ddlpwfz3==1) sjbcbz3=1;
				if(ddlpwfz3==1&&sjbcjs3>=gddjyxjgsj)
				{
					sjbcbz3=0;
					sjbcjs3=0;
					WDogddjyx=1;
					ddlpwfz3=2;
					sjbcbz3=1;
        }
				if(ddlpwfz3==2&&sjbcjs3>=gddjyxsj)
				{
					sjbcbz3=0;
					sjbcjs3=0;
					WDogddjyx=0;
					ddlpwfz3=1;
        }
///////////////分支4步骤执行///////////////////
				if(ddlpwfz4==1) WDoxhsbyx=1;
      }
			if(pwfs==2)
			{
				if(bsljlljsz>=60000)
				{
					bsljlljsbz=0;
					bsljlljsz=0;
					bsljll+=RAdbsssll/60.0;     //计算补水累计流量
				}
				else bsljlljsbz=1;
/////////////////////////分支1的步骤执行///////////////////
				if(ddlpwfz1==1)
				djdyyxbz=1;
				else if(ddlpwfz1==2)
				djdyyxbz=0;
				else
				djdyyxbz=1;
//////////////////////////分支2 的步骤执行/////////////////			
				if(ddlpwfz2==1) sjbcbz2=1;
				if(sjbcjs2>=pwfmyxjgsj)
				{
					sjbcbz2=0;
					sjbcjs2=0;
					ddlpwfz2=2;
				}
				if(ddlpwfz2==2)
				{
					ddlpwfz1=2;
					pwsj=3600*(bsljll/(nsbs*RAdcllssll)-RAdxhsssll*fsxs*lcpwjgsj/RAdcllssll);
					if(pwsj>=fmdkgbsjzh)
					{
						ddlpwfz1=3;
						sjbcbz2=1;
						WDopwfm=1;
						WDopwdyx=1;
          }
				}
				if(ddlpwfz2==3&&sjbcjs2>=pwsj)
				{
					sjbcbz2=0;
					sjbcjs2=0;
					ddlpwfz2=4;
					WDopwfm=0;
					WDopwdyx=0;
        }
				if(ddlpwfz2==4&&RDipwfmfk==1)
				{
					sjbcbz2=1;
					ddlpwfz2=5;
				}
				if(ddlpwfz2==5&&sjbcjs2>=15000)
				{
					sjbcbz2=0;
					sjbcjs2=0;
					ddlpwfz1=3;
				}
//////////////////////////分支3的步骤执行///////////////////////////////
				if(ddlpwfz3==1) sjbcbz3=1;
				if(ddlpwfz3==1&&sjbcjs3>=gddjyxjgsj)
				{
					sjbcbz3=0;
					sjbcjs3=0;
					WDogddjyx=1;
					ddlpwfz3=2;
					sjbcbz3=1;
        }
				if(ddlpwfz3==2&&sjbcjs3>=gddjyxsj)
				{
					sjbcbz3=0;
					sjbcjs3=0;
					WDogddjyx=0;
					ddlpwfz3=1;
        }
///////////////分支4步骤执行///////////////////
				if(ddlpwfz4==1) WDoxhsbyx=1;
      }
			if(pwfs==3)
			{	
				if(bsljlljsz>=60000)
				{
					bsljlljsbz=0;
					bsljlljsz=0;
					bsljll+=RAdbsssll/60.0;     //计算补水累计流量 VM
					bsljsj+=60;
				}
				else bsljlljsbz=1;
/////////////////////////分支1的步骤执行///////////////////
				if(ddlpwfz1==1)
				djdyyxbz=1;
				else if(ddlpwfz1==2)
				djdyyxbz=0;
				else
				djdyyxbz=1;
//////////////////////////分支2 的步骤执行/////////////////			
				if(ddlpwfz2==1)
				{
					llpwtj=bsljll/nsbs-fsxs*RAdxhsssll*bsljsj;   //计算流量排污体积
					WDojsfm=0;
					WDoxyflqfm=0;
					if(llpwtj>=0.99*pwtj)
					{
						WDojsfm=0;
						WDoxyflqfm=0;
						ddlpwfz2=2;
						ddlpwfz1=2;
					}
        }
				if(ddlpwfz2==2&&RDijsfmfk==0)
				{
					WDopwfm=1;
					WDopwdyx=1;
					ddlpwfz2=3;
					sjbcbz2=1;
        }
				if(ddlpwfz2==3&&sjbcjs2>=bslpwpwfmsdz)
				{
					sjbcbz2=0;
					sjbcjs2=0;
					WDopwfm=0;
					WDopwdyx=0;
					ddlpwfz2=4;
				}
				if(ddlpwfz2==4&&RDipwfmfk==0)
				{
					WDojsfm=1;
					WDoxyflqfm=1;
					sjbcbz2=1;
					ddlpwfz2=5;
				}
				if(ddlpwfz2==5&&sjbcjs2>=15000)
				{
					sjbcbz2=0;
					sjbcjs2=0;
					ddlpwfz1=3;
        }
//////////////////////////分支3的步骤执行///////////////////////////////
				if(ddlpwfz3==1) sjbcbz3=1;
				if(ddlpwfz3==1&&sjbcjs3>=gddjyxjgsj)
				{
					sjbcbz3=0;
					sjbcjs3=0;
					WDogddjyx=1;
					ddlpwfz3=2;
					sjbcbz3=1;
        }
				if(ddlpwfz3==2&&sjbcjs3>=gddjyxsj)
				{
					sjbcbz3=0;
					sjbcjs3=0;
					WDogddjyx=0;
					ddlpwfz3=1;
        }
///////////////分支4步骤执行///////////////////
				if(ddlpwfz4==1) WDoxhsbyx=1;
      }
			if(pwfs==4)
			{
				WDobjdyx=1;
				bjfz=1;
				sjbcbz=1;
				if(bjfz==1&&sjbcjs>=30000)
				{
					bjfz=0;
					sjbcjs=0;
					WDopwfm=1;
					WDopwdyx=1;
					bjfz=2;
				}
				if(bjfz==2&&RDipwfmfk==1) 
				{
					sjbcbz=1;
					bjfz=3;
        }
				if(bjfz==3&&sjbcjs>=qzpwsdsj)
				{
					sjbcbz=0;
					sjbcjs=0;
					WDopwfm=0;
					WDopwdyx=0;
					bjfz=4;
        }
				if(bjfz==4&&RDipwfmfk==0)
				{
					bjfz=5;
					sjbcbz=1;
				}
				if(bjfz==5&&sjbcjs>=qzpwsdjxsj)
				{
					sjbcbz=0;
					sjbcjs=0;
					bjfz=6;
        }					
				if(bjfz==6)
				{
					if(RAdddlz>bjddlsdz)
					{
						bjfz=2;
						ddlbjjsq++;
						if(ddlbjjsq<bjjsqsdz) 
						{
							WDopwfm=1;
							WDopwdyx=1;
						}
						else bjfz=7;
          }
					else
					{
						WDobjdyx=0;
						pwfs=bjzdspwfs;
					}
				}
				if(bjfz==7)
				{
					if(RAdddlz>bjddlsdz) pwfs=2;
					else 
					{
						WDobjdyx=0;
						pwfs=bjzdspwfs;
					}
				}
      }
		} 
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
////////////////////////////////////子函数///////////////////////////////////
