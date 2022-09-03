/*
 * Relay.h
 *
 * Created: 8/29/2022 4:03:41 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef RELAY_H_
#define RELAY_H_

/*****************************************_MACROS_*****************************************/
#define F_CPU	16000000UL

/****************************************_INCLUDES_***************************************/
#include "Dio.h"
#include "RelayCfg.h"
#include <util/delay.h>

/***************************************_PROTOTYPES_***************************************/
void	H_Relay_Init		(void);
void	H_Relay_On			(void);
void	H_Relay_Off		    (void);




#endif /* RELAY_H_ */