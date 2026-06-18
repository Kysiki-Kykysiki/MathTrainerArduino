#include "Buzzer.h"


Buzzer::Buzzer(int BuzzPin) 
{
    pin = BuzzPin;
    pinMode(pin, OUTPUT);
}


void Buzzer::on() 
{
    tone(8, 262, 250);
}


void Buzzer::off() 
{
    noTone(pin);
}