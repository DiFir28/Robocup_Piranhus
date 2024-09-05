#ifndef _IR_sensor_H_
#define _IR_sensor_H_

#include "config.h"
#include "Wire.h"

//----------------------------------------------------------------

class IR_sensor
{
public:
    void init(int address);
    void update();
    int angle;

private:
    int address_;
};

#endif // _IR_sensor_H_