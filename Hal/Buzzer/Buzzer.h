/*
 * Buzzer.h
 *
 * Created: 6/7/2022 12:02:08 AM
 *  Author: Ahmed Hesham
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

/*****************************************_MACROS_*****************************************/
#define F_CPU	16000000UL

/****************************************_INCLUDES_***************************************/
#include "Dio.h"
#include "BuzzerCfg.h"
#include <util/delay.h>

/***************************************_PROTOTYPES_***************************************/
void	H_Buzzer_Init		(void);
void	H_Buzzer_On			(void);
void	H_Buzzer_Off		(void);
void	H_Buzzer_Beeb		(void);
void	H_Buzzer_Tog		(void);




#endif /* BUZZER_H_ */