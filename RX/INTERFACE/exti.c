//#include "exti.h"
//#include "stm32f4xx.h"
//#include "delay.h"
//#include "pwm.h"
//#include "ServoControl.h"

//u32 t,dir,angle;

//void EXTI_PulseCnt_Init(void)
//{
//	NVIC_InitTypeDef   NVIC_InitStructure;
//	EXTI_InitTypeDef   EXTI_InitStructure;
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);				//使能SYSCFG时钟
//	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource1);	//配置GPIO与中断线的映射关系
//	//结构体配置
//	EXTI_InitStructure.EXTI_Line=EXTI_Line1;											//中断线1
//	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;							//配置为中断模式
//	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;					//配置中断触发方式
//	EXTI_InitStructure.EXTI_LineCmd=ENABLE;												//使能中断线
//	EXTI_Init(&EXTI_InitStructure);																//初始化外部中断
//	//中断分组配置
//	NVIC_InitStructure.NVIC_IRQChannel=EXTI1_IRQn;								//使能外部中断2
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x03;		//配置抢占优先级
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x00;						//配置相应优先级
//	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;									//使能外部中断通道
//	NVIC_Init(&NVIC_InitStructure);																//初始化中断分组
//}

//void EXTI1_IRQHandler(void)
//{
//	t++;
//	if (t>=AngleControl(360))
//	{
//		TIM_Cmd(TIM4,DISABLE);
//		delay_ms(100);
//		t=0;
//		TIM_Cmd(TIM4,ENABLE);
//		if (dir==1)
//			dir=0;
//		else if (dir==0)
//			dir=1;
//		DirControl(dir);
//	}
//	EXTI_ClearITPendingBit(EXTI_Line1);
//}
//	

