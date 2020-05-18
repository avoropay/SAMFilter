/*
   Simple moving average

   copyright (c) Andrii Voropai, 2020
   andre.voropay@gmail.com

   Released under GPLv3.
   Please refer to LICENSE file for licensing information.

   https://en.wikipedia.org/wiki/Moving_average
*/

#ifndef SMAFILTER_H_
#define SMAFILTER_H_
#include <limits.h>

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class MovingAverageFilter {
  private:
    uint8_t _numberOfTime; // number (n) of time periods
    int _stackPosition;
    int _sumValues;
    int _diveder;
    float *_stackValues;

  public:
    MovingAverageFilter(uint8_t numberOfTime);
    float getSAM(float newValue); // get Averange between all values
    float getValue(int stackPosition); // Between 0 .. _numberOfTime
    void resetStack();
};
#endif
