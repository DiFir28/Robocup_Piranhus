#include "config.h"
#include "inits.h"
#include "config.h"
#include "Wire.h"
void setup()
{
  Wire.begin();
  init();
  Serial.begin(19200);
  delay(1000);
}

void loop()
{
  sensors.update();
  int son_data[2] = {0, 0};
  Serial.print(" SONICS: ");
  Wire.requestFrom(0x08, 2*sizeof(int));
  byte buffer[2*sizeof(int)];
  for (int i = 0; i < 2*sizeof(int); i++) {
     buffer[i] = Wire.read();
     Serial.print(" ");
   }
  memcpy(&son_data, buffer, 2*sizeof(int));
  Serial.print(son_data[1]);


  // // Serial.print(millis());
  // // Serial.print(" - ");
  // sensors.update();
  if (son_data){
   if (!ballRet){
    if (abs(ballAng) < 50){
      go(90 * sign(ballAng), 0);
      }
    }
  }
  Serial.println("");
  delay(1);
}
