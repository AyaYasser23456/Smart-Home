/*
 * Timer1.c
 *
 * Created: 6/29/2022 4:39:45 AM
 *  Author: Ahmed Hesham
 */ 

#include "Timer1.h"

void M_Pwm1_Init				(void)
{
	
 	SetBit(DDRD,5);	
 	
 	SetBit(TCCR1A,COM1A1);
	ClrBit(TCCR1A,COM1A0);
	
	SetBit(TCCR1B,WGM13);
	SetBit(TCCR1B,WGM12);
	SetBit(TCCR1A,WGM11);
	ClrBit(TCCR1A,WGM10);
	

	
}
void M_Pwm1_SetDutyCycle		(f32 Local_f32_DesiredDutyCycle)
{
	OCR1A = (((Local_f32_DesiredDutyCycle * ICR1)/100)-1);
}
void M_Pwm1_SetFrequency		(u16 Local_u16_DesiredFrequency)
{
	ICR1 = ((CRYSTAL_FREQUENCY * 1000000) / (Local_u16_DesiredFrequency * TIMER1_PRESCALER));
}
void M_Pwm1_Start				(void)
{
	#if		TIMER1_PRESCALER == PRESCLNG_64
	ClrBit(TCCR1B,CS12);
	SetBit(TCCR1B,CS11);
	SetBit(TCCR1B,CS10);
	
	#elif	TIMER1_PRESCALER == PRESCLNG_256
	SetBit(TCCR1B,CS12);
	ClrBit(TCCR1B,CS11);
	ClrBit(TCCR1B,CS10);
	
	#elif	TIMER1_PRESCALER == PRESCLNG_1024
	SetBit(TCCR1B,CS12);
	ClrBit(TCCR1B,CS11);
	SetBit(TCCR1B,CS10);
	
	#endif
	
}
void M_Pwm1_Stop				(void)
{
	ClrBit(TCCR1B,CS12);
	ClrBit(TCCR1B,CS11);
	ClrBit(TCCR1B,CS10);
}
