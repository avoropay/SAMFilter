/*
   Example Simple moving average with static object

   copyright (c) Andrii Voropai, 2020
   andre.voropay@gmail.com

   Released under GPLv3.
   Please refer to LICENSE file for licensing information.

   https://en.wikipedia.org/wiki/Moving_average
*/

#include <SMAFilter.h>

#define STACKSIZE 10

MovingAverageFilter filtredVoltageValue(STACKSIZE);

float voltageArray[20] = {9.2, 3.0, 2.0, 4.8, 3.6, 2.1, 7.0, 8.4, 9.2, 11.1, 3.6, 2.1, 7.0, 8.4, 9.2, 11.1, 9.2, 3.0, 2.0, 4.8};

void setup() {
  Serial.begin(9600);

  Serial.println(F("Array of Voltage"));
  for (int index = 0; index < STACKSIZE; index++) {
    Serial.print(voltageArray[index]);
    Serial.print(F(" "));
  }
  Serial.println();
  Serial.println();
}

void loop() {
  float avg = 0.0;
  for (int indexVoltage = 0; indexVoltage < 20; indexVoltage++) {
    avg = filtredVoltageValue.getSAM(voltageArray[indexVoltage]);

    Serial.println(F("Array for Average"));
    for (int index = 0; index < STACKSIZE; index++) {
      Serial.print(filtredVoltageValue.getValue(index));
      Serial.print(F(" "));
    }
    Serial.println();


    Serial.print(F("Average = "));
    Serial.println(avg);
  }
  Serial.println();
  delay(6000);
}
