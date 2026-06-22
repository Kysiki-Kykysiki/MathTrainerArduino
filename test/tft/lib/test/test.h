#pragma once
#include <Arduino.h>

class Button {
  int pin;
  int pressCount;
  bool lastState;
  bool press;
  
public:
  Button ();
  Button(int);

  void update();
  void resetCount();
  bool pressed();
  int get_pressCount();

};