#include <Arduino.h>
#include <stdint.h> 
#include "steering_angle.h"

const int potPin = A0;

  // Implement the constructor
  StPot::StPot() {
    msb=0;
    lsb=0;
  }

 /* typedef struct{
    uint8_t msb;
    uint8_t lsb;
  } CanBytes;*/

  // Implement the setup method
  void StPot::setup() {
    pinMode(potPin, INPUT);
  }

  // Implement the angleRead method
  int StPot::angleRead() {
    return analogRead(potPin);
  }

  void StPot::conv2bytes(int angle){

    msb=angle >> 2;
    lsb=angle & 3;

  }

// Initialize an instance of the class
//saclass::SteeringAngle steering_angle;