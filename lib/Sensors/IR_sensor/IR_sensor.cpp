#include "IR_sensor.h"

// Initial IR sensor
void IR_sensor::init(int address)
{
    address_ = address;
    Wire.begin();
}

// Update IR sensor
void IR_sensor::update()
{
    Wire.requestFrom(IR_SENSOR_ADDRESS, 2 * sizeof(short));

    byte buffer[2 * sizeof(short)];
    for (unsigned int i = 0; i < 2 * sizeof(short); i++)
    {
        buffer[i] = Wire.read();
    }
    memcpy(&data, buffer, 2 * sizeof(short));

    Serial.print(" Ball: ");
    Serial.print(data[0]);
    Serial.print(" ");
    Serial.print(data[1]*5.5-5);
}