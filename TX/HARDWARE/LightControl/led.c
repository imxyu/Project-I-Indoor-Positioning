#include "led.h"
#include "sys.h"
#include "delay.h"


//PF0-PF2
void LED_Init(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_2|GPIO_Pin_4;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOF, &GPIO_InitStructure);
  GPIO_ResetBits(GPIOF,GPIO_Pin_0|GPIO_Pin_2|GPIO_Pin_4);
} 

void L1Control(void)
{
	PFout(0)=0;
	delay_ms(1);
	
	PFout(0)=1;
	delay_ms(1);
	
	PFout(0)=0;
	delay_ms(1);
	
	PFout(0)=1;
	delay_ms(2);
	
	PFout(0)=0;
}

void L2Control(void)
{
	PFout(2)=0;
	delay_ms(1);
	
	PFout(2)=1;
	delay_ms(1);
	
	PFout(2)=0;
	delay_ms(1);
	
	PFout(2)=1;
	delay_ms(1);
	
	PFout(2)=0;
	delay_ms(1);
	
	PFout(2)=1;
	delay_ms(4);
	
	PFout(2)=0;
}

void L3Control(void)
{
	PFout(4)=0;
	delay_ms(1);
	
	PFout(4)=1;
	delay_ms(1);
	
	PFout(4)=0;
	delay_ms(1);
	
	PFout(4)=1;
	delay_ms(1);
	
	PFout(4)=0;
	delay_ms(1);
	
	PFout(4)=1;
	delay_ms(1);
	
	PFout(4)=0;
	delay_ms(1);
	
	PFout(4)=1;
	delay_ms(6);
	
	PFout(4)=0;
}

void Hz40_In_Turn(void)
{
	PFout(0)=1;
	PFout(2)=0;
	PFout(4)=0;
	delay_us(8333);
	
	PFout(0)=0;
	PFout(2)=1;
	PFout(4)=0;
	delay_us(8333);
	
	PFout(0)=0;
	PFout(2)=0;
	PFout(4)=1;
	delay_us(8333);
}