#include "gyroscope.h"

void Gyroscope::init()
{
    GYRO_SERIAL_.begin(115200);
    delay(3000);

    GYRO_SERIAL_.write(0xA5);
    GYRO_SERIAL_.write(0x54);
    delay(1000);

    GYRO_SERIAL_.write(0xA5);
    GYRO_SERIAL_.write(0x55);
    delay(1000);

    GYRO_SERIAL_.write(0xA5);
    GYRO_SERIAL_.write(0x53);
}

void Gyroscope::update()
{
    GYRO_SERIAL_.write(0XA5);
    GYRO_SERIAL_.write(0X51); // send it for each read
    while (GYRO_SERIAL_.available())
    {
        Re_buf[counter] = (unsigned char)GYRO_SERIAL_.read();
        if (counter == 0 && Re_buf[0] != 0xAA)
            return;
        counter++;
        if (counter == 8) // package is complete
        {
            counter = 0;
            if (Re_buf[0] == 0xAA && Re_buf[7] == 0x55) // полученные данные правильны
            {
                angle = (int16_t)(Re_buf[1] << 8 | Re_buf[2]) / 100.00;
            }
        }
    }

    Serial.print(" Gyro: ");
    Serial.print(angle);
}