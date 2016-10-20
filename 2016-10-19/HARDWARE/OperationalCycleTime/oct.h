#ifndef __OCT_H
#define __OCT_H	
#include "sys.h" 
extern u32 oct_count;    //系统运行周期计时
extern u32 sjbcjs,sjbcjs2,sjbcjs3;    //时间保持计数
extern u16 sjbcbz,sjbcbz2,sjbcbz3;    //时间保持标志
extern u32 bsljlljsbz,bsljlljsz;      //补水累计流量计数值   补水累计流量计数标志
void TIM5_Int_Init(u16 arr,u16 psc);
#endif
