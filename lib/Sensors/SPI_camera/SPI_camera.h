#ifndef _SPI_camera_H_
#define _SPI_camera_H_

#include "config.h"

#include <SPI.h>
//----------------------------------------------------------------

class spi_camera
{
public:
    void init();
    void update();
    char buff[128];
    int ang[4]={0,0,0,0};
private:

};

#endif // _SPI_H_