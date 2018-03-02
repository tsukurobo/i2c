/*
 * TI2C.cpp
 *
 * Created: 2018/02/18 18:50:52
 *  Author: ip.sakura
 */ 
#include "TI2C.h"

const char postfix = '$';

TI2C::TI2C(uint8_t address, void (*recv)(char*), void (*req)()){
	this->recv_cb = recv;
	this->req_cb = req;
	I2C_init(address);
}


void TI2C::received(char *str) //slave <-
{
	this->recv_cb(str);
	// printf();
}

void TI2C::requested() //→master
{
	//I2C_transmitByte(data);
}

void TI2C::char_received(uint8_t received_data) {
	static int i = 0;
	// データに追加
	this -> buf.uint_buf[i] = received_data;	
	// postfixが来た場合にコールバックを呼んで初期化
	if (this -> buf.str_buf[i] == postfix) {
		buf.str_buf[i] = '\0';
		this->received(buf.str_buf);
	}
	
}