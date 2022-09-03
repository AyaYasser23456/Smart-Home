/*
 * I2cCfg.h
 *
 * Created: 03/06/2022 04:41:24 م
 *  Author: dell
 */ 


#ifndef I2CCFG_H_
#define I2CCFG_H_
/********************************_SELECT_SLAVE_ADDRESS_*****************************/
#define SLAVE_ADDRESS        1
/********************************_GENERAL_CALL_CONTROL_*****************************/
// option 1 -> [ 0 ] -> DISABLE_GENERAL_CALL
// option 2 -> [ 1 ] -> ENABLE_GENERAL_CALL
#define GENERAL_CALL         1
/********************************_SELECT_I2C_MODE_*****************************/
// option 1 -> [ I2C_MASTER ]
// option 2 -> [ I2C_SLAVE  ]
#define I2C_MODE        I2C_MASTER
#endif /* I2CCFG_H_ */