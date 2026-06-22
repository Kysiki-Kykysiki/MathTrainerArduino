#pragma once
#include <Arduino.h>

class Button {
  int pin;
  bool lastState;

public:
  bool press;
  int pressCount;
  Button ();
  Button(int);

  void update();
  bool wasPressed();
  void resetCount();
  int get_pressCount();
};
