/*
 * I2CRobosa.h
 *
 * Created: 2018/02/18 18:51:12
 *  Author: ip.sakura
 */ 


#ifndef I2CROBOSA_H_
#define I2CROBOSA_H_

#include "I2CSlave.h"

#define SIZE 1024

union Data {
	uint8_t uint_buf[SIZE];
	char str_buf[SIZE];
};
union Data_Bit {
	uint8_t uint_buf;
	char str_buf;
};
	
class I2CRobosa
{
	Data buf;
	public:
	I2CRobosa(uint8_t address);
	void send_str(char* buf);
	void get_str(char* buf);
	void I2C_received(uint8_t received_data);
	void I2C_requested();	
};


#endif /* I2CROBOSA_H_ */