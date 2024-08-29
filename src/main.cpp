#include "config.h"
#include "structs.h"
#include "classes.h"
#include "geometry.h"
#include "movement.h"

// #include <line.h>

Leds l;
gyro g;

void but5()
{
  Serial.println("Новое пороговое: ");
}

void setup()
{
  g.init();
  delay(1500);
  Serial.begin(115200);
  Serial.println(9);
  pinMode(13, INPUT);
  // attachInterrupt(digitalPinToInterrupt(5), but5, LOW);
  motors_init();
  l.init(4, 31, 39);
  // pinMode(4, OUTPUT);
  // pinMode(2, OUTPUT);
  // pinMode(3, OUTPUT);
}

void loop()
{
  go(80, -90);
  g.update();
  //l.colorWipe(100, 0, 100, 100);
  delay(10);
}
