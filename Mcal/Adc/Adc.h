/*
 * Adc.h
 *
 * Created: 6/16/2022 2:12:06 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef ADC_H_
#define ADC_H_

/****************************************_MACROS_***************************************/
#define F_CPU									16000000UL

#define AREF									2
#define AVCC									3
#define VREF									4

#define LEFT_ADJUST								2
#define RIGHT_ADJUST							3

#define	DIVISION_FACTOR_1						1
#define	DIVISION_FACTOR_2						2
#define	DIVISION_FACTOR_4						3
#define	DIVISION_FACTOR_8						4
#define	DIVISION_FACTOR_16						5
#define	DIVISION_FACTOR_32						6
#define	DIVISION_FACTOR_64						7
#define DIVISION_FACTOR_128						8

#define ADC_INT_ENABLE							0 
#define ADC_INT_DISABLE							1


/***************************************_INCLUDES_***************************************/

//#include <avr/interrupt.h>
#include <util/delay.h>
#include "Dio.h"
#include "Reg.h"
#include "StdTypes.h"
#include "BitMath.h"
#include "AdcCfg.h"
/***************************************_PROTOTYPES_***************************************/

void M_Adc_Init (void);

u16  M_Adc_Read(void);

void M_Adc_SetCallBackAdc (void (*Local_void_ptr) (void));

// void M_Adc_SetCallBackInt1 (void (*Local_void_ptr) (void));
// void M_Adc_SetCallBackInt2 (void (*Local_void_ptr) (void));




#endif /* ADC_H_ */