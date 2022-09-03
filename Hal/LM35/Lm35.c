/*
 * Lm35.c
 *
 * Created: 6/22/2022 3:53:12 AM
 *  Author: Ahmed Hesham
 */ 

#include "Lm35.h"

void H_Lm35_Init				(void)
{
	M_Adc_Init();
}
u16  H_Lm35_Read				(void)
{
	u16 Local_u16_ADCReading	=	M_Adc_Read();
	u16 Local_u16_Temp			=	(((u32)Local_u16_ADCReading * 500)/1023);
	return Local_u16_Temp;
}