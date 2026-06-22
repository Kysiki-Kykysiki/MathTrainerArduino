#pragma once
#include <Arduino.h>
#include <Keypad.h>

enum class InputEvent {NONE, DIGIT, CLEAR, SUBMIT};

class InputHandler {
public:
    InputHandler();

    InputEvent poll();
    const String& value() const;
    void clear();
private:
    static const byte ROWS = 4;
    static const byte COLS = 4;
    static const byte MAX_LEN = 4;  
    
    char keys[ROWS][COLS];
    byte rowPins[ROWS];             
    byte colPins[COLS];
    Keypad keypad;
    String buffer;
};