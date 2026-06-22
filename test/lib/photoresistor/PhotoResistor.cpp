#include "Photoresistor.h"


Photoresistor::Photoresistor(int sensor_pin, int led_pin, int dark_limit) {
  _sensor_pin = sensor_pin;
  _led_pin = led_pin;
  _dark_limit = dark_limit;
}

void Photoresistor::photoresistor_init() {
  pinMode(_sensor_pin, INPUT);
  pinMode(_led_pin, OUTPUT);
  digitalWrite(_led_pin, LOW);
}

int Photoresistor::photoresistor_read_raw() {
  return analogRead(_sensor_pin);
}

bool Photoresistor::photoresistor_is_dark() {
  int raw_value = photoresistor_read_raw();
  
  if (raw_value < _dark_limit) {
    digitalWrite(_led_pin, HIGH);
    return true;
  } else {
    digitalWrite(_led_pin, LOW);
    return false;
  }
}