#ifndef _structs_H_
#define _structs_H_

#include <Arduino.h>
struct line
{
  short lenght;
  short angle;
};

struct coords
{
  short x = 0;
  short y = 0;
  short angle = 0;
};

class triangle
{
  line first;
  line second;
  line third;
};

struct lisens
{
  bool bool_value = 0;
  bool broken = 0;
  line vector;
  short analog_value = 0;
  short value = 1;
  short max_value = 0;
  short min_value = 0;
  short threshold_value = 200;
};

#endif