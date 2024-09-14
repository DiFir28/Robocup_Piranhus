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
    leds.init(4,31,39);
    leds.on(0,0,50,0);
    sensors.init();
    leds.on(1,0,50,0);
    sensors.gyro_.update();
    b5.init(5,a);
    leds.on(2,0,50,0);
    
    motors_init();
    leds.on(3,0,50,0);
    Serial.println(" Init end");
 }

