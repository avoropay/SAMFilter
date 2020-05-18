# SAMFilter
Simple moving average Arduino Filter

Define as static object
```c++
#include <SMAFilter.h>

MovingAverageFilter filtredVoltageValue(100);
``` 

Usage

```c++
void loop() {
  float avg = 0.0;

avg = filtredVoltageValue.getSAM(145.76);
```

Define as dinamic object:

```c++
#include <SMAFilter.h>
void setup() {
  filtredVoltageValue = new MovingAverageFilter(100);
``` 

Usage

```c++
void loop() {
  float avg = 0.0;

avg = filtredVoltageValue->getSAM(145.76);
```

Referens to https://github.com/AlexGyver/tutorials
