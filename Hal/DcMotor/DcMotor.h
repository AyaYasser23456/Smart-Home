/*
 * DcMotor.h
 *
 * Created: 6/28/2022 11:31:56 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef DCMOTOR_H_
#define DCMOTOR_H_

/****************************************_MACROS_****************************************/
#define F_CPU									16000000UL
#define ACW										1
#define CW										0

/***************************************_INCLUDES_***************************************/
#include <util/delay.h>
#include "Dio.h"
#include "StdTypes.h"
#include "BitMath.h"
#include "Timer2.h"
#include "DcMotorCfg.h"
/***************************************_PROTOTYPES_*************************************/

void H_DcMotor_Init				(void);
void H_DcMotor_SetDirection		(u8 Local_u8_Direction);
void H_DcMotor_Speed			(u8 Local_u8_Speed);
void H_DcMotor_Start			(void);
void H_DcMotor_Stop				(void);

#endif /* DCMOTOR_H_ */