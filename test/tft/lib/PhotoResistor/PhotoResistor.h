#pragma once
#include <Arduino.h>

class PhotoResistor {
    int pin;
public:
    PhotoResistor();
    PhotoResistor(int);
    int get_PData();
};