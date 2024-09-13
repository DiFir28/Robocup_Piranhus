#ifndef _config_H_
#define _config_H_

#include <Arduino.h>

#define POWER 60.0 / 100 * 255
#define POWER_ROT_MAX 180

#define GYRO_SERIAL_ Serial8

#define IR_SENSOR_ADDRESS 0x9
#define IR_SENSOR_QUANTITY_BYTE sizeof(short)*2

#define SS_PIN 10
#define BAUD_RATE 19200
#define CHAR_BUF 128

#define dist_ir 5.5

#define gyro sensors.gyro_.angle
#define lineAngle sensors.li.angle
#define lineLenght sensors.li.lenght

#endif // _config_H_
