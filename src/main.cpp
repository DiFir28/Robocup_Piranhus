#include "config.h"
#include "inits.h"
#include <SPI.h>
#include "config.h"

void setup()
{
  init();
  Serial.begin(19200);
  delay(1000);
}

void loop()
{
  sensors.update();

  delay(1);
}
