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
#include "TI2C.h"
#include <avr/interrupt.h>
#include <stdlib.h>
#include <util/delay.h>

#include "hd44780.h"

#define I2C_ADDR 0x10

volatile uint8_t data; //®”0`255‚ğudatav‚ÆŒÄ‚Ñ‚Ü‚·


//// lcd
void initHard();
char str[] = "hello avr world";


void i2c_received_cb(char* str) {
	// print to lcd
	
}

void i2c_request_cb() {
	// print to lcd
	
}

TI2C ti2c = TI2C(I2C_ADDR,i2c_received_cb, i2c_request_cb);


void setup()
{
	int i = 0;
	initHard();
	lcd_init();
	for (i = 0; i < 15; i++) {
		lcd_putc(str[i]);
		
	}
}

int main()
{
	setup();

	// Main program loop
	while(1){
	}
}




void initHard() {
	DDRB = 0xff;
	PORTB = 0;
	DDRC = 0x3f;
	PORTC = 0;
	DDRD = 0xf0;
	PORTD = 0;
	
	
	
}