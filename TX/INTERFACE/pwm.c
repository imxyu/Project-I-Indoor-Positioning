#include "pwm.h"
#include "stm32f4xx.h"


int i=1;

/*******************************
在主函数中加入：
TIM4_PWM_Init(2400-1,3-1)
TIM5_PWM_Init(2400-1,3-1)
TIM_SetCompare1(TIM4,1200)
……
TIM_SetCompare4(TIM5,1200)
*******************************/

//TIM11 PWM初始化
void TIM11_PWM_Init(u32 arr,u32 psc)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);	
	
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource13,GPIO_AF_TIM4);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;

	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_Init(GPIOD,&GPIO_InitStructure);
	
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;
	TIM_TimeBaseInitStructure.TIM_Period=arr;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStructure);
	
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;
	
	TIM_OC2Init(TIM4,&TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM4,TIM_OCPreload_Enable); 

	
	TIM_ARRPreloadConfig(TIM4,ENABLE);
	TIM_CtrlPWMOutputs(TIM4,ENABLE);
	
	TIM_Cmd(TIM4,ENABLE);
}

//TIM13 PWM初始化
void TIM13_PWM_Init(u32 arr,u32 psc)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM13,ENABLE);	
	
	GPIO_PinAFConfig(GPIOF,GPIO_PinSource8,GPIO_AF_TIM13);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;

	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_Init(GPIOF,&GPIO_InitStructure);
	
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;
	TIM_TimeBaseInitStructure.TIM_Period=arr;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM13,&TIM_TimeBaseInitStructure);
	
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;
	
	TIM_OC1Init(TIM13,&TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM13,TIM_OCPreload_Enable); 

	
	TIM_ARRPreloadConfig(TIM13,ENABLE);
	TIM_CtrlPWMOutputs(TIM13,ENABLE);
	
	TIM_Cmd(TIM13,ENABLE);
}

void TIM14_PWM_Init(u32 arr,u32 psc)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14,ENABLE);	
	
	GPIO_PinAFConfig(GPIOF,GPIO_PinSource9,GPIO_AF_TIM14);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;

	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_Init(GPIOF,&GPIO_InitStructure);
	
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;
	TIM_TimeBaseInitStructure.TIM_Period=arr;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM14,&TIM_TimeBaseInitStructure);
	
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;
	
	TIM_OC1Init(TIM14,&TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM14,TIM_OCPreload_Enable); 

	TIM_ARRPreloadConfig(TIM14,ENABLE);
	TIM_CtrlPWMOutputs(TIM14,ENABLE);
	
	TIM_Cmd(TIM14,ENABLE);
}

void TIM3_Timer_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE); 
	
  TIM_TimeBaseInitStructure.TIM_Period = arr; 	
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc; 
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	TIM_Cmd(TIM3,ENABLE);
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x00; 
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update) == SET)
	{
		switch (i)
		{
			case 1:						//1s for LED1
			{		
				TIM11_PWM_Init(222-1,8400-1);			//45Hz
				TIM_SetCompare2(TIM4,0.5*222);
				TIM13_PWM_Init(100-1,84-1);			//1kHz
				TIM_SetCompare1(TIM13,0.5*100);
				TIM14_PWM_Init(100-1,84-1);			//1kHz
				TIM_SetCompare1(TIM14,0.5*100);
				i=2;
				TIM3_Timer_Init(10000-1,8400-1);	//1s					
				TIM_ClearITPendingBit(TIM3,TIM_IT_Update); 	
				break;
			}
			case 2:						//10ms for LED2
			{
				TIM11_PWM_Init(100-1,84-1);				//10kHz
				TIM_SetCompare2(TIM4,0.5*100);
				TIM13_PWM_Init(153-1,8400-1);				//65Hz
				TIM_SetCompare1(TIM13,0.5*153);
				TIM14_PWM_Init(100-1,84-1);				//10kHz
				TIM_SetCompare1(TIM14,0.5*100);
				i=3;
				TIM3_Timer_Init(10000-1,8400-1);		//1s
				TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
				break;
			}
			case 3:						//1s for LED2
			{
				TIM11_PWM_Init(100-1,84-1);				//10kHz
				TIM_SetCompare2(TIM4,0.5*100);
				TIM13_PWM_Init(100-1,84-1);				//10kHz
				TIM_SetCompare1(TIM13,0.5*100);
				TIM14_PWM_Init(182-1,8400-1);				//55Hz
				TIM_SetCompare1(TIM14,0.5*182);
				i=1;
				TIM3_Timer_Init(10000-1,8400-1);	//1s
				TIM_ClearITPendingBit(TIM3,TIM_IT_Update); 
				break;
			}
		}
	}
}


