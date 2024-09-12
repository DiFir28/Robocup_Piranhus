#include <SPI.h>
// Initial SPI
void spi::init()
{
  pinMode(SS_PIN, OUTPUT);
  Serial.begin(BAUD_RATE);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  SPI.setDataMode(SPI_MODE0);
  Serial.println(1);
  Serial.print("SPI is ready");
  int data = [];
}

// read data from camera
void spi::read()
{
  int32_t len = 0;
  char buff[CHAR_BUF] = { 0 };
  digitalWrite(SS_PIN, LOW);
  delay(1);
  if (SPI.transfer(1) == 85) { 
    SPI.transfer(&len, 4);     
    if (len) {
      SPI.transfer(&buff, min(len, CHAR_BUF));
      len -= min(len, CHAR_BUF);
    }
    while (len--) SPI.transfer(0);
  }
  digitalWrite(SS_PIN, HIGH);
  Serial.print(buff);  
}