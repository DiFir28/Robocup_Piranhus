#ifndef _SPI_camera_H_
#define _SPI_camera_H_

#include "config.h"
#include "geometry.h"

#include <SPI.h>
//----------------------------------------------------------------

class spi_camera
{
public:
    void init();
    void update();
    void find_coords(float, int, int);
    char buff[128];
    int ang[4]={0,0,0,0};
private:
    float goal_angles[3] = {0, 0, 0};
    int gip, perpend;

};

#endif // _SPI_H_