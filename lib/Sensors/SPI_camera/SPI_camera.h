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
    void update(bool); //0 - синий, 1 - жёлтый
    int find_coords(int, int, float);
    int help_gyro();
    char buff[128];
    int goal_angl[2]={0,0};
    int c_g;
    int perpend;
    int sum;
    bool fl;

private:
    int h_1, h_2, w_1, w_2, main_a, angl_3, angl_4;
    int rez_coord[3] = {0, 0, 0};
    int goals_angle[2] = {0, 0};
};

#endif // _SPI_H_