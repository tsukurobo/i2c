#ifndef Ti2c_h
#define Ti2c_h
#include "Arduino.h"

class Ti2c{
  public:
  Ti2c(uint8_t i2caddr);
  void sendStr();
  void receiveStr();
  private:
};
#endif

