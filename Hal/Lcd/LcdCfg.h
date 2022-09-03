/*
 * LcdCfg.h
 *
 * Created: 6/8/2022 1:23:13 AM
 *  Author: Ahmed Hesham
 */ 


#ifndef LCDCFG_H_
#define LCDCFG_H_

/*******************************_SELECT_LCD_MODE********************************/
/*
 * OPTION 1-> [ _4_BIT_MODE ]
 * OPTION 1-> [ _8_BIT_MODE ]
 */
#define LCD_MODE			_4_BIT_MODE

/****************************_SELECT_DATA_REGISTER********************************/

#define LCD_DATA_PORT		PORTB

/*******************************_SELECT_MC_PINS********************************/

#define LCD_RS_PIN			PB0 
#define LCD_RW_PIN			PB1
#define LCD_EN_PIN			PB2
#define LCD_DATA_4_PIN		PB4
#define LCD_DATA_5_PIN		PB5
#define LCD_DATA_6_PIN		PB6
#define LCD_DATA_7_PIN		PB7

#endif /* LCDCFG_H_ */