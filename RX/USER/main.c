#include "stm32f4xx.h"
#include "delay.h"
#include "key.h"
#include "oled.h"
#include "pwm.h"
#include "mpu6050.h"
#include "inv_mpu.h"
#include "stdio.h"
#include "dac.h"
#include "bh1750.h"
#include "usart.h"
#include "adc.h"
#include "led.h"
#include "timer.h"
int a=0;
int main(void)
{

	uart_init(115200);
	delay_init(168);
	OLED_Init();
	ADC3_Init();
	KEY_Init();
	
	OLED_ShowString(0,0,"B/D");
	OLED_ShowString(0,2,"C/E");
	OLED_ShowString(0,4,"Locate");
	while(1)
	{
		Mode_Switch();
	}
}


//A 45Hz   B 65Hz   C 55Hz
