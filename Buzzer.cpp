#include "Buzzer.h"


Buzzer::Buzzer(int BuzzPin) 
{
    pin = BuzzPin;
    pinMode(pin, OUTPUT);
}


void Buzzer::on(unsigned int frequency, unsigned long duration) 
{
    tone(pin, frequency, duration);
}


void Buzzer::off() 
{
    noTone(pin);
}