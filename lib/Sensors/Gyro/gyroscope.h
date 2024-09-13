#ifndef _gyro_H_
#define _gyro_H_

#include "config.h"

// ----------------------------------------------------------------

class Gyroscope
{
public:
    void init();
    void update();
    float angle;
    char buffer[50];
    float heading;
private:
    unsigned char Re_buf[8], counter = 0;
};

#endif // _gyro_H_