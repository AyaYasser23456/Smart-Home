/*
 * Hc05.h
 *
 * Created: 28/05/2022 04:12:27 م
 *  Author: dell
 */ 


#ifndef HC05_H_
#define HC05_H_


/*********************************_INCLUDES_******************************/
#include "Hc05Cfg.h"
#include "Uart.h"
#include <util/delay.h>
/***********************************_MACOS_*******************************/

/********************************_PROTOTYPES_*****************************/
void H_Hc05_Init(void);
void H_Hc05_Send(u8);
void H_Hc05_SendString(u8*);
u8   H_Hc05_Rec(void);

#endif /* HC05_H_ */