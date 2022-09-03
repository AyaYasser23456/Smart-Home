/*
 * Timer1Cfg.h
 *
 * Created: 6/29/2022 4:39:30 AM
 *  Author: Ahmed Hesham
 */ 


#ifndef TIMER1CFG_H_
#define TIMER1CFG_H_

/****************************************_TIMER0_CLOCK_SELECTIONS_***************************************/
/*
 *	TO CHOOSE TIMER1 
 *		OPTION 1		->		NO_CLK				->	For stopping the clock 
 *		OPTION 2		->		PRESCLNG_1			->	For	starting the clock without a prescaler
 *		OPTION 3		->		PRESCLNG_8			->	For starting the clock with a prescaler 8
 *		OPTION 4		->		PRESCLNG_64			->	For starting the clock with a prescaler 64
 *		OPTION 5		->		PRESCLNG_256		->	For	starting the clock with a prescaler 256
 *		OPTION 6		->		PRESCLNG_1024		->	For starting the clock with a prescaler 1024
 *		OPTION 7		->		XCK_FLNG_EDGE		->	External clock source on T0 pin. Clock on falling edge.
 *		OPTION 8		->		XCK_RSNG_EDGE		->	External clock source on T0 pin. Clock on rising edge.
 */

#define TIMER1_PRESCALER		PRESCLNG_64
/****************************************_CRYSTAL_FREQUENCY_***************************************/
/*
 *	WRITE CRYSTAL FREQUENCY IN MEGA BYTES 
 */

#define CRYSTAL_FREQUENCY		16

/****************************************_TIMER0_MODE_OF_OPERATION_***************************************/
/*
 *	CHOOSE OPERATION MODE FOR TIMER 1
 *		OPTION 1		->		NORMAL			
 *		OPTION 2		->		CTC				
 */

#define TIMER1_MODE				NORMAL

/****************************************_TIMER0_MODE_OF_OPERATION_***************************************/
/*
 *	CHOOSE OPERATION MODE FOR PWM1
 *		OPTION 1		->		FAST_PWM			
 *		OPTION 2		->		PHASE_CORRECT
 */

#define PWM1_MODE				FAST_PWM

/****************************************_TIMER0_MODE_OF_OPERATION_***************************************/
/*
 *	CHOOSE OPERATION MODE FOR PWM1
 *		OPTION 1		->		NON_INVERTED			
 *		OPTION 2		->		INVERTED
 */

#define OUTPUT_PWM_MODE				NON_INVERTED



#endif /* TIMER1CFG_H_ */