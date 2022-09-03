/*
 * Servo.c
 *
 * Created: 7/4/2022 6:39:25 PM
 *  Author: Ahmed Hesham
 */ 

/************************************************************************/
/*							INCLUDES                                    */
/************************************************************************/
#include "Servo.h"

/************************************************************************/
/*							FUNCTIONS' DEFINITIONS                      */
/************************************************************************/

/*
	To initialize the servo, most of servo motor works by a pwm signal 50 hz 
	so I initialized an output pwm signal with frequency 50 hz
*/
void H_Servo_Init		(void)
{
	/*To Set Control Pin as Output*/
	M_Dio_PinMode(SERVO_OUTPUT_PIN, OUTPUT);
	
	/*To initialize PWM*/
	M_Pwm1_Init();
		
	/*To set working Frequency*/
	M_Pwm1_SetFrequency(50);
}

/*To set desired angel for the servo step, Servo usually works from 5% to 10% duty cycle so I mapped 0-180 degrees to 5%-10% */
void H_Servo_SetAngel	(f32 Local_f32_DesiredAngel)
{
	/*scaling from 180 degrees to 5 to 10 Percents*/
 	
	Local_f32_DesiredAngel *= 5;
 	Local_f32_DesiredAngel /= 180;
	Local_f32_DesiredAngel += 5;
	 
	/*to set PWM Duty Cycle*/
 	M_Pwm1_SetDutyCycle(Local_f32_DesiredAngel);
	 
	/*To start the clock*/
 	M_Pwm1_Start();
}

void H_Servo_TurnOff	(void)
{
	M_Pwm1_Stop();
}