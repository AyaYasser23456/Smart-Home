/*
 * ExtInt.h
 *
 * Created: 6/15/2022 10:20:01 PM
 *  Author: elwady
 */ 


#ifndef EXTINT_H_
#define EXTINT_H_

/****************************************_MACROS_***************************************/
#define F_CPU									16000000UL
#define LOW_LEVEL								1
#define ANY_CHANGE								2
#define FALLING_EDGE							3
#define RISING_EDGE								4

/***************************************_INCLUDES_***************************************/


#include "Reg.h"
#include "StdTypes.h"
#include "BitMath.h"
#include "ExtIntCfg.h"
#include <avr/interrupt.h>
#include <util/delay.h>
/***************************************_PROTOTYPES_***************************************/
/*
 *	CHOOSE EXTERNAL INTERRUPT 
 *	OPTION 1	->		INT0
 *	OPTION 2	->		INT1
 *	OPTION 3	->		INT2
 */

void M_ExtInt_Init (u8 Local_u8_IntNumber);

void M_ExtInt_SetCallBackInt0 (void (*Local_void_ptr) (void));
void M_ExtInt_SetCallBackInt1 (void (*Local_void_ptr) (void));
void M_ExtInt_SetCallBackInt2 (void (*Local_void_ptr) (void));

#endif /* EXTINT_H_ */