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
    ang[i] = atoi(angch);
  }
    // Serial.print("  ");
  Serial.print(" buff: ");
    //for (int i = 0; i < 4; i++){
    //Serial.print("  ");
    //Serial.print(ang[i]);}
  

   for (int i = 0; i < 2; i++)
  {
    Serial.print(" ");
    Serial.print(ang[i]);
  }
}

int spi_camera::find_coords(int angle_1, int angle_2, float gyro_angle)
{
  angle_1 = between(angle_1, gyro_angle);
  angle_2 = between(angle_2, gyro_angle);
  main_a = between(angle_1, angle_2); //- gyro_angle
  w_1 = 60 / sin(DEG_TO_RAD * (main_a)) * sin(DEG_TO_RAD * (angle_1)) * sin(DEG_TO_RAD * (angle_2)); 
  h_1 = 30 - (abs(w_1) / tan(DEG_TO_RAD * abs(angle_1)));
  h_2 = 30 + (abs(w_1) / tan(DEG_TO_RAD * abs(angle_2)));

  rez_coord[0] = {w_1};
  rez_coord[1] = {30 - h_1};
  // Serial.print("    angles: ");
  // Serial.print(angle_1);
  // Serial.print("  ");
  // Serial.print( angle_2);
  // Serial.print("  ");
  // Serial.print(main_a);
  Serial.print("  ");
  Serial.print("    height: ");
  // Serial.print("   ");
  Serial.print(w_1);
  Serial.print("   ");
  Serial.print(h_1);
  Serial.print("   ");
  Serial.print(h_2);
  Serial.print("   ");
  return ;
}