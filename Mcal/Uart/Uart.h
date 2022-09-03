/*
 * Uart.h
 *
 * Created: 27/05/2022 04:13:02 م
 *  Author: dell
 */ 


#ifndef UART_H_
#define UART_H_


/*********************************_INCLUDES_****************************/
#include "UartCfg.h"
#include "StdTypes.h"
#include "BitMath.h"
#include "Reg.h"
/***********************************_MACOS_*******************************/
#define DISABLE       0
#define ODD           1
#define EVEN          2
/********************************_PROTOTYPES_*****************************/
void M_Uart_Init(void);
void M_Uart_Write(u8);
u8   M_Uart_Read(void);
#endif /* UART_H_ */