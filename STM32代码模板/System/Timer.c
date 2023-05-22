#include "stm32f10x.h"                  // Device header

//void Timer_Init(void)//定时器5 定时中断
//{
//  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);

//	TIM_InternalClockConfig (TIM5);

//  TIM_TimeBaseInitTypeDef TIM_TimeBaseInitstructure;
//	TIM_TimeBaseInitstructure.TIM_ClockDivision=TIM_CKD_DIV1;
//	TIM_TimeBaseInitstructure.TIM_CounterMode=TIM_CounterMode_Up  ;
//	TIM_TimeBaseInitstructure.TIM_Period=50-1;//arr
//	TIM_TimeBaseInitstructure.TIM_Prescaler=7200-1;//psc  72M/(PSC+1)/（ARR+1）  T=1/f 5ms 
//	TIM_TimeBaseInitstructure.TIM_RepetitionCounter=0;
//	TIM_TimeBaseInit(TIM5,&TIM_TimeBaseInitstructure);

//	TIM_ClearFlag (TIM5,TIM_FLAG_Update );
//	TIM_ITConfig(TIM5,TIM_IT_Update,ENABLE);
//	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
//  NVIC_InitTypeDef NVIC_Initstructure;
//	NVIC_Initstructure.NVIC_IRQChannel=TIM5_IRQn;
//	NVIC_Initstructure.NVIC_IRQChannelCmd=ENABLE;
//	NVIC_Initstructure.NVIC_IRQChannelPreemptionPriority=2;
//	NVIC_Initstructure.NVIC_IRQChannelSubPriority=1;
//	NVIC_Init(&NVIC_Initstructure);
//	
//	TIM_Cmd(TIM5,ENABLE);
//	
//}





	
	


