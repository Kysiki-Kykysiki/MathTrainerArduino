#include <Button.h>


Button::Button(){
    pin = 2;
    pinMode(pin, INPUT);
}
Button::Button(int p) {
    pin = p;
    pinMode(pin, INPUT);
}

bool Button::pressed(){
    if (digitalRead(pin)){
      delay(100);
      return true;
    }
    return false;
}

void Button::update(){
    bool currentState = digitalRead(pin) == LOW;

    press = false;
    if(currentState && !lastState){
        press = true;
        pressCount += 1;
    }
    lastState = currentState;
    delay(10);
}

void Button::resetCount(){
    pressCount = 0;

}

int Button::get_pressCount(){
    return pressCount;
}