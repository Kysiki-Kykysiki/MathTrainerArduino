#include <TempResistor.h>


TempResistor::TempResistor(){
    pin = A0;
    pinMode(pin,INPUT);
}
TempResistor::TempResistor(int p){
    pin = p;
    pinMode(pin,INPUT);
}

double TempResistor::get_temp(){
    int analogValue = analogRead(pin);
    celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
    return celsius;
}
