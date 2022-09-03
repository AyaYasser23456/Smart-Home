/*
 * Timer0.c
 *
 * Created: 6/22/2022 5:15:29 AM
 *  Author: Ahmed Hesham
 */ 

#include "Timer0.h"


u32 Timer0_u32_NumberofOVFs = 0;

u32 Timer0_u32_NumOfCompareMatch = 0;

u8  Timer0_u8_RemTicks		= 0;

void (*Timer0_void_CallBack) (void) = NULL;


void M_Timer0_Init			(void)
{
	
	#if			TIMER0_MODE		==		NORMAL
	ClrBit(TCCR0,WGM01); ClrBit(TCCR0,WGM00); 	
	SetBit(TIMSK,TOIE0);
	#elif		TIMER0_MODE		==		CTC	
	SetBit(TCCR0,WGM01); ClrBit(TCCR0,WGM00); 	
	SetBit(TIMSK,OCIE0);
	#endif

	SetBit(SREG, Ibit);
}


void  M_Timer0_SetTime		(u32 Local_u32_DesiredTime)
{
	u32 Local_u32_TickTime		=	TIMER0_PRESCALER/CRYSTAL_FREQUENCY;
	u32 Local_u32_NumberOfTicks =	((Local_u32_DesiredTime*1000)/ Local_u32_TickTime);
	#if			TIMER0_MODE		==		NORMAL
	Timer0_u32_NumberofOVFs		=	Local_u32_NumberOfTicks / 256;	
	Timer0_u8_RemTicks			=	Local_u32_NumberOfTicks % 256;
	if (Timer0_u8_RemTicks != 0)
	{
		TCNT0 = 256 - Timer0_u8_RemTicks;
		Timer0_u32_NumberofOVFs++;
	}
	#elif		TIMER0_MODE		==		CTC	
	u8 Local_u8_Division_Factor = 255;
	while(Local_u32_NumberOfTicks < Local_u8_Division_Factor )
	{
		Local_u8_Division_Factor--; 
	}
	while(Local_u32_NumberOfTicks%Local_u8_Division_Factor != 0)
	{
		Local_u8_Division_Factor--;
	}
	Timer0_u32_NumOfCompareMatch = Local_u32_NumberOfTicks/ Local_u8_Division_Factor;
	OCR0 = Local_u8_Division_Factor -1;
	#endif
	
}


void M_Timer0_Start			(void)
{
	#if			TIMER0_PRESCALER	==		PRESCLNG_1
	ClrBit(TCCR0,CS02); ClrBit(TCCR0,CS01);	SetBit(TCCR0,CS00);
	#elif		TIMER0_PRESCALER	==		PRESCLNG_8
	ClrBit(TCCR0,CS02); SetBit(TCCR0,CS01);	ClrBit(TCCR0,CS00);
	#elif		TIMER0_PRESCALER	==		PRESCLNG_64
	ClrBit(TCCR0,CS02); SetBit(TCCR0,CS01);	SetBit(TCCR0,CS00);
	#elif		TIMER0_PRESCALER	==		PRESCLNG_256
	SetBit(TCCR0,CS02); ClrBit(TCCR0,CS01);	SetBit(TCCR0,CS00);
	#elif		TIMER0_PRESCALER	==		PRESCLNG_1024		
	SetBit(TCCR0,CS02); ClrBit(TCCR0,CS01);	SetBit(TCCR0,CS00);
	#endif
}

void M_Timer0_Stop			(void)
{
	ClrBit(TCCR0,CS02); ClrBit(TCCR0,CS01);	ClrBit(TCCR0,CS00);
}


void M_Pwm0_Init				(void)
{
	M_Dio_PinMode(PB3,OUTPUT);

	#if			PWM0_MODE		==		FAST_PWM
	SetBit(TCCR0,WGM01); SetBit(TCCR0,WGM00);
	#elif		PWM0_MODE		==		PHASE_CORRECT
	ClrBit(TCCR0,WGM01); SetBit(TCCR0,WGM00);
	#endif
	
	#if			OUTPUT_MODE		==		NON_INVERTED
	SetBit(TCCR0,COM01); ClrBit(TCCR0,COM00);
	#elif		OUTPUT_MODE		==		INVERTED
	SetBit(TCCR0,COM01); SetBit(TCCR0,COM00);
	#endif
	
}

void M_Pwm0_SetDutyCycle		(u8 Local_u8_DesiredDutyCycle)
{
	#if			OUTPUT_MODE		==		NON_INVERTED
	
	if(Local_u8_DesiredDutyCycle == 0)
	{
		SetBit(TCCR0,COM01); SetBit(TCCR0,COM00);
		OCR0 = (255 - ((Local_u8_DesiredDutyCycle *256)/100));
	}
	else
	{
		SetBit(TCCR0,COM01); ClrBit(TCCR0,COM00);
		OCR0 = (((Local_u8_DesiredDutyCycle * 256) / 100) - 1);
	}
	
	#elif		OUTPUT_MODE		==		INVERTED
	if(Local_u8_DesiredDutyCycle == 100)
	{
		SetBit(TCCR0,COM01); ClrBit(TCCR0,COM00);
		OCR0 = (((Local_u8_DesiredDutyCycle * 256) / 100) - 1);
	}
	else
	{
		SetBit(TCCR0,COM01); SetBit(TCCR0,COM00);
		OCR0 = (255 - ((Local_u8_DesiredDutyCycle *256)/100));
	}
	#endif
	
}

void M_Pwm0_Start				(void)
{
	M_Timer0_Start();
}

void M_Pwm0_Stop				(void)
{
	M_Timer0_Stop();
}









void M_Timer0_SetCallBack	(void (*Local_void_ptr) (void))
{
	Timer0_void_CallBack = Local_void_ptr;
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