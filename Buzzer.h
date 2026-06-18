#pragma once
#include <Arduino.h>

class Buzzer 
{
private:
    int pin; 
public:
    Buzzer(int BuzzPin); 
    
    void on(); 
    void off(); 
};