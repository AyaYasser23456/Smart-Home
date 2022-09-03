/*
 * Led.c
 *
 * Created: 6/6/2022 11:13:48 PM
 *  Author: Ahmed Hesham
 */ 

#include "Led.h"

void	H_Led_Init(u8 Local_u8_Led_Number)
{	
	M_Dio_PinMode(Local_u8_Led_Number,OUTPUT);		
}

void	H_Led_On(u8 Local_u8_Led_Number)
{
	M_Dio_PinWrite(Local_u8_Led_Number,HIGH);
}

void H_Led_Off(u8 Local_u8_Led_Number)
{
	M_Dio_PinWrite(Local_u8_Led_Number,LOW);
}

void H_Led_Blink(u8 Local_u8_Led_Number)
{
	M_Dio_PinWrite(Local_u8_Led_Number,HIGH);
	_delay_ms(200);
	M_Dio_PinWrite(Local_u8_Led_Number,LOW);
}

void H_Led_Tog(u8 Local_u8_Led_Number)
{
	M_Dio_PinTog(Local_u8_Led_Number);
}