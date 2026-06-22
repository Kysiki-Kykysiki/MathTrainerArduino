#pragma once
#include <Arduino.h>

class Led {
  int pin;
  bool blinking = false;
  bool state = false;
  int interval = 500;
  unsigned long lastToggle = 0;
public:
  Led();
  Led(int);
  void blink(int);
  void on();
  void off();
  void update();
};
