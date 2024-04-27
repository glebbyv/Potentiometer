#ifndef STEERING_ANGLE_H
#define STEERING_ANGLE_H
#include <stdint.h> 
class StPot
{
  private:
  uint8_t msb,lsb;
  public:
  StPot();
  void setup();
  int angleRead();
  void conv2bytes(int angle);

};

//extern saclass steering_angle; // name to access the class type

#endif