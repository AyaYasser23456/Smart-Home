/*
 * I2c.h
 *
 * Created: 03/06/2022 04:41:13 م
 *  Author: dell
 */ 


#ifndef I2C_H_
#define I2C_H_


/*********************************_INCLUDES_****************************************/
#include "I2cCfg.h"
#include "StdTypes.h"
#include "BitMath.h"
#include "Reg.h"
#define F_CPU 16000000UL

#include <util/delay.h>
/***********************************_MACOS_*****************************************/
#define I2C_MASTER                        1
#define I2C_SLAVE                         2
#define START_CONDITION_TRANSMITTED       0x08
#define REP_START_ACK                     0x10		// repeated start
#define SLAVE_AD_AND_WR_ACK               0x18		// master transmit [ slave address + write request ] ACK
#define SLAVE_AD_AND_RD_ACK               0x40		// master transmit [ slave address + read  request ] ACK
#define WR_BYTE_ACK                       0x28		// master transmit data ACK
#define RD_BYTE_WITH_NACK			      0x58		// master received data with NACK
#define RD_BYTE_WITH_ACK			      0x50		// master received data with  ACK
#define SLAVE_ADD_REC_RD_REQ		      0xA8		// slave address received with write request
#define SLAVE_ADD_REC_WR_REQ              0x60		// slave address received with read  request
#define SLAVE_DATA_REC                    0x80		// read  byte request received
#define SLAVE_BYTE_TRANSMITTED            0xC0		// write byte request received
/********************************_PROTOTYPES_***************************************/
void M_I2c_Init(void);
void M_I2c_StartCondition(void);
void M_I2c_SendSlaveAddressWrite(u8);
void M_I2c_SendSlaveAddressRead(u8);
void M_I2c_SendSByte(u8);
u8   M_I2c_ReadByte(void);
void M_I2c_RepeatedStart(void);
void M_I2c_StopCondition(void);
u8 M_I2c_ReadByteNoAck();
#endif /* I2C_H_ */