/*
   Simple moving average

   copyright (c) Andrii Voropai, 2020
   andre.voropay@gmail.com

   Released under GPLv3.
   Please refer to LICENSE file for licensing information.

   https://en.wikipedia.org/wiki/Moving_average
*/

#include "SMAFilter.h"
#include <float.h>

MovingAverageFilter::MovingAverageFilter(uint8_t numberOfTime) {
  _numberOfTime = numberOfTime;
  // Check maximun stack length limit
  if (1023 * numberOfTime < FLT_MAX) {
    _stackValues = malloc(numberOfTime * sizeof(float));
    resetStack();
  }
}

// Between 0 .. _numberOfTime
// if inititalisation was correct and stackPosition between 0 and selected stack size
float MovingAverageFilter::getValue(int stackPosition) {
  float result = 0.0;
  if ((1023 * _numberOfTime < FLT_MAX) && stackPosition < _numberOfTime) {
    result = _stackValues[stackPosition]  ;
  }
  return result;
}

// Clear all allocated memory and reset variable to zero
void MovingAverageFilter::resetStack() {
  _stackPosition = 0;
  _diveder = 0;
  _sumValues = 0;
  if (1023 * _numberOfTime < FLT_MAX) { // Only if if inititalisation was correct
    memset(_stackValues, 0, _numberOfTime * sizeof(float));
  }
}


float MovingAverageFilter::getSAM(float newValue) {
  float result = 0.0;
  if (1023 * _numberOfTime < FLT_MAX) {                         // Chenk if inititalisation was correct
    if (_diveder < _numberOfTime) _diveder++;                   // need to use for first elements until thay become equal _numberOfTime
    _sumValues -= _stackValues[_stackPosition];                 // take away oldest value
    _sumValues += newValue;                                     // add new value
    _stackValues[_stackPosition] = newValue;                    // push new velue
    if (++_stackPosition >= _numberOfTime) _stackPosition = 0;  // Rewind to first element
    result = ((float)_sumValues / _diveder);                    // Average
  }
  return result;
}
