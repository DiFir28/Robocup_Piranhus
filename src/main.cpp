#include "config.h"

// #include <line.h>
 #include "leds.h"
//  #include "line_2.h"
 #include "movement.cpp"

Leds l;
void but5()
{
  Serial.println("Новое пороговое: ");
}

void setup()
{
  sensors.init();
   motors_init();
  l.init(4,31,39);

  Serial.begin(115200);  
  pinMode(13, INPUT);
  
  
}

void loop(){
  sensors.li.update();
  Serial.print(millis());
  // line_detect();
  // sensors.update();
  // go(180,200 );
  delay(10);
  Serial.println("");
  l.off();
  l.on(millis()/1000%4,0,100,0);

}
