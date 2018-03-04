/*
 * TI2C.cpp
 *
 * Created: 2018/02/18 18:50:52
 *  Author: ip.sakura
 */ 
#include "TI2C.h"

const char postfix = '$';
Data TI2C_buf;
void (*TI2C_recv_cb)(char*);
void (*TI2C_req_cb)();


void TI2C_init(uint8_t address, void (*recv)(char*), void (*req)()){
	TI2C_recv_cb = recv;
	TI2C_req_cb = req;
	I2C_init(address);
	I2C_setCallbacks(TI2C_char_received, TI2C_requested);
}


void TI2C_received(char *str) //slave <-
{
	TI2C_recv_cb(str);
	// printf();
}

void TI2C_requested() //→master
{
	//I2C_transmitByte(data);
}

void TI2C_char_received(uint8_t received_data) {
	DDRC = 0b00000010;
	static int i = 0;
	// データに追加
	TI2C_buf.uint_buf[i] = received_data;	
	// postfixが来た場合にコールバックを呼んで初期化
	if (TI2C_buf.str_buf[i] == postfix) {
		TI2C_buf.str_buf[i] = '\0';
		TI2C_received(TI2C_buf.str_buf);
		i = 0;
	} else {
		i++;
	}	
}

