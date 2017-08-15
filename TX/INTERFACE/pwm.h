#ifndef __PWM_H
#define __PWM_H
#include "stm32f4xx.h"

void TIM3_Timer_Init(u16 arr,u16 psc);
void TIM11_PWM_Init(u32 arr,u32 psc);
void TIM13_PWM_Init(u32 arr,u32 psc);
void TIM14_PWM_Init(u32 arr,u32 psc);
#endif
