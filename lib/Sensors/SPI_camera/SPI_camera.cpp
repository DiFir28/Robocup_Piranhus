#include "SPI_camera.h"

// Initial SPI
void spi_camera::init()
{
  pinMode(10, OUTPUT);
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
  for (int i = 0; i < 2; i++) 
  {
    char angch[5] = "";
    strncpy(angch, buff + i * 5, 4);
    goal_ans[i] = atoi(angch);
  }
}

void spi_camera::coords_find(int gyro_ang, bool goal){
  //угол до центра ворот с поправкой на gyro
    perf_ang[0] = between(goal_ans[0], gyro_ang); //cиние
    perf_ang[1] = between(goal_ans[1], gyro_ang); //жёлтые
    crds.angle = between(perf_ang[0], perf_ang[1]); //угол между центрами ворот
    crds.y = 60 / sin(DEG_TO_RAD * crds.angle) * sin(DEG_TO_RAD * perf_ang[0]) * sin(DEG_TO_RAD * perf_ang[1]);
    crds.x = abs(crds.y) / tan(DEG_TO_RAD * abs(perf_ang[goal]));

    Serial.print(" angles to goals: ");
    Serial.print(perf_ang[0]);
    Serial.print("  ");
    Serial.print(perf_ang[1]);
    Serial.print(" coords: ");
    Serial.print(crds.x);
    Serial.print("  ");
    Serial.print(crds.y);

}