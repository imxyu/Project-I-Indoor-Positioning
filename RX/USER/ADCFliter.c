#include "ADCFliter.h"
#include "adc.h"

int ADC_Fliter(void)    
{
	Adc_info	Adc;
    int i,j,k,temp;
    for(i=0;i<5;i++)
    {
        Adc.ad_valu[0][i] =Get_Adc_Average(ADC_Channel_0,10);
    }
        for(j=0;j<4;j++)
        {
            for(k=0;k<4-j;k++)
            {
                if(Adc.ad_valu[0][k] > Adc.ad_valu[0][k+1])
                {
                    temp = Adc.ad_valu[0][k+1];
                    Adc.ad_valu[0][k+1] = Adc.ad_valu[0][k];
                    Adc.ad_valu[0][k] = temp;
                }
            }
        }
    
    
    
        Adc.ad_sum[0] = Adc.ad_valu[0][1] + Adc.ad_valu[0][2] + Adc.ad_valu[0][3];
        Adc.ad_valu1[0] = Adc.ad_sum[0] / 3;
    
    
    for(i=0;i<NM-1;i++)
    {
        Adc.AD_V[0][i] = Adc.AD_V[0][i + 1]; 
    }
    
    
        Adc.AD_V[0][NM-1] = Adc.ad_valu1[0];
    
    
    for(i=0;i<NM;i++)
    {
        Adc.AD_sum[0] += Adc.AD_V[0][i];
       
    }
    
    
        Adc.AD_value[0] = Adc.AD_sum[0] / NM;
        Adc.AD_sum[0]= 0;
		
		return Adc.AD_value[0];
    


}