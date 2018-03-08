#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
}
char b_buf[100] = "";
char buf[100] = "";

int i = 0;
void loop() {
  i = 0;
  while(1){
    Wire.requestFrom(0x10, 1);
      //Serial.print(buf);
        byte val = Wire.read();

    while (Wire.available()) {
      //Serial.print(val);
      b_buf[i++] = val;
    }
    if (val == '$'){
      break;
    }
  }
  sprintf(buf, "%s", b_buf);
  Serial.print(buf);

    //SSerial.print(buf);
    Serial.print("\n");


  delay(500);
}
