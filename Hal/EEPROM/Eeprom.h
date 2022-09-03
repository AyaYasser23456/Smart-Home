/*
 * Eeprom.h
 *
 * Created: 04/06/2022 03:01:08 م
 *  Author: dell
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

/*********************************_INCLUDES_******************************/
#include "EepromCfg.h"
#include "I2c.h"
#include "StdTypes.h"
/***********************************_MACOS_*******************************/

/********************************_PROTOTYPES_*****************************/
void H_Eeprom_Init(void);
void H_Eeprom_Write(u8 Local_u8_Data,u8 Local_u8_PageAddress,u8 Local_u8_ByteAddress);
u8   H_Eeprom_Read(u8 Local_u8_PageAddress,u8 Local_u8_ByteAddress);

#endif /* EEPROM_H_ */