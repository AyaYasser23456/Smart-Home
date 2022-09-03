/*
 * Lm35.h
 *
 * Created: 6/22/2022 3:53:23 AM
 *  Author: Ahmed Hesham
 */ 


#ifndef LM35_H_
#define LM35_H_

/****************************************_MACROS_***************************************/
#define F_CPU									16000000UL

/***************************************_INCLUDES_***************************************/
#include "Dio.h"
#include "StdTypes.h"
#include "BitMath.h"
#include "Adc.h"
#include "Lm35Cfg.h"
#include <util/delay.h>

/***************************************_PROTOTYPES_***************************************/

void H_Lm35_Init				(void);
u16  H_Lm35_Read				(void);




#endif /* LM35_H_ */