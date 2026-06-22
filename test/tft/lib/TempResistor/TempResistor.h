#pragma once
#include <Arduino.h>

class TempResistor{
  int pin;
  const float BETA = 3950;
  float celsius;
public:
  TempResistor();
  TempResistor(int);

  double get_temp();
};