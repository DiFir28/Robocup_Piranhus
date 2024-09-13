#include "config.h"
#include "inits.h"
#include "config.h"

void setup()
{
  init();
  Serial.begin(19200);
  delay(1000);
}

void loop()
{
  // Serial.print(millis());
  // Serial.print(" - ");
  sensors.update();
  // if (!ballRet){
  //   if (abs(ballAng) > 90){
  //     go(180 -  sign(ballAng) * atan2(30, ballDis)*RAD_TO_DEG, 0);
  //     Serial.print(" ");
  //     Serial.print(180 -  sign(ballAng) * atan2(30, ballDis)*RAD_TO_DEG);

  //   }else{

  //     go(ballAng + sign(ballAng)*atan2(30, ballDis)*RAD_TO_DEG, 0);
  //     Serial.print(" ");
  //     Serial.print(ballAng + sign(ballAng)*atan2(30, ballDis)*RAD_TO_DEG);
  //   }
    
  // }else{

    
  // }
  sensors.camera.find_coords(sensors.camera.ang[0], sensors.camera.ang[1], gyro);
  Serial.println("");
  delay(1);
}
