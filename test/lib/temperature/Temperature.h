#pragma once
#include <Arduino.h>

class Temperature {
private:
  int sensor_pin;
  int led_pin;
  float threshold;
  const float BETA = 3950.0;

public:
 
  Temperature(int sensor_pin, int led_pin, float threshold_temp = 40.0);

  void  temperature_init();
  float temperature_read_celsius();    // температура в °C
  bool  temperature_is_hot();          // true, если > порога
};