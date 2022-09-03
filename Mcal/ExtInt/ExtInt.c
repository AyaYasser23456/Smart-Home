/*
 * ExtInt.c
 *
 * Created: 6/15/2022 10:19:52 PM
 *  Author: elwady
 */ 

#include "ExtInt.h"
#include <stdio.h>


void (*ExtInt_void_CallBackInt0) (void) = NULL; 
void (*ExtInt_void_CallBackInt1) (void) = NULL;
void (*ExtInt_void_CallBackInt2) (void) = NULL;



void M_ExtInt_Init (u8 Local_u8_IntNumber)
{
	
	/* Step 1	->		Choose Sense Control */
	switch(Local_u8_IntNumber)
	{	
		case INT0:
		#if			SENSE_CONTROL_0		==		LOW_LEVEL
		ClrBit(MCUCR,ISC00);
		ClrBit(MCUCR,ISC01);
		#elif		SENSE_CONTROL_0		==		ANY_CHANGE	
		SetBit(MCUCR,ISC00);
		ClrBit(MCUCR,ISC01);
		#elif		SENSE_CONTROL_0		==		FALLING_EDGE
		ClrBit(MCUCR,ISC00);
		SetBit(MCUCR,ISC01);
		#elif		SENSE_CONTROL_0		==		RISING_EDGE
		SetBit(MCUCR,ISC00);
		SetBit(MCUCR,ISC01);
		#endif
		break;
		
		case INT1:
		#if			SENSE_CONTROL_1		==		LOW_LEVEL
		ClrBit(MCUCR,ISC10);
		ClrBit(MCUCR,ISC11);
		#elif		SENSE_CONTROL_1		==		ANY_CHANGE
		SetBit(MCUCR,ISC10);
		ClrBit(MCUCR,ISC11);
		#elif		SENSE_CONTROL_1		==		FALLING_EDGE
		ClrBit(MCUCR,ISC10);
		SetBit(MCUCR,ISC11);
		#elif		SENSE_CONTROL_1		==		RISING_EDGE
		SetBit(MCUCR,ISC10);
		SetBit(MCUCR,ISC11);
		#endif
		break;
		
		case INT2:
		#if			SENSE_CONTROL_2		==		FALLING_EDGE
		ClrBit(MCUCR,ISC2);
		#elif		SENSE_CONTROL_2		==		RISING_EDGE
		SetBit(MCUCSR,ISC2);
		#endif
		break;
		
		default: 
		break;
	}
	/* Step 2	->		Enable Peripheral Interrupt */
	switch(Local_u8_IntNumber)
	{
		case INT0:	SetBit(GICR,INT0);		break;
		case INT1:	SetBit(GICR,INT1);		break;
		case INT2:	SetBit(GICR,INT2);		break;
		default:							break;		
	}
	
	
	/* Step 3	->		Enable Global Interrupt */
	SetBit(SREG,Ibit);
}

void M_ExtInt_SetCallBackInt0 (void (*Local_void_ptr) (void))
{
	ExtInt_void_CallBackInt0 = Local_void_ptr;
}

void M_ExtInt_SetCallBackInt1 (void (*Local_void_ptr) (void))
{
	ExtInt_void_CallBackInt1 = Local_void_ptr;
}

void M_ExtInt_SetCallBackInt2 (void (*Local_void_ptr) (void))
{
	ExtInt_void_CallBackInt2 = Local_void_ptr;
}
// 
// ISR(INT0_vect)
// {
// 	ExtInt_void_CallBackInt0();
// }
// 
// ISR(INT1_vect)
// {
// 	ExtInt_void_CallBackInt1();
// }
// 
// ISR(INT2_vect)
// {
// 	ExtInt_void_CallBackInt2();
// }