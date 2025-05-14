#include "dian_ji.h"
#include "tim.h"

void dianji_init(void)
{
}
void  dianji1_kongzhi(int Xfangxiang,float Xsudu,int Xzhuoqi)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, Xfangxiang);
	__HAL_TIM_SetAutoreload(&htim2,Xsudu);		//设置速度快慢
	__HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_1, (Xsudu/2));//设置脉冲  用不到
	QuanShu=Xzhuoqi;
}

void  dianji2_kongzhi(int Yfangxiang,float Ysudu,int Yzhuoqi)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, Yfangxiang);
	__HAL_TIM_SetAutoreload(&htim3,Ysudu);		//设置速度快慢
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, (Ysudu/2));//设置脉冲  用不到
	QuanShu=Yzhuoqi;
}