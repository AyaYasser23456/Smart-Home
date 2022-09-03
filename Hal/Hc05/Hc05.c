/*
 * Hc05.c
 *
 * Created: 28/05/2022 04:12:14 م
 *  Author: dell
 */ 
#include "Hc05.h"

void H_Hc05_Init(void)
{
	M_Uart_Init();
}
void H_Hc05_Send(u8 Local_u8_Data)
{
	M_Uart_Write(Local_u8_Data);
}

void H_Hc05_SendString(u8* Local_u8_PtrToString)
{
	u8 Local_u8_Counter = 0;
	u8 Local_u8_Data = 0;
	while (Local_u8_PtrToString[Local_u8_Counter] !='\0')
	{
		Local_u8_Data=Local_u8_PtrToString[Local_u8_Counter];
		H_Hc05_Send(Local_u8_Data);
		_delay_ms(50);
		Local_u8_Counter++;
	}
	H_Hc05_Send(13);
}
u8   H_Hc05_Rec(void)
{
	u8 Local_u8_Data = 0;
	Local_u8_Data = M_Uart_Read();
	return Local_u8_Data;
}