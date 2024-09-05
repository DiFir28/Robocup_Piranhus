#ifndef _config_H_
#define _config_H_

#include <Arduino.h>

#define POWER 60.0 / 100 * 255
#define POWER_ROT_MAX 180

#define GYRO_SERIAL_ Serial8

#define IR_SENSOR_ADDRESS 0x9
#define IR_SENSOR_QUANTITY_BYTE 8

#define gyro sensors.gyro_.angle

#endif // _config_H_
