#include "sensors.h"

// Initialize sensors
void Sensors::init()
{
    IR.init(IR_SENSOR_ADDRESS);
    gyro_.init();
}

// Update sensor data
void Sensors::update()
{
    IR.update();
 
    gyro_.update();
}
