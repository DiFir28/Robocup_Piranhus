#include "SPI_camera.h"

// Initial SPI
void spi_camera::init()
{
  pinMode(SS_PIN, OUTPUT);
  Serial.begin(BAUD_RATE);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  SPI.setDataMode(SPI_MODE0);
  delay(1000);
  Serial.print("SPI is ready");
}

// read data from camera
void spi_camera::update()
{
  int32_t len = 0;
  char buff[CHAR_BUF] = {0};
  digitalWrite(SS_PIN, LOW);
  delay(1);
  if (SPI.transfer(1) == 85)
  {
    SPI.transfer(&len, 4);
    if (len)
    {
      SPI.transfer(&buff, min(len, CHAR_BUF));
      len -= min(len, CHAR_BUF);
    }
    while (len--)
      SPI.transfer(0);
  }
  digitalWrite(SS_PIN, HIGH);

  for (int i = 0; i < 4; i++)
  {
    char angch[5] = "";
    strncpy(angch, buff + i * 5, 4);
    ang[i] = atoi(angch);}
    Serial.print("  ");
    Serial.print(buff);
    for (int i = 0; i < 4; i++){
    Serial.print("  ");
    Serial.print(ang[i]);}
  // for (int i = 0; i < 4; i++)
  // {
  //   Serial.print("  ");
  //   Serial.print(ang[i]);
  // }
}

void spi_camera::find_coords(float gyro_angle, int angle_1, int angle_2){
  goal_angles[0] = between(angle_1, angle_2);
  goal_angles[1] = 90 - goal_angles[0];
  goal_angles[2] = 180 - (goal_angles[0] + goal_angles[1]);
  gip = 60 / sin(goal_angles[0]) * sin(goal_angles[2]);
  perpend = gip / 1 * sin(goal_angles[1]);
  return perpend;

}