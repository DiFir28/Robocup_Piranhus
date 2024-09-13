
#ifndef _sensors_H_
#define _sensors_H_

#include "config.h"
#include "Wire.h"

#include "line/line_2.h"
#include "Gyro/gyroscope.h"
#include "IR_sensor/IR_sensor.h"
#include "SPI_camera/spi_camera.h"

//----------------------------------------------------------------
// Sensors class declaration
//---------------------------
// This class encapsulates the initialization and updating of the
// gyroscope and IR sensor.

class Sensors
{
public:
    void init();
    void update();
    IR_sensor IR;
    Gyroscope gyro_;
    lisenses li;
    spi_camera camera;
    vec line;

private:
};


#endif // _sensors_H_