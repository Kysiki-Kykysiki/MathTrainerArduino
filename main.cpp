#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include "Led.h"
#include "Buzzer.h"

const int LCD_COLS = 16;
const int LCD_ROWS = 2;

const int LED_PIN = 13;
const int BUZZ_PIN = 8;

const int TIMER_ALARM = 5;
const int countQuestion = 3;


LiquidCrystal_I2C lcd(0x27, LCD_COLS, LCD_ROWS);

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

byte colPins[COLS] = { 5, 4, 3, 2 }; // Pins connected to C1, C2, C3, C4
byte rowPins[ROWS] = { 9, 8, 7, 6 }; // Pins connected to R1, R2, R3, R4

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
Led led(LED_PIN);
Buzzer buzz(BUZZ_PIN);

// глоб. переменные
int a,b;
char op;
int correctAnswer;
int score = 0;
String userInput = "";
int startTime;

void newQuestion(){
    a = random(2,10);
    b = random(2,10);
    op = '+';
    correctAnswer = a+b;

    userInput = "";

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(a);
    lcd.print(" ");
    lcd.print(op);
    lcd.print(" ");
    lcd.print(b);
    lcd.print(" = ?");

    lcd.setCursor(0,1);
    lcd.print("Otvet: ");
}

void setup() {
    startTime = millis();
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();

    randomSeed(analogRead(A3));

    lcd.setCursor(0,0);
    lcd.print("Math TrainerV1.0");
    lcd.setCursor(0,1);
    lcd.print("Press any key...");

    while(keypad.getKey() == NO_KEY) {}

    newQuestion();
}

void loop() {
    if((millis() - startTime) > TIMER_ALARM){
        if(score < countQuestion){
            buzz.on();
            led.blink(100);
        }
        else{
            buzz.off();
            led.off();
        }
        char key = keypad.getKey();
        if (key == NO_KEY) return;

        if (key >= '0' && key <= '9') {
            if(userInput.length() < 4) {
                userInput += key;
                lcd.setCursor(7,1);
                lcd.print("     ");
                lcd.setCursor(7,1);
                lcd.print(userInput);
            }
        }

        else if(key == '*'){
            userInput = "";
            lcd.setCursor(7,1);
            lcd.print("          ");
        }
        else if(key == '#') {
            if(userInput.length() == 0) return;
            int answer = userInput.toInt();

            lcd.clear();
            lcd.setCursor(0,0);
            if (answer == correctAnswer){
                score++;
                lcd.print("Pravilno :)");
            }
            else {
                score = 0;
                lcd.print("!Pravilno :( ");
                lcd.print(correctAnswer);
            }

            lcd.setCursor(0,1);
            lcd.print("Schet: ");
            lcd.print(score);

            delay(2000);
            newQuestion();
        }
    }
}