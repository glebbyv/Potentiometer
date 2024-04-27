#include <Arduino.h>
#include <stdint.h> 
#include "steering_angle.h"

  StPot::StPot(int Pin) {
    potPin = Pin;
    pinMode(potPin, INPUT);
    msb=0;
    lsb=0;
  }


  // reading potentiometer's value
  int StPot::angleRead() {
    return analogRead(potPin);
  }

  //separating potentiometer's value into msb and lsb
  void StPot::conv2bytes(int angle){
    msb=angle >> 2;
    lsb=angle & 3;
  }
