/*
 * I2C_test.cpp
 *
 * Created: 2018/01/21 18:56:19
 * Author : ip.sakura
 */ 

//motordriver_I2C

//I2C
#define F_CPU 1000000UL

#include <avr/io.h>
#include "I2CSlave.h"
#include "I2CRobosa.h"
#include <avr/interrupt.h>
#include <stdlib.h>
#include <util/delay.h>


#define I2C_ADDR 0x10

volatile uint8_t data; //®”0`255‚ğudatav‚ÆŒÄ‚Ñ‚Ü‚·

int pw = 0;


void setup()
{
	// set received/requested callbacks
	//I2C_setCallbacks(I2C_received, I2C_requested);

	// init I2C
	I2C_init(I2C_ADDR);
	
//	DDRD = 0b11100000;  //port7,6,5=output
	
	//pw = 70;
	//motor_set_speed(pw);
}

int main()
{
	setup();

	// Main program loop
	while(1){
	}
}
