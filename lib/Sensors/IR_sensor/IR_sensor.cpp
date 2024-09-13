#include "IR_sensor.h"
#include "geometry.h"
// Initial IR sensor
void IR_sensor::init(int address)
{
    address_ = address;
    Wire.begin();
}

// Update IR sensor
void IR_sensor::update(int g)
{
    Wire.requestFrom(IR_SENSOR_ADDRESS, 2 * sizeof(short));

    byte buffer[2 * sizeof(short)];
    for (unsigned int i = 0; i < 2 * sizeof(short); i++)
    {
        buffer[i] = Wire.read();
    }
    memcpy(&data, buffer, 2 * sizeof(short));

    angle = between(data[0], -g);
    distance = data[1]*dist_ir/100-5;
    ret = (data[0] > 400);

    Serial.print(" Ball: ");
    Serial.print(angle);
    Serial.print(" ");
    Serial.print(ret);
    Serial.print(" ");
    Serial.print(distance);
}