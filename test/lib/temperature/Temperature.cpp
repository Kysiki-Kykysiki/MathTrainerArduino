#include "Temperature.h"


Temperature::Temperature(int sensor_pin, int led_pin, float threshold_temp) 
  : sensor_pin(sensor_pin), led_pin(led_pin), threshold(threshold_temp) 
{
  
}

void Temperature::temperature_init() {
  pinMode(sensor_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin, LOW); 
}

float Temperature::temperature_read_celsius() {
  int analogValue = analogRead(sensor_pin);
 
  if (analogValue <= 0) analogValue = 1;
  if (analogValue >= 1023) analogValue = 1022;

  // Расчет температуры по формуле Стейнхарта-Харта
  float celsius = 1.0 / (log(1.0 / (1023.0 / analogValue - 1.0)) / BETA + 1.0 / 298.15) - 273.15;
  return celsius;
}

bool Temperature::temperature_is_hot() {
  float current_temp = temperature_read_celsius();
  
  if (current_temp > threshold) {
    digitalWrite(led_pin, HIGH); 
    return true;
  } else {
    digitalWrite(led_pin, LOW);
    return false;
  }
}