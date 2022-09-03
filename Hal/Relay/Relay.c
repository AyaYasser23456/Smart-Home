/*
 * Relay.c
 *
 * Created: 8/29/2022 4:03:27 PM
 *  Author: Ahmed Hesham
 */ 

#include "Relay.h"

void	H_Relay_Init		(void)
{
	M_Dio_PinMode(RELAY_PIN,OUTPUT);	
}

void	H_Relay_On			(void)
{
	M_Dio_PinWrite(RELAY_PIN,HIGH);
}

void	H_Relay_Off		    (void)
{
	M_Dio_PinWrite(RELAY_PIN,LOW);
}
