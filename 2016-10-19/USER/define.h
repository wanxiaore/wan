#ifndef __DEFINE_H
#define __DEFINE_H	 
#include "sys.h"

float RAddyz;  //电压值
float RAddlz;  //电流值
float RAdddlz;  //电导率值
float RAdphz;   //PH值
float RAdrswdcgq;  //入水温度传感器
float RAdcswdcgq;  //出水温度传感器
float RAdhjwdcgq;  //环境温度传感器
float RAdhjsdcgq;  //环境湿度传感器
float RAdbsssll;  //补水瞬时传感器
float RAdzd;      //浊度
float RAdorp;     //ORP
float RAdpwssll;  //排污瞬时流量
float RAdcllssll;  //处理量瞬时流量
float RAdxhsssll;  //循环水瞬时流量

u8 djdyyxbz=0;    //电解电源运行标志
float WAddjdyz=0;  //写电解电源值

u8 WDopwfm;  //排污阀门
u8 WDojsfm;  //进水阀门
u8 WDogddjyx;  //刮刀电机运行
u8 WDoxhsbyx;  //循环水泵运行
u8 WDobjdyx;  //报警灯运行
u8 WDopwdyx; //排污灯运行
u8 WDojlbyx;   //计量泵运行
u8 WDoxyflqfm;  //悬液分离器阀门

#define WDopwfm DO0
#define	WDojsfm DO1
#define	WDogddjyx DO2
#define	WDoxhsbyx DO3
#define	WDobjdyx DO4
#define	WDopwdyx DO5
#define	WDojlbyx DO6

u8 RDipwfmfk;  //排污阀门反馈
u8 RDijsfmfk;  //进水阀门反馈
u8 RDigddjfk;  //刮刀电机保护
u8 RDisbdjbh;  //水泵电机保护
u8 RDidjdybh;  //电解电源保护
u8 RDiv24dybh; //24V电源保护
u8 RDijlbbh;   //计量泵保护
u8 RDijswwjfk; //加酸物位计反馈

#define RDipwfmfk DI0
#define	RDijsfmfk DI1
#define	RDigddjfk DI2
#define	RDisbdjbh DI3
#define	RDidjdybh DI4
#define	RDiv24dybh DI5
#define	RDijlbbh DI6
#define	RDijswwjfk DI7


/////////////////////运行时间//////////////////
u32 gddjyxjgsj=0; //刮刀电机运行间隔时间
u32 gddjyxsj=0;   //刮刀电机运行时间
u32 pwfmyxsj=0;   //排污阀门运行时间
u32 pwfmyxjgsj=0; //排污阀门运行间隔时间
u32 djdyhyscz=0;  //电解电源恒压输出值
u32 bsljll=0;     //补水累计流量
u32 pwsj=0;       //排污时间
u32 qzpwsdsj=0,qzpwsdjxsj=0;  //强制排污设定时间  强制排污设定间歇时间
u32 fmdkgbsjzh=0;  //阀门打开关闭过程时间总和
float llpwtj=0,pwtj=0,bsljsj=0;    //流量排污体积VB   排污体积V1    补水累计时间
float sjpwfsxpwsj=0;   //时间排污方式下排污时间
u32 bslpwpwfmsdz=0;   //补水量排污排污设定时间

/////////////////////标志位////////////////////
u8 pwfsyxbz=0;   //排污方式运行标志
u8 ddlpwfz1=0,ddlpwfz2=0,ddlpwfz3=0,ddlpwfz4=0;  //电导率排污分支步骤标志
u8 bjfz=0;       //报警分支执行步骤 
u8 pwfs=0,bjzdspwfs=0;    //排污方式   报警中断时排污方式
u32 ddlbjjsq=0;    //电导率报警计数器  

///////////////////设置相关///////////////////
float ddlsdsx=0;   //电导率设定上限
float ddlsdxx=0;   //电导率设定下限
u32 bjddlsdz=0,bjjsqsdz=0;    //报警电导率达到要求设定值   报警电导率未达要求技数器设定上限值
u32 gddlbjz=0,gzdbjz=0;  //高电导率报警值   高浊度报警值
u16 nsbs=0;            //浓缩倍数
u16 fsxs=0;            //风损系数
u32 lcpwjgsj=0;        //两次排污时间间隔
float sddjdyz=0;       //设定电解电源值
//////////////////////24C02存储数据///////////////////////////
/*[0][1]=0xf9 0x7c
  [2][3]高电流报警值    [4][5]低电流报警值    [6][7]高电压报警值   [8][9]低电压报警值   [10][11]高PH报警值   [12][13]	低PH报警值   [14][15]高电导率报警值   [16][17]低电导率报警值
	[18][19]高浊度报警值   [20][21]	低浊度报警值    [22][23]电解电源自动电流值   [24][25]恒压电压值   [26][27]刮刀电机运行间隔时间   [28][29]进水阀门完全打开所需时间               
  [30][31]进水阀门完全打开所需时间 	    [32][33]排污阀门运行间隔时间    [34][35]排污阀门完全打开所需时间   [36][37]电导率排污上限   [38][39]电导率排污下限   [40][41]强制排污运行时间
  [42][43]连续强制排污次数        [44][45]强制排污间隔时间         [46][47]电解电源最大输出电流      [48][49]电解电源最大输出电压    [50][51]补水流量计上限    [52][53]补水流量计下限
  [54][55]排污流量计上限          [56][57]排污流量计下限            [58][59]处理量流量计上限           [60][61]处理量流量计下限       [62][63]循环水量流量计上限    [64][65]循环水量流量计下限
  [66][67]系统延迟启动时间        [68][69]浓缩倍数                   [70][71]排污时间                 [72][73]冷却塔风损系数          [72][73]补水排污下排污时间  */
u8 buffer[9];
#define SIZE sizeof(buffer)
u8 datasave[SIZE];

#endif
