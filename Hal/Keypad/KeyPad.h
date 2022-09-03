/*
 * KeyPad.h
 *
 * Created: 6/13/2022 8:37:14 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

/****************************************_MACROS_***************************************/
#define F_CPU									16000000UL


/***************************************_INCLUDES_***************************************/
#include "Dio.h"
#include "StdTypes.h"
#include "BitMath.h"
#include "KeyPadCfg.h"
#include <util/delay.h>

/***************************************_PROTOTYPES_***************************************/

void H_KeyPad_Init				(void);
u8	 H_KeyPad_Read			(void);





#endif /* KEYPAD_H_ */