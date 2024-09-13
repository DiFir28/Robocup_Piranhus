#ifndef _SPI_camera_H_
#define _SPI_camera_H_
#include <SPI.h>

#include "config.h"
#include "geometry.h"

//----------------------------------------------------------------

class spi_camera
{
public:
    void init();
    void update();
    int find_coords(int, int, int);
    char buff[128];
    int ang[4]={0,0,0,0};
    int perpend;
private:
    float goal_angles[3] = {0, 0, 0};
    int gip;

};

#endif // _SPI_H_