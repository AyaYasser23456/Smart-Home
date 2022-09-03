/*
 * Eeprom.c
 *
 * Created: 04/06/2022 03:00:59 م
 *  Author: dell
 */ 
#include "Eeprom.h"

void H_Eeprom_Init(void)
{
	M_I2c_Init();
}
void H_Eeprom_Write(u8 Local_u8_Data,u8 Local_u8_PageAddress,u8 Local_u8_ByteAddress)
{
	if(Local_u8_PageAddress < 8)
	{
		M_I2c_StartCondition();
		M_I2c_SendSlaveAddressWrite((0x50 | Local_u8_PageAddress));
		M_I2c_SendSByte(Local_u8_ByteAddress);
		M_I2c_SendSByte(Local_u8_Data);
		M_I2c_StopCondition();
	}
}
u8   H_Eeprom_Read(u8 Local_u8_PageAddress,u8 Local_u8_ByteAddress)
{
	u8 Local_u8_Data = 0;
	M_I2c_StartCondition();
	M_I2c_SendSlaveAddressWrite((0x50 | Local_u8_PageAddress));
	M_I2c_SendSByte(Local_u8_ByteAddress);
	M_I2c_RepeatedStart();
	M_I2c_SendSlaveAddressRead((0x50 | Local_u8_PageAddress));
	Local_u8_Data = M_I2c_ReadByteNoAck();
	M_I2c_StopCondition();
	return Local_u8_Data;
}