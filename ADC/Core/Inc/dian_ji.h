#ifndef __DIAN_JI_H__
#define __DIAN_JI_H__

#include "main.h"
#include "gpio.h"
#include "my_lib.h"

#define up 1
#define down 0

extern int AutoReload_data;	//自动重装载值
extern int MaiChong;	//脉冲
extern int QuanShu;	//圈数

void dianji_init(void);
void dianji_set(void);
void dianji1_kongzhi(int Xfangxiang,float Xsudu,int Xzhuoqi);	//方向，速度
void dianji2_kongzhi(int Yfangxiang,float Ysudu,int Yzhuoqi);	//方向，速度

#endif

