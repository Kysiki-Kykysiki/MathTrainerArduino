#include <Led.h>

Led::Led(){
    pin = 13;
    pinMode(pin, OUTPUT);
}

Led::Led(int p){
    pin = p;
    pinMode(pin, OUTPUT);
}

void Led::blink(int inter){
    blinking = true;
    interval = inter;
}

void Led::on(){
    blinking = false;
    digitalWrite(pin,HIGH);
}

void Led::off(){
    blinking = false;
    digitalWrite(pin,LOW);
}

void Led::update(){
    if(!blinking) return;
    if(millis() - lastToggle >= (unsigned long)interval){
        lastToggle = millis();
        state = !state;
        digitalWrite(pin, state ? HIGH : LOW);
    }
}
