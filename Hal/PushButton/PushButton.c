/*
 * PushButton.c
 *
 * Created: 6/7/2022 1:38:24 PM
 *  Author: elwady
 */ 
/*
#include "PushButton.h"

void H_PushButton_Init(u8 Local_u8_Push_Button_Number)
{
	switch(Local_u8_Push_Button_Number)
	{
		case PUSH_BUTTON_0: M_Dio_PinMode(PUSH_BUTTON_0_PIN,INPUT);		break;
		case PUSH_BUTTON_1: M_Dio_PinMode(PUSH_BUTTON_1_PIN,INPUT);		break;
		case PUSH_BUTTON_2: M_Dio_PinMode(PUSH_BUTTON_2_PIN,INPUT);		break;
		default:														break;
	}
}
u8	H_PushButton_Read(u8 Local_u8_Push_Button_Number)
{
	u8 Local_u8_Push_Button_Value = 0;
	switch(Local_u8_Push_Button_Number)
	{
		case PUSH_BUTTON_0: Local_u8_Push_Button_Value = M_Dio_PinRead(PUSH_BUTTON_0);break;
		case PUSH_BUTTON_1: Local_u8_Push_Button_Value = M_Dio_PinRead(PUSH_BUTTON_1);break;
		case PUSH_BUTTON_2: Local_u8_Push_Button_Value = M_Dio_PinRead(PUSH_BUTTON_2);break;
		default:														break;
	}
	
	
	return Local_u8_Push_Button_Value ;
}
*/

#include "PushButton.h"
void H_PushButton_Init(void)
{
	M_Dio_PinMode(PUSH_BUTTON_PIN,INPUT);
}
u8   H_PushButton_Read(void)
{
	u8 Local_u8_Reading = 0;
	   Local_u8_Reading = M_Dio_PinRead(PUSH_BUTTON_PIN);
	return Local_u8_Reading;
}