#include "sensors.h"

// Initialize sensors

void Sensors::init()
{
    IR.init(IR_SENSOR_ADDRESS);
    gyro_.init();
    li.init();
    camera.init();
}

// Update sensor data
void Sensors::update()
{
    IR.update();
    gyro_.update();
    line = li.update();
    camera.update();
}
