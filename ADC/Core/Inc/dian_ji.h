#ifndef __DIAN_JI_H__
#define __DIAN_JI_H__

#include "main.h"
#include "gpio.h"
#include "my_lib.h"

#define up 1
#define down 0

extern int AutoReload_data;	//�Զ���װ��ֵ
extern int MaiChong;	//����
extern int QuanShu;	//Ȧ��

void dianji_init(void);
void dianji_set(void);
void dianji1_kongzhi(int Xfangxiang,float Xsudu,int Xzhuoqi);	//�����ٶ�
void dianji2_kongzhi(int Yfangxiang,float Ysudu,int Yzhuoqi);	//�����ٶ�

#endif

