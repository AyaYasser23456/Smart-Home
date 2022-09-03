/*
 * Timer2.c
 *
 * Created: 8/25/2022 12:21:33 AM
 *  Author: Ahmed Hesham
 */ 

#include "Timer2.h"


u32 Timer2_u32_NumberofOVFs = 0;
		 
u32 Timer2_u32_NumOfCompareMatch = 0;
		 
u8  Timer2_u8_RemTicks		= 0;

void (*Timer2_void_CallBack) (void) = NULL;


void M_Timer2_Init			(void)
{
	
	#if			TIMER2_MODE		==		NORMAL
	ClrBit(TCCR2,WGM21); ClrBit(TCCR2,WGM20);
	SetBit(TIMSK,TOIE2);
	#elif		TIMER2_MODE		==		CTC
	SetBit(TCCR2,WGM21); ClrBit(TCCR2,WGM20);
	SetBit(TIMSK,OCIE2);
	#endif

	SetBit(SREG, Ibit);
}


void  M_Timer2_SetTime		(u32 Local_u32_DesiredTime)
{
	u32 Local_u32_TickTime		=	TIMER2_PRESCALER/CRYSTAL_FREQUENCY;
	u32 Local_u32_NumberOfTicks =	((Local_u32_DesiredTime*1000)/ Local_u32_TickTime);
	#if			TIMER2_MODE		==		NORMAL
	Timer2_u32_NumberofOVFs		=	Local_u32_NumberOfTicks / 256;
	Timer2_u8_RemTicks			=	Local_u32_NumberOfTicks % 256;
	if (Timer2_u8_RemTicks != 0)
	{
		TCNT2 = 256 - Timer2_u8_RemTicks;
		Timer2_u32_NumberofOVFs++;
	}
	#elif		TIMER2_MODE		==		CTC
	u8 Local_u8_Division_Factor = 255;
	while(Local_u32_NumberOfTicks < Local_u8_Division_Factor )
	{
		Local_u8_Division_Factor--;
	}
	while(Local_u32_NumberOfTicks%Local_u8_Division_Factor != 0)
	{
		Local_u8_Division_Factor--;
	}
	Timer2_u32_NumOfCompareMatch = Local_u32_NumberOfTicks/ Local_u8_Division_Factor;
	OCR2 = Local_u8_Division_Factor -1;
	#endif
	
}


void M_Timer2_Start			(void)
{
	#if			TIMER2_PRESCALER	==		PRESCLNG_1
	ClrBit(TCCR2,CS22); ClrBit(TCCR2,CS21);	SetBit(TCCR2,CS20);
	#elif		TIMER2_PRESCALER	==		PRESCLNG_8	   
	ClrBit(TCCR2,CS22); SetBit(TCCR2,CS21);	ClrBit(TCCR2,CS20);
	#elif		TIMER2_PRESCALER	==		PRESCLNG_64		   
	ClrBit(TCCR2,CS22); SetBit(TCCR2,CS21);	SetBit(TCCR2,CS20);
	#elif		TIMER2_PRESCALER	==		PRESCLNG_256	   
	SetBit(TCCR2,CS22); ClrBit(TCCR2,CS21);	SetBit(TCCR2,CS20);
	#elif		TIMER2_PRESCALER	==		PRESCLNG_1024	   
	SetBit(TCCR2,CS22); SetBit(TCCR2,CS21);	SetBit(TCCR2,CS20);
	#endif
}

void M_Timer2_Stop			(void)
{
	ClrBit(TCCR2,CS22); ClrBit(TCCR2,CS21);	ClrBit(TCCR2,CS20);
}


void M_Pwm2_Init				(void)
{
	M_Dio_PinMode(PD7,OUTPUT);

	#if			PWM2_MODE		==		FAST_PWM
	SetBit(TCCR2,WGM21); SetBit(TCCR2,WGM20);
	#elif		PWM2_MODE		==		PHASE_CORRECT
	ClrBit(TCCR2,WGM21); SetBit(TCCR2,WGM20);
	#endif
	
	#if			OUTPUT_MODE		==		NON_INVERTED
	SetBit(TCCR2,COM21); ClrBit(TCCR2,COM20);
	#elif		OUTPUT_MODE		==		INVERTED
	SetBit(TCCR2,COM21); SetBit(TCCR2,COM20);
	#endif
	
}

void M_Pwm2_SetDutyCycle		(u8 Local_u8_DesiredDutyCycle)
{
	#if			OUTPUT_MODE		==		NON_INVERTED
	
	if(Local_u8_DesiredDutyCycle == 0)
	{
		SetBit(TCCR2,COM21); SetBit(TCCR2,COM20);
		OCR2 = (255 - ((Local_u8_DesiredDutyCycle *256)/100));
	}
	else
	{
		SetBit(TCCR2,COM21); ClrBit(TCCR2,COM20);
		OCR2 = (((Local_u8_DesiredDutyCycle * 256) / 100) - 1);
	}
	
	#elif		OUTPUT_MODE		==		INVERTED
	if(Local_u8_DesiredDutyCycle == 100)
	{
		SetBit(TCCR2,COM21); ClrBit(TCCR2,COM20);
		OCR2 = (((Local_u8_DesiredDutyCycle * 256) / 100) - 1);
	}
	else
	{
		SetBit(TCCR2,COM21); SetBit(TCCR2,COM20);
		OCR2 = (255 - ((Local_u8_DesiredDutyCycle *256)/100));
	}
	#endif
	
}

void M_Pwm2_Start				(void)
{
	M_Timer2_Start();
	M_Dio_PinMode(PD7,OUTPUT);
}

void M_Pwm2_Stop				(void)
{
	M_Timer2_Stop();
	M_Dio_PinMode(PD7,INPUT);
}





void M_Timer2_SetCallBack	(void (*Local_void_ptr) (void))
{
	Timer2_void_CallBack = Local_void_ptr;
}
//
// #if			TIMER0_MODE		==		NORMAL
// ISR(TIMER0_OVF_vect)
// {
// 	static u32 Local_u32_OVFCounter = 0;
// 	Local_u32_OVFCounter  ++;
// 	if (Local_u32_OVFCounter  == Timer0_u32_NumberofOVFs)
// 	{
// 		Timer0_void_CallBack();
// 		Local_u32_OVFCounter  =	0;
// 		TCNT0 = 256 - Timer0_u8_RemTicks;
//
// 	}
// }
// #elif		TIMER0_MODE		==		CTC
// ISR(TIMER0_COMP_vect)
// {
// 	static u32 Local_u32_CTCCounter = 0;
// 	Local_u32_CTCCounter  ++;
// 	if (Local_u32_CTCCounter  == Timer0_u32_NumOfCompareMatch)
// 	{
// 		Timer0_void_CallBack();
// 		Local_u32_CTCCounter  =	0;
// 	}
// }
// #endif