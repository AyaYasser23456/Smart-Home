/*
 * KeyPad.c
 *
 * Created: 6/13/2022 8:36:52 PM
 *  Author: Ahmed Hesham
 */ 

#include "KeyPad.h"


void H_KeyPad_Init				(void)
{
	M_Dio_PinMode(KEYPAD_R0_PIN,OUTPUT);
	M_Dio_PinMode(KEYPAD_R1_PIN,OUTPUT);
	M_Dio_PinMode(KEYPAD_R2_PIN,OUTPUT);
	M_Dio_PinMode(KEYPAD_R3_PIN,OUTPUT);
	
	M_Dio_PinWrite(KEYPAD_R0_PIN,HIGH);
	M_Dio_PinWrite(KEYPAD_R1_PIN,HIGH);
	M_Dio_PinWrite(KEYPAD_R2_PIN,HIGH);
	M_Dio_PinWrite(KEYPAD_R3_PIN,HIGH);
	
	M_Dio_PinMode(KEYPAD_C0_PIN,INPUT);
	M_Dio_PinMode(KEYPAD_C1_PIN,INPUT);
	M_Dio_PinMode(KEYPAD_C2_PIN,INPUT);
	M_Dio_PinMode(KEYPAD_C3_PIN,INPUT);
	
	M_Dio_PinPullUp(KEYPAD_C0_PIN,PULLUP_ENABLE);
	M_Dio_PinPullUp(KEYPAD_C1_PIN,PULLUP_ENABLE);
	M_Dio_PinPullUp(KEYPAD_C2_PIN,PULLUP_ENABLE);
	M_Dio_PinPullUp(KEYPAD_C3_PIN,PULLUP_ENABLE);
		
}
u8	 H_KeyPad_Read				(void)
{
	u8 Local_u8_KeypadReading		=	0;
	u8 Local_u8_KeyPadArr [4][4]	={	{'7','8','9','/'},
										{'4','5','6','*'},
										{'1','2','3','-'},										
										{'C','0','=','+'} };
										
	M_Dio_PinWrite(KEYPAD_R0_PIN,LOW);
	
	if(M_Dio_PinRead(KEYPAD_C0_PIN) == 0) { _delay_ms(30);if(M_Dio_PinRead(KEYPAD_C0_PIN) == 0) {while(M_Dio_PinRead(KEYPAD_C0_PIN) == 0); M_Dio_PinWrite(KEYPAD_R0_PIN,HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [0][0];}}
	if(M_Dio_PinRead(KEYPAD_C1_PIN) == 0) { _delay_ms(30);if(M_Dio_PinRead(KEYPAD_C1_PIN) == 0) {while(M_Dio_PinRead(KEYPAD_C1_PIN) == 0); M_Dio_PinWrite(KEYPAD_R0_PIN,HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [0][1];}}
	if(M_Dio_PinRead(KEYPAD_C2_PIN) == 0) { _delay_ms(30);if(M_Dio_PinRead(KEYPAD_C2_PIN) == 0) {while(M_Dio_PinRead(KEYPAD_C2_PIN) == 0); M_Dio_PinWrite(KEYPAD_R0_PIN,HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [0][2];}}
	if(M_Dio_PinRead(KEYPAD_C3_PIN) == 0) { _delay_ms(30);if(M_Dio_PinRead(KEYPAD_C3_PIN) == 0) {while(M_Dio_PinRead(KEYPAD_C3_PIN) == 0); M_Dio_PinWrite(KEYPAD_R0_PIN,HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [0][3];}}
	
	M_Dio_PinWrite(KEYPAD_R0_PIN,HIGH);
	
	
	M_Dio_PinWrite(KEYPAD_R1_PIN,LOW);
	
	if(M_Dio_PinRead(KEYPAD_C0_PIN) == 0) { _delay_ms(30);if(M_Dio_PinRead(KEYPAD_C0_PIN) == 0) {while(M_Dio_PinRead(KEYPAD_C0_PIN) == 0); M_Dio_PinWrite(KEYPAD_R1_PIN,HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [1][0];}}
	if(M_Dio_PinRead(KEYPAD_C1_PIN) == 0) { _delay_ms(30);if(M_Dio_PinRead(KEYPAD_C1_PIN) == 0) {while(M_Dio_PinRead(KEYPAD_C1_PIN) == 0); M_Dio_PinWrite(KEYPAD_R1_PIN,HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [1][1];}}
	if(M_Dio_PinRead(KEYPAD_C2_PIN) == 0) { _delay_ms(30);if(M_Dio_PinRead(KEYPAD_C2_PIN) == 0) {while(M_Dio_PinRead(KEYPAD_C2_PIN) == 0); M_Dio_PinWrite(KEYPAD_R1_PIN,HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [1][2];}}
	if(M_Dio_PinRead(KEYPAD_C3_PIN) == 0) { _delay_ms(30);if(M_Dio_PinRead(KEYPAD_C3_PIN) == 0) {while(M_Dio_PinRead(KEYPAD_C3_PIN) == 0); M_Dio_PinWrite(KEYPAD_R1_PIN,HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [1][3];}}
	
	M_Dio_PinWrite(KEYPAD_R1_PIN,HIGH);
	
	
	M_Dio_PinWrite(KEYPAD_R2_PIN,LOW);
		
	if(M_Dio_PinRead(KEYPAD_C0_PIN) == 0) { _delay_ms(30);if(M_Dio_PinRead(KEYPAD_C0_PIN) == 0) {while(M_Dio_PinRead(KEYPAD_C0_PIN) == 0);M_Dio_PinWrite(KEYPAD_R2_PIN,HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [2][0];}}
	if(M_Dio_PinRead(KEYPAD_C1_PIN) == 0) { _delay_ms(30);if(M_Dio_PinRead(KEYPAD_C1_PIN) == 0) {while(M_Dio_PinRead(KEYPAD_C1_PIN) == 0);M_Dio_PinWrite(KEYPAD_R2_PIN,HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [2][1];}}
	if(M_Dio_PinRead(KEYPAD_C2_PIN) == 0) { _delay_ms(30);if(M_Dio_PinRead(KEYPAD_C2_PIN) == 0) {while(M_Dio_PinRead(KEYPAD_C2_PIN) == 0);M_Dio_PinWrite(KEYPAD_R2_PIN,HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [2][2];}}
	if(M_Dio_PinRead(KEYPAD_C3_PIN) == 0) { _delay_ms(30);if(M_Dio_PinRead(KEYPAD_C3_PIN) == 0) {while(M_Dio_PinRead(KEYPAD_C3_PIN) == 0);M_Dio_PinWrite(KEYPAD_R2_PIN,HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [2][3];}}
	
	M_Dio_PinWrite(KEYPAD_R2_PIN,HIGH);
	
				
	M_Dio_PinWrite(KEYPAD_R3_PIN,LOW);
	
	if(M_Dio_PinRead(KEYPAD_C0_PIN) == 0) { _delay_ms(30);if(M_Dio_PinRead(KEYPAD_C0_PIN) == 0) {while(M_Dio_PinRead(KEYPAD_C0_PIN) == 0);M_Dio_PinWrite(KEYPAD_R3_PIN,HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [3][0];}}
	if(M_Dio_PinRead(KEYPAD_C1_PIN) == 0) { _delay_ms(30);if(M_Dio_PinRead(KEYPAD_C1_PIN) == 0) {while(M_Dio_PinRead(KEYPAD_C1_PIN) == 0);M_Dio_PinWrite(KEYPAD_R3_PIN,HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [3][1];}}
	if(M_Dio_PinRead(KEYPAD_C2_PIN) == 0) { _delay_ms(30);if(M_Dio_PinRead(KEYPAD_C2_PIN) == 0) {while(M_Dio_PinRead(KEYPAD_C2_PIN) == 0);M_Dio_PinWrite(KEYPAD_R3_PIN,HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [3][2];}}
	if(M_Dio_PinRead(KEYPAD_C3_PIN) == 0) { _delay_ms(30);if(M_Dio_PinRead(KEYPAD_C3_PIN) == 0) {while(M_Dio_PinRead(KEYPAD_C3_PIN) == 0);M_Dio_PinWrite(KEYPAD_R3_PIN,HIGH); Local_u8_KeypadReading = Local_u8_KeyPadArr [3][3];}}
	
	M_Dio_PinWrite(KEYPAD_R3_PIN,HIGH);
	
	return Local_u8_KeypadReading ;
}		   