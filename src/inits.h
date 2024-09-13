#include "button.h"
 #include "leds.h"
#include "sensors.h"
 #include "movement.cpp"

Leds leds;
button b5;

void a(){
    sensors.li.calib();
}

 void init(){
    sensors.init();
    sensors.gyro_.update();
    b5.init(5,a);
    leds.init(4,31,39);
    motors_init();
    Serial.println("Init end");
 }

