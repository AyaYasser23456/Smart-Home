/*
 * ExtIntCfg.h
 *
 * Created: 6/15/2022 10:20:20 PM
 *  Author: elwady
 */ 


#ifndef EXTINTCFG_H_
#define EXTINTCFG_H_

/****************************************_SENSE_CONTROL_MODE_***************************************/
/*
 *	TO CHOOSE SENSE CONTROL MODE FOR INT0
 *	OPTION 1	->		LOW_LEVEL
 *	OPTION 2	->		ANY_CHANGE
 *	OPTION 3	->		FALLING_EDGE
 *	OPTION 4	->		RISING_EDGE	
 */

#define SENSE_CONTROL_0		RISING_EDGE

/*
 *	TO CHOOSE SENSE CONTROL MODE FOR INT1
 *	OPTION 1	->		LOW_LEVEL
 *	OPTION 2	->		ANY_CHANGE
 *	OPTION 3	->		FALLING_EDGE
 *	OPTION 4	->		RISING_EDGE	
 */

#define SENSE_CONTROL_1		RISING_EDGE

/*
 *	TO CHOOSE SENSE CONTROL MODE FOR INT2
 *	OPTION 1	->		FALLING_EDGE
 *	OPTION 2	->		RISING_EDGE	
 */

#define SENSE_CONTROL_2		RISING_EDGE


#endif /* EXTINTCFG_H_ */