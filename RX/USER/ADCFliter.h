#ifndef __ADCFLITER_H
#define __ADCFLITER_H

#include "stm32f4xx.h"
#define NM 3

typedef struct
{
  int ad_valu[4][5];
  int ad_valu1[4];
  int ad_sum[4];
  int AD_V[4][3];
  int AD_value[4];
  int AD_sum[4];
  int AD1;
  int AD2;
}Adc_info;

int ADC_Fliter(void);

#endif