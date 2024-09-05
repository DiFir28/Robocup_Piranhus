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
    Wire.requestFrom(address_, IR_SENSOR_QUANTITY_BYTE);
    int i = 0;
    char char_angle[4] = "";
    char buf[10];
    while (1 < Wire.available()) // organizes the data from the slave in the table
    {
        buf[i] = Wire.read(); // receive a byte as character
        i++;
    }
    char *char_link = strchr(buf, ',');
    strncpy(char_angle, buf, char_link - buf);
    angle = atoi(char_angle);

    Serial.print(" Ball: ");
    Serial.print(angle);
}