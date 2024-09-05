#include "config.h"

// #include <line.h>
#include "leds.h"

#include "movement.h"

Leds l;
void but5()
{
  Serial.println("Новое пороговое: ");
}

void setup()
{
  // motors_init();
  l.init(4,31,39);

  Serial.begin(115200);  
  pinMode(13, INPUT);
  
  
}

void loop(){
  go(0, 0);
  delay(10);
  Serial.println("");
  l.colorWipe(0,100,0,100);
}
