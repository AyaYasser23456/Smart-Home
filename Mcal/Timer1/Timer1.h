/*
 * Timer1.h
 *
 * Created: 6/29/2022 4:39:15 AM
 *  Author: Ahmed Hesham
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

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
#include "Timer1Cfg.h"

/***************************************_PROTOTYPES_***************************************/


void M_Pwm1_Init				(void);
void M_Pwm1_SetDutyCycle		(f32 Local_u8_DesiredDutyCycle);
void M_Pwm1_SetFrequency		(u16 Local_u16_DesiredFrequency);
void M_Pwm1_Start				(void);
void M_Pwm1_Stop				(void);

#endif /* TIMER1_H_ */