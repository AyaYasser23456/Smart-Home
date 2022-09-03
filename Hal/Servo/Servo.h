/*
 * Servo.h
 *
 * Created: 7/4/2022 6:39:37 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef SERVO_H_
#define SERVO_H_

/************************************************************************/
/*							INCLUDES                                    */
/************************************************************************/
#include "StdTypes.h"
#include "Reg.h"
#include "Dio.h"
#include "ServoCfg.h"
#include "Timer1.h"

/************************************************************************/
/*							PROTOTYPES                                  */
/************************************************************************/

/*To initialize the servo*/
void H_Servo_Init		(void);

/*To set angel, Enter your desired angel from 0 to 180*/ 
void H_Servo_SetAngel	(f32 Local_f32_DesiredAngel);

/*To turn Off Servo Motor*/
void H_Servo_TurnOff	(void);


#endif /* SERVO_H_ */