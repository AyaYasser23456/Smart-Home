/*
 * Timer0.h
 *
 * Created: 6/22/2022 5:15:17 AM
 *  Author: Ahmed Hesham
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

/****************************************_MACROS_***************************************/
#define F_CPU									16000000UL

#define NO_CLK									0
#define PRESCLNG_1								1
#define PRESCLNG_8								8
#define PRESCLNG_64								64
#define PRESCLNG_256							256
#define PRESCLNG_1024							1024
#define XCK_FLNG_EDGE							10
#define XCK_RSNG_EDGE							15

#define NORMAL									1
#define CTC										2

#define FAST_PWM								1
#define PHASE_CORRECT							2

#define NON_INVERTED							1
#define INVERTED								2
/***************************************_INCLUDES_***************************************/
#include <stdio.h>
//#include <avr/interrupt.h>
#include <util/delay.h>
#include "Dio.h"
#include "Reg.h"
#include "StdTypes.h"
#include "BitMath.h"
#include "Timer0Cfg.h"

/***************************************_PROTOTYPES_***************************************/

void M_Timer0_Init				(void);
								
void M_Timer0_SetTime			(u32 Local_u32_DesiredTime);
								
void M_Timer0_Start				(void);
								
void M_Timer0_Stop				(void);

void M_Pwm0_Init				(void);
	   
void M_Pwm0_SetDutyCycle		(u8 Local_u8_DesiredDutyCycle);
	   
void M_Pwm0_Start				(void);
	   
void M_Pwm0_Stop				(void);

void M_Timer0_SetCallBack	(void (*Local_void_ptr) (void));




#endif /* TIMER0_H_ */