#include <PhotoResistor.h>

PhotoResistor::PhotoResistor(){
    pin = A0;
    pinMode(pin, INPUT);
}
PhotoResistor::PhotoResistor(int p){
    pin = p;
    pinMode(pin, INPUT);
}

int PhotoResistor::get_PData(){
    return analogRead(pin);
}