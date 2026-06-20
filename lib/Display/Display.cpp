#include "Display.h"

Display::Display(byte address, byte c, byte r): lcd(address, c,r), cols(c), rows(r){}
void Display::begin(){
    lcd.init();
    lcd.backlight();    
}
void Display::showWelcome(){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Math TrainerV1.0");
    lcd.setCursor(0, 1);
    lcd.print("Press any key...");
}
void Display::showResult(bool correct, int correctAnswer, int score){
    lcd.clear();
    lcd.setCursor(0, 0);
    if (correct) {
        lcd.print("Pravilno :)");
    } else {
        lcd.print("!Pravilno :( ");
        lcd.print(correctAnswer);
    }
    
    lcd.setCursor(0, 1);
    lcd.print("Schet: ");
    lcd.print(score);
}
void Display::showInput(const String& input){
    lcd.setCursor(7, 1);
    lcd.print("         "); 
    lcd.setCursor(7, 1);
    lcd.print(input);
}
void Display::showQuestion(const Question& q){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(q.a);
    lcd.print(" ");
    lcd.print(q.op);
    lcd.print(" ");
    lcd.print(q.b);
    lcd.print(" = ?");

    lcd.setCursor(0, 1);
    lcd.print("Otvet: ");
}
