#include <Wire.h>
#include "ti2c.h"

// main for testing.
uint8_t addr = 0x10;
Ti2c ti2c = Ti2c(addr);
char buf[100];

void setup(){
  Wire.begin();
  Serial.begin(9600);
  Serial.println("start");
}

void loop(){
  //Wire.requestFrom(addr, 1);
  ti2c.sendStr("0");
  ti2c.receiveStr(buf);
  Serial.println(buf);
  delay(1000);
  ti2c.sendStr("1234"); 
  delay(1000);
  ti2c.sendStr("2"); 
  delay(1000);

}
