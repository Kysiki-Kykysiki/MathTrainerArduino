#pragma once
#include <Arduino.h>

class Buzzer 
{
private:
    int pin; 
public:
    Buzzer(int BuzzPin); 
    
    void on(unsigned int frequency, unsigned long duration); // Включить звук
    void off(); 
};