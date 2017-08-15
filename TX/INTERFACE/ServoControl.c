#include "ServoControl.h"
#include "stm32f4xx.h"
#include "pwm.h"

void Servo_Init(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOD,&GPIO_InitStructure);
  GPIO_ResetBits(GPIOD,GPIO_Pin_9|GPIO_Pin_11);
}

int AngleControl(int angle)
{
	return (int)(angle*160/9);
}

void DirControl(int i)
{
	switch (i)
	{
		case 0: FORWARD;break;
		case 1: BACKWARD;break;
		default: break;
	}
}

void ServoEnable(void)
{
	ServoENABLE;
}
void ServoDisable(void)
{
	ServoDISABLE;
}

void FreqControl(int fKHz)
{
	TIM4_PWM_Init(fKHz-1,84-1);
	TIM_SetCompare1(TIM4,(int)(fKHz/2));
	TIM_SetCompare2(TIM4,(int)(fKHz/2));
}
