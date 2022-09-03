/*
 * Timer0Cfg.h
 *
 * Created: 6/22/2022 5:15:40 AM
 *  Author: Ahmed Hesham
 */ 


#ifndef TIMER0CFG_H_
#define TIMER0CFG_H_

/****************************************_TIMER0_CLOCK_SELECTIONS_***************************************/
/*
 *	TO CHOOSE TIMER0 
 *		OPTION 1		->		NO_CLK				->	For stopping the clock 
 *		OPTION 2		->		PRESCLNG_1			->	For	starting the clock without a prescaler
 *		OPTION 3		->		PRESCLNG_8			->	For starting the clock with a prescaler 8
 *		OPTION 4		->		PRESCLNG_64			->	For starting the clock with a prescaler 64
 *		OPTION 5		->		PRESCLNG_256		->	For	starting the clock with a prescaler 256
 *		OPTION 6		->		PRESCLNG_1024		->	For starting the clock with a prescaler 1024
 *		OPTION 7		->		XCK_FLNG_EDGE		->	External clock source on T0 pin. Clock on falling edge.
 *		OPTION 8		->		XCK_RSNG_EDGE		->	External clock source on T0 pin. Clock on rising edge.
 */

#define TIMER0_PRESCALER		PRESCLNG_1024
/****************************************_CRYSTAL_FREQUENCY_***************************************/
/*
 *	WRITE CRYSTAL FREQUENCY IN MEGA BYTES 
 */

#define CRYSTAL_FREQUENCY		16

/****************************************_TIMER0_MODE_OF_OPERATION_***************************************/
/*
 *	CHOOSE OPERATION MODE FOR TIMER 0
 *		OPTION 1		->		NORMAL			
 *		OPTION 2		->		CTC				
 */

#define TIMER0_MODE				NORMAL

/****************************************_TIMER0_MODE_OF_OPERATION_***************************************/
/*
 *	CHOOSE OPERATION MODE FOR PWM0
 *		OPTION 1		->		FAST_PWM			
 *		OPTION 2		->		PHASE_CORRECT
 */

#define PWM0_MODE				FAST_PWM

/****************************************_TIMER0_MODE_OF_OPERATION_***************************************/
/*
 *	CHOOSE OPERATION MODE FOR PWM0
 *		OPTION 1		->		NON_INVERTED			
 *		OPTION 2		->		INVERTED
 */

#define OUTPUT_MODE				NON_INVERTED


#endif /* TIMER0CFG_H_ */