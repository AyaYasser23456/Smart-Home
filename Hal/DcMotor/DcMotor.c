/*
 * DcMotor.c
 *
 * Created: 6/28/2022 11:31:33 PM
 *  Author: Ahmed Hesham
 */ 

#include "DcMotor.h"

void H_DcMotor_Init				(void)
{
	M_Dio_PinMode(DC_MOTOR_PIN_1,OUTPUT);
	M_Dio_PinMode(DC_MOTOR_PIN_0,OUTPUT);
	M_Pwm2_Init();
}


void H_DcMotor_SetDirection		(u8 Local_u8_Direction)
{
	M_Dio_PinWrite(DC_MOTOR_PIN_0,HIGH);
	M_Dio_PinWrite(DC_MOTOR_PIN_1,LOW);	

// 	switch(Local_u8_Direction)
// 	{
// 		case CW: 
// 			M_Dio_PinWrite(DC_MOTOR_PIN_0,HIGH); 
// 			M_Dio_PinWrite(DC_MOTOR_PIN_1,LOW);
// 			break;
// 		case ACW:
// 			M_Dio_PinWrite(DC_MOTOR_PIN_0,LOW);
// 			M_Dio_PinWrite(DC_MOTOR_PIN_1,HIGH);
// 			break;
// 		default:
// 			break;
// 	}
}


void H_DcMotor_Speed			(u8 Local_u8_Speed)
{
	M_Pwm2_SetDutyCycle(Local_u8_Speed);
}


void H_DcMotor_Start			(void)
{
	M_Pwm2_Start();
}


void H_DcMotor_Stop				(void)
{
	M_Pwm2_Stop();
}