/*
 * Uart.c
 *
 * Created: 27/05/2022 04:12:48 م
 *  Author: dell
 */ 
#include "Uart.h"

void M_Uart_Init(void)
{
	ClrBit(DDRD,0);  // to make PD0 (Rx) as -> Input
	SetBit(DDRD,1);  // to make PD1 (Tx) as -> Output
	u8 Local_u8_UCSRC_Value = 0;
	SetBit(Local_u8_UCSRC_Value,7);
	// to select character size -> 8 bits
	ClrBit(UCSRB,2);    
	SetBit(Local_u8_UCSRC_Value,1); 
	SetBit(Local_u8_UCSRC_Value,2); 
	#if   PARITY_MODE   ==   EVEN
	ClrBit(Local_u8_UCSRC_Value,4);
	SetBit(Local_u8_UCSRC_Value,5);
	#elif PARITY_MODE   ==   ODD
	SetBit(Local_u8_UCSRC_Value,4);
	SetBit(Local_u8_UCSRC_Value,5);
	#elif PARITY_MODE   ==   DISABLE
	ClrBit(Local_u8_UCSRC_Value,4);
	ClrBit(Local_u8_UCSRC_Value,5);
	#endif
	ClrBit(Local_u8_UCSRC_Value,3);    // to select stop bit as -> 1
	UBRRL = 103;        // to select baud rate as -> 9600 BPS
	UCSRC = Local_u8_UCSRC_Value;
	SetBit(UCSRB,3);    // to enable tx circuit
	SetBit(UCSRB,4);    // to enable rx circuit
}
void M_Uart_Write(u8 Local_u8_Data)
{
	UDR = Local_u8_Data;
	while(GetBit(UCSRA,6) == 0);
}
u8   M_Uart_Read(void)
{
	while(GetBit(UCSRA,7) == 0);
	return UDR;
}