#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "QuestionGen.h"

class Display {
public:
    Display(byte address, byte cols, byte rows);

    void begin();
    void showWelcome();
    void showResult(bool correct, int correctAnswer, int score);
    void showInput(const String& input);
    void showQuestion(const Question& q);
    
private:
    LiquidCrystal_I2C lcd;
    byte cols;
    byte rows;

}