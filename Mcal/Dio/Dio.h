/*
 * Dio.h
 *
 * Created: 6/2/2022 4:12:53 AM
 *  Author: Ahmed Hesham
 */ 


#ifndef DIO_H_
#define DIO_H_
/****************************************_INCLUDES_****************************************/
#include "Reg.h"
#include "BitMath.h"
#include "StdTypes.h"

/*****************************************_MACROS_*****************************************/
#define OUTPUT			1
#define INPUT			0
#define HIGH			1
#define LOW				0
#define PULLUP_DISABLE	0
#define PULLUP_ENABLE	1

#define PA0				10
#define PA1				11
#define PA2				12
#define PA3				13
#define PA4				14
#define PA5				15
#define PA6				16
#define PA7				17

#define PB0				20
#define PB1				21
#define PB2				22
#define PB3				23
#define PB4				24
#define PB5				25
#define PB6				26
#define PB7				27

#define PC0				30
#define PC1				31
#define PC2				32
#define PC3				33
#define PC4				34
#define PC5				35
#define PC6				36
#define PC7				37

#define PD0				40
#define PD1				41
#define PD2				42
#define PD3				43
#define PD4				44
#define PD5				45
#define PD6				46
#define PD7				47

/***************************************_PROTOTYPES_***************************************/
void M_Dio_PinMode		(u8 Local_u8_PinNumber, u8 Local_u8_PinDirection);

void M_Dio_PinWrite		(u8 Local_u8_PinNumber, u8 Local_u8_OutputMode);

void M_Dio_PinTog		(u8 Local_u8_PinNumber);

u8	 M_Dio_PinRead		(u8 Local_u8_PinNumber);

void M_Dio_PinPullUp	(u8 Local_u8_PinNumber, u8 Local_u8_PullUpState);




#endif /* DIO_H_ */