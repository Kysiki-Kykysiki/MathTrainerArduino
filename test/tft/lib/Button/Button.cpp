#include <Button.h>


Button::Button(){
    pin = 2;
    pinMode(pin, INPUT);
}
Button::Button(int p) {
    pin = p;
    pinMode(pin, INPUT);
}

void Button::update(){
    bool currentState = digitalRead(pin) == LOW;

    press = false;
    if(currentState && !lastState){
        press = true;
        pressCount += 1;
    }
    lastState = currentState;
}

bool Button::wasPressed(){
    return press;
}

void Button::resetCount(){
    pressCount = 0;

}

int Button::get_pressCount(){
    return pressCount;
}