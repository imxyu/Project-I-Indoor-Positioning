#include "stm32f4xx.h"
#include "delay.h"
#include "key.h"
#include "oled.h"
#include "pwm.h"
#include "stdio.h"
#include "dac.h"
#include "bh1750.h"
#include "usart.h"
#include "adc.h"
#include "led.h"


char lx_buff[20];

int main(void)
{
	int key=0;
	uart_init(115200);
	delay_init(168);
	OLED_Init();
	ADC3_Init();
	LED_Init();
	KEY_Init();
	TIM3_Timer_Init(100-1,8400-1);
//	TIM11_PWM_Init(100-1,84-1);
//	TIM13_PWM_Init(100-1,84-1);
//	TIM14_PWM_Init(100-1,84-1);
	
//	TIM_SetCompare1(TIM11,100);
//	TIM_SetCompare1(TIM13,100);
//	TIM_SetCompare1(TIM14,100);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	OLED_ShowString(0,0,"Sparking");
	while(1)
	{
	}
}



