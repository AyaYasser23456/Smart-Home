/*
 * Led.h
 *
 * Created: 6/6/2022 11:14:02 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef LED_H_
#define LED_H_

/****************************************_MACROS_***************************************/
#define F_CPU	16000000UL


/***************************************_INCLUDES_***************************************/
#include "Dio.h"
#include "LedCfg.h"
#include <util/delay.h>

/***************************************_PROTOTYPES_***************************************/
void	H_Led_Init		(u8 Local_u8_Led_Number);
void	H_Led_On		(u8 Local_u8_Led_Number);
void	H_Led_Off		(u8 Local_u8_Led_Number);
void	H_Led_Blink		(u8 Local_u8_Led_Number);
void	H_Led_Tog		(u8 Local_u8_Led_Number);


#endif /* LED_H_ */