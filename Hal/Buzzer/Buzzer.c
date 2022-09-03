/*
 * Buzzer.c
 *
 * Created: 6/7/2022 12:01:53 AM
 *  Author: Ahmed Hesham
 */ 

#include "Buzzer.h"

void	H_Buzzer_Init(void)
{
	M_Dio_PinMode(BUZZERPIN,OUTPUT);
}

void	H_Buzzer_On(void)
{
	M_Dio_PinWrite(BUZZERPIN,HIGH);
}

void H_Buzzer_Off(void)
{
	M_Dio_PinWrite(BUZZERPIN,LOW);
}

void H_Buzzer_Beeb(void)
{
	M_Dio_PinWrite(BUZZERPIN,HIGH);
	_delay_ms(200);
	M_Dio_PinWrite(BUZZERPIN,LOW);
}

void H_Buzzer_Tog(void)
{
	M_Dio_PinTog(BUZZERPIN);
}