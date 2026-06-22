#pragma once
#include <Arduino.h>

class Photoresistor {
private:
  int _sensor_pin;
  int _led_pin;
  int _dark_limit;

public:
  
  Photoresistor(int sensor_pin, int led_pin, int dark_limit);

  void photoresistor_init();
  int  photoresistor_read_raw();       // сырое значение 0–1023
  bool photoresistor_is_dark();        // true, если темно
};