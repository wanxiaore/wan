#ifndef __DEFINE_H
#define __DEFINE_H	 
#include "sys.h"

float RAddyz;  //��ѹֵ
float RAddlz;  //����ֵ
float RAdddlz;  //�絼��ֵ
float RAdphz;   //PHֵ
float RAdrswdcgq;  //��ˮ�¶ȴ�����
float RAdcswdcgq;  //��ˮ�¶ȴ�����
float RAdhjwdcgq;  //�����¶ȴ�����
float RAdhjsdcgq;  //����ʪ�ȴ�����
float RAdbsssll;  //��ˮ˲ʱ������
float RAdzd;      //�Ƕ�
float RAdorp;     //ORP
float RAdpwssll;  //����˲ʱ����
float RAdcllssll;  //������˲ʱ����
float RAdxhsssll;  //ѭ��ˮ˲ʱ����

u8 djdyyxbz=0;    //����Դ���б�־
float WAddjdyz=0;  //д����Դֵ

u8 WDopwfm;  //���۷���
u8 WDojsfm;  //��ˮ����
u8 WDogddjyx;  //�ε��������
u8 WDoxhsbyx;  //ѭ��ˮ������
u8 WDobjdyx;  //����������
u8 WDopwdyx; //���۵�����
u8 WDojlbyx;   //����������
u8 WDoxyflqfm;  //��Һ����������

#define WDopwfm DO0
#define	WDojsfm DO1
#define	WDogddjyx DO2
#define	WDoxhsbyx DO3
#define	WDobjdyx DO4
#define	WDopwdyx DO5
#define	WDojlbyx DO6

u8 RDipwfmfk;  //���۷��ŷ���
u8 RDijsfmfk;  //��ˮ���ŷ���
u8 RDigddjfk;  //�ε��������
u8 RDisbdjbh;  //ˮ�õ������
u8 RDidjdybh;  //����Դ����
u8 RDiv24dybh; //24V��Դ����
u8 RDijlbbh;   //�����ñ���
u8 RDijswwjfk; //������λ�Ʒ���

#define RDipwfmfk DI0
#define	RDijsfmfk DI1
#define	RDigddjfk DI2
#define	RDisbdjbh DI3
#define	RDidjdybh DI4
#define	RDiv24dybh DI5
#define	RDijlbbh DI6
#define	RDijswwjfk DI7


/////////////////////����ʱ��//////////////////
u32 gddjyxjgsj=0; //�ε�������м��ʱ��
u32 gddjyxsj=0;   //�ε��������ʱ��
u32 pwfmyxsj=0;   //���۷�������ʱ��
u32 pwfmyxjgsj=0; //���۷������м��ʱ��
u32 djdyhyscz=0;  //����Դ��ѹ���ֵ
u32 bsljll=0;     //��ˮ�ۼ�����
u32 pwsj=0;       //����ʱ��
u32 qzpwsdsj=0,qzpwsdjxsj=0;  //ǿ�������趨ʱ��  ǿ�������趨��Ъʱ��
u32 fmdkgbsjzh=0;  //���Ŵ򿪹رչ���ʱ���ܺ�
float llpwtj=0,pwtj=0,bsljsj=0;    //�����������VB   �������V1    ��ˮ�ۼ�ʱ��
float sjpwfsxpwsj=0;   //ʱ�����۷�ʽ������ʱ��
u32 bslpwpwfmsdz=0;   //��ˮ�����������趨ʱ��

/////////////////////��־λ////////////////////
u8 pwfsyxbz=0;   //���۷�ʽ���б�־
u8 ddlpwfz1=0,ddlpwfz2=0,ddlpwfz3=0,ddlpwfz4=0;  //�絼�����۷�֧�����־
u8 bjfz=0;       //������ִ֧�в��� 
u8 pwfs=0,bjzdspwfs=0;    //���۷�ʽ   �����ж�ʱ���۷�ʽ
u32 ddlbjjsq=0;    //�絼�ʱ���������  

///////////////////�������///////////////////
float ddlsdsx=0;   //�絼���趨����
float ddlsdxx=0;   //�絼���趨����
u32 bjddlsdz=0,bjjsqsdz=0;    //�����絼�ʴﵽҪ���趨ֵ   �����絼��δ��Ҫ�������趨����ֵ
u32 gddlbjz=0,gzdbjz=0;  //�ߵ絼�ʱ���ֵ   ���Ƕȱ���ֵ
u16 nsbs=0;            //Ũ������
u16 fsxs=0;            //����ϵ��
u32 lcpwjgsj=0;        //��������ʱ����
float sddjdyz=0;       //�趨����Դֵ
//////////////////////24C02�洢����///////////////////////////
/*[0][1]=0xf9 0x7c
  [2][3]�ߵ�������ֵ    [4][5]�͵�������ֵ    [6][7]�ߵ�ѹ����ֵ   [8][9]�͵�ѹ����ֵ   [10][11]��PH����ֵ   [12][13]	��PH����ֵ   [14][15]�ߵ絼�ʱ���ֵ   [16][17]�͵絼�ʱ���ֵ
	[18][19]���Ƕȱ���ֵ   [20][21]	���Ƕȱ���ֵ    [22][23]����Դ�Զ�����ֵ   [24][25]��ѹ��ѹֵ   [26][27]�ε�������м��ʱ��   [28][29]��ˮ������ȫ������ʱ��               
  [30][31]��ˮ������ȫ������ʱ�� 	    [32][33]���۷������м��ʱ��    [34][35]���۷�����ȫ������ʱ��   [36][37]�絼����������   [38][39]�絼����������   [40][41]ǿ����������ʱ��
  [42][43]����ǿ�����۴���        [44][45]ǿ�����ۼ��ʱ��         [46][47]����Դ����������      [48][49]����Դ��������ѹ    [50][51]��ˮ����������    [52][53]��ˮ����������
  [54][55]��������������          [56][57]��������������            [58][59]����������������           [60][61]����������������       [62][63]ѭ��ˮ������������    [64][65]ѭ��ˮ������������
  [66][67]ϵͳ�ӳ�����ʱ��        [68][69]Ũ������                   [70][71]����ʱ��                 [72][73]��ȴ������ϵ��          [72][73]��ˮ����������ʱ��  */
u8 buffer[9];
#define SIZE sizeof(buffer)
u8 datasave[SIZE];

#endif
