#ifndef __OCT_H
#define __OCT_H	
#include "sys.h" 
extern u32 oct_count;    //ϵͳ�������ڼ�ʱ
extern u32 sjbcjs,sjbcjs2,sjbcjs3;    //ʱ�䱣�ּ���
extern u16 sjbcbz,sjbcbz2,sjbcbz3;    //ʱ�䱣�ֱ�־
extern u32 bsljlljsbz,bsljlljsz;      //��ˮ�ۼ���������ֵ   ��ˮ�ۼ�����������־
void TIM5_Int_Init(u16 arr,u16 psc);
#endif
