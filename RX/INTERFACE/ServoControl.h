#ifndef __SERVOCONTROL_H
#define __SERVOCONTROL_H

#include "stm32f4xx.h"
#include "sys.h"

#define FORWARD 			PDout(11)=1
#define BACKWARD 			PDout(11)=0
#define ServoENABLE 	PDout(9)=1
#define ServoDISABLE	PDout(9)=0

void Servo_Init(void);
int AngleControl(int angle);
void DirControl(int i);
void ServoEnable(void);
void ServoDisable(void);
void FreqControl(int fKHz);

#endif

