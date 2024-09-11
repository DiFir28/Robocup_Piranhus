#include "config.h"
#include "inits.h"

Leds l;
void but5()
{
  Serial.println("Новое пороговое: ");
}

void setup()
{
  init();

  Serial.begin(115200);  
  pinMode(13, INPUT);
  
  
}

void loop(){
  Serial.print(millis());
  delay(10);
  Serial.println("");
  l.off();
  l.on(millis()/1000%4,0,100,0);

}
