/*
 * Lcd.h
 *
 * Created: 6/8/2022 1:22:58 AM
 *  Author: Ahmed Hesham
 */ 


#ifndef LCD_H_
#define LCD_H_

/****************************************_MACROS_***************************************/
#define F_CPU									16000000UL
#define LCD_CMD_CLEAR							0X01
#define LCD_CMD_DISPLAY_ON_CURSOR_OFF			0X0C
#define LCD_CMD_SELECT_8_BIT_MODE				0X38
#define LCD_CMD_SELECT_4_BIT_MODE				0X28
#define LCD_CMD_RETURN_HOME						0X02
#define LCD_CMD_WRITE_FROM_LEFT_TO_RIGHT		0X06
#define LCD_CMD_FIRST_ROW						0X80
#define LCD_CMD_SECOND_ROW						0XC0

#define	_4_BIT_MODE								1
#define _8_BIT_MODE								2

/***************************************_INCLUDES_***************************************/
#include "Dio.h"
#include "StdTypes.h"

#include "LcdCfg.h"
#include <util/delay.h>

/***************************************_PROTOTYPES_***************************************/

void H_Lcd_Init				(void);
void H_Lcd_WriteCharacter	(u8 Local_u8_Character);
void H_Lcd_WriteCommand		(u8);
void H_Lcd_WriteNumber		(s32);
void H_Lcd_Clear			(void);
void H_Lcd_WriteString		(u8*);

void H_Lcd_GoTo				(u8 Local_u8_Row, u8 Local_u8_Coloumn);


#endif /* LCD_H_ */