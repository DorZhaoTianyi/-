#include "dian_ji.h"
#include "tim.h"

void dianji_init(void)
{
}
void  dianji1_kongzhi(int Xfangxiang,float Xsudu,int Xzhuoqi)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, Xfangxiang);
	__HAL_TIM_SetAutoreload(&htim2,Xsudu);		//�����ٶȿ���
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1, (Xsudu/2));//��������  �ò���
	QuanShu=Xzhuoqi;
}

void  dianji2_kongzhi(int Yfangxiang,float Ysudu,int Yzhuoqi)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, Yfangxiang);
	__HAL_TIM_SetAutoreload(&htim3,Ysudu);		//�����ٶȿ���
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, (Ysudu/2));//��������  �ò���
	QuanShu=Yzhuoqi;
}