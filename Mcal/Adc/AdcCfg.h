/*
 * AdcCfg.h
 *
 * Created: 6/16/2022 2:12:22 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef ADCCFG_H_
#define ADCCFG_H_

/****************************************_VOLTAGE_REFERENCE_SELECTION_***************************************/
/*
 *	TO CHOOSE SENSE CONTROL MODE FOR INT0
 *		OPTION 1		->		AREF	->	For the usage of AREF Pin
 *		OPTION 2		->		AVCC	->	For	the usage of AVCC Pin, attach external capacitor to AREF Pin
 *		OPTION 3		->		VREF	->	For the usage internal 2.56V Voltage Reference with external capacitor at AREF Pin
 */

#define VOLTAGE_REFERENCE		AVCC

/****************************************_LEFT_ADJUST_RESULT_***************************************/
/*
 *	TO CHOOSE SENSE CONTROL MODE FOR INT0
 *		OPTION 1		->		LEFT_ADJUST
 *		OPTION 2		->		RIGHT_ADJUST
 */

#define LEFT_ADJUST_RESULT		RIGHT_ADJUST

/****************************************_PRESCALER_SELECTION_***************************************/
/*
 *	TO CHOOSE SENSE CONTROL MODE FOR INT0
 *		OPTION 1		->		DIVISION_FACTOR_1
 *		OPTION 2		->		DIVISION_FACTOR_2
 *		OPTION 3		->		DIVISION_FACTOR_4
 *		OPTION 4		->		DIVISION_FACTOR_8
 *		OPTION 5		->		DIVISION_FACTOR_16
 *		OPTION 6		->		DIVISION_FACTOR_32
 *		OPTION 7		->		DIVISION_FACTOR_64
 *		OPTION 8		->		DIVISION_FACTOR_128	
 */

#define PRESCALER_SELECTION		DIVISION_FACTOR_128

/****************************************_INTERRUPT_STATE_***************************************/
/*
 *	TO CHOOSE SENSE CONTROL MODE FOR INT0
 *		OPTION 1		->		ADC_INT_ENABLE 
 *		OPTION 2		->		ADC_INT_DISABLE
 */
#define ADC_INTERRUPT			ADC_INT_DISABLE

#endif /* ADCCFG_H_ */