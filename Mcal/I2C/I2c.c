/*
 * I2c.c
 *
 * Created: 03/06/2022 04:41:03 م
 *  Author: dell
 */ 
#include "I2c.h"

void M_I2c_Init(void)
{
	ClrBit(TWCR,2);
	#if    I2C_MODE      ==   I2C_MASTER
	TWBR = 12;           // to make Fscl = 400 Khz
	#elif  I2C_MODE      ==   I2C_SLAVE
	TWAR = ((SLAVE_ADDRESS << 1) | GENERAL_CALL); 
	#endif
	SetBit(TWCR,2);    // to enable i2c circuit
	_delay_ms(10);
}
void M_I2c_StartCondition(void)
{
	SetBit(TWCR,5);
	SetBit(TWCR,7);                  //   to clear the flag bit
	while(GetBit(TWCR,7) == 0);
	while((TWSR & 0xF8) != START_CONDITION_TRANSMITTED);
	_delay_ms(10);
}
void M_I2c_SendSlaveAddressWrite(u8 Local_u8_Address)  
{
	TWDR = (Local_u8_Address << 1);
	SetBit(TWCR,7);                  //   to clear the flag bit
	while(GetBit(TWCR,7) == 0);
	while((TWSR & 0xF8) != SLAVE_AD_AND_WR_ACK);
	_delay_ms(10);
}
void M_I2c_SendSlaveAddressRead(u8 Local_u8_Address)
{
	TWDR = ((Local_u8_Address << 1) | 1);
	SetBit(TWCR,7);                  //   to clear the flag bit
	while(GetBit(TWCR,7) == 0);
	while((TWSR & 0xF8) != SLAVE_AD_AND_RD_ACK);
	_delay_ms(10);
}
void M_I2c_SendSByte(u8 Local_u8_Byte)
{
	TWDR = Local_u8_Byte;
	ClrBit(TWCR,5);                  //   later
	SetBit(TWCR,7);                  //   to clear the flag bit
	while(GetBit(TWCR,7) == 0);
	while((TWSR & 0xF8) != WR_BYTE_ACK);
	_delay_ms(100);
}
u8   M_I2c_ReadByte(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(GetBit(TWCR,TWINT)==0);
	return TWDR;
//     ClrBit(TWCR,5);                  //   later
//     ClrBit(TWCR,4);					 //   later
//     SetBit(TWCR,6);					 //   later
// 	SetBit(TWCR,7);                  //   to clear the flag bit
// 	while(GetBit(TWCR,7) == 0);
// 	while((TWSR & 0xF8) != RD_BYTE_WITH_ACK);
// 	return TWDR;
}
u8 M_I2c_ReadByteNoAck()
{
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(GetBit(TWCR,TWINT) == 0);
	return TWDR;
}
void M_I2c_RepeatedStart(void)
{
	SetBit(TWCR,5);
	SetBit(TWCR,7);                  //   to clear the flag bit
	while(GetBit(TWCR,7) == 0);
	while((TWSR & 0xF8) != REP_START_ACK);
}
void M_I2c_StopCondition(void)
{
//  	SetBit(TWCR,7);                  //   to clear the flag bit
//  	SetBit(TWCR,4);
// // 	SetBit(TWCR,2);	
	//while(GetBit(TWCR,7) == 0);
	//TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
	SetBit(TWCR,4);
	SetBit(TWCR,7);
	_delay_ms(1);
}