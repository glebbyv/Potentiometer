#ifndef STEERING_ANGLE_H
#define STEERING_ANGLE_H
#include <stdint.h> 
class StPot
{
  private:
  int potPin;// attached pin
  
  public:
  uint8_t msb,lsb;// atributes of the class
  StPot(int Pin); //class of steering potentiometer 
  int angleRead();// reading Potentiometers value
  void conv2bytes();// converting int value into 2 bytes(msb and lsb)

};


#endif