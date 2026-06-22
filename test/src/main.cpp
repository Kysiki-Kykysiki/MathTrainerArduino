#include <Arduino.h>
#include "QuestionGen.h"
#include "Display.h"
#include "InputHandler.h"

// #define LCD_ADDR 0x27


const byte LCD_ADDR = 0x27;
const byte LCD_COLS = 16;
const byte LCD_ROWS = 2;

Display display(LCD_ADDR, LCD_COLS, LCD_ROWS);
InputHandler input;
QuestionGen generator;

Question current;
int score = 0;


void newQuestion(){
    current = generator.next();
    input.clear();
    display.showQuestion(current);
}

void setup() {
    Serial.begin(9600);
    randomSeed(analogRead(A3));

    display.begin();
    display.showWelcome();

    while (input.poll() == InputEvent::NONE){}

    newQuestion();
    
}

void loop() {
    InputEvent ev = input.poll();

    if (ev == InputEvent::DIGIT || ev == InputEvent::CLEAR) {
        display.showInput(input.value());
    }
    else if (ev == InputEvent::SUBMIT) {
        if (input.value().length() == 0) return;

        int answer = input.value().toInt();
        bool correct = (answer == current.answer);

        if (correct) {
            score++;
        } else {
            score = 0;   
        }
        display.showResult(correct, current.answer, score);
        delay(2000);
        newQuestion();
    }
}