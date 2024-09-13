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
    int find_coords(int, int, float);
    char buff[128];
    int ang[2]={0,0};
    int perpend;
private:
    int h_1, h_2, w_1, w_2, main_a, angl_3, angl_4;
    int rez_coord[3] = {0, 0, 0};
    int goals_angle[2] = {0, 0};

};

#endif // _SPI_H_