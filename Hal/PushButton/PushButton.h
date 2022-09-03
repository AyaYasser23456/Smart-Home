/*
 * PushButton.h
 *
 * Created: 6/7/2022 1:37:32 PM
 *  Author: elwady
 */ 


#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_



/****************************************_MACROS_***************************************/
/*#define F_CPU				16000000UL
#define PUSH_BUTTON_0		1
#define PUSH_BUTTON_1		2
#define PUSH_BUTTON_2		3
*/
#define PRESSED				1
#define RELEASED			0
/***************************************_INCLUDES_***************************************/
#include "Dio.h"
#include "StdTypes.h"
#include "PushButtonCfg.h"
//#include <util/delay.h>

/***************************************_PROTOTYPES_***************************************/
void	H_PushButton_Init			(void);
u8		H_PushButton_Read			(void);


#endif /* PUSHBUTTON_H_ */