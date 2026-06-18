#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

const int LCD_COLS = 20;
const int LCD_ROWS = 4;

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

const unsigned long TIME_LIMIT_MC = 10000;

// глоб. переменные
int a,b,ope;
char op;
int correctAnswer;
int score = 0;
String userInput = "";
unsigned long questionStart = 0;
int lastBarBlocks = -1;

void newQuestion(){
    questionStart = millis();
    a = random(0,100);
    b = random(0,100);
    ope = random(0,1);
    if(ope == 0){
      op = '+';
      correctAnswer = a+b;
    }else if(ope == 1){
      op = '-';
      correctAnswer = a-b;
    }

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


void drawTimeBar(){
    unsigned long elps = millis() - questionStart;
    if (elps > TIME_LIMIT_MC) {elps = TIME_LIMIT_MC;digitalWrite(13, HIGH);}

    int blocks = LCD_COLS - (int)(elps * LCD_COLS / TIME_LIMIT_MC);
    if(blocks == lastBarBlocks) return;

    lcd.setCursor(0,3);
    for(int i = 0; i < LCD_COLS; i++){
        lcd.write(i < blocks ? (uint8_t)0xFF : ' ');
    }
}

void showResult(bool correct, bool timeout){
    
}

void setup() {
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(A1, OUTPUT);

    randomSeed(analogRead(A3));

    lcd.setCursor(0,0);
    lcd.print("Math TrainerV1.0");
    lcd.setCursor(0,1);
    lcd.print("Press any key...");

    while(keypad.getKey() == NO_KEY) {}

    newQuestion();

}

void loop() {
    drawTimeBar();
    char key = keypad.getKey();
    if (key == NO_KEY) return;

    if (key == 'A') {
        if(userInput.length() < 4) {
            userInput += "-";
            lcd.setCursor(7,1);
            lcd.print("     ");
            lcd.setCursor(7,1);
            lcd.print(userInput);
        }
    }

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
            digitalWrite(12, HIGH);
            analogWrite(A1, 1023);
        
        }else{
          score = 0;
            lcd.print("!Pravilno :( ");
            lcd.print(correctAnswer);
             digitalWrite(13, HIGH);
        }

        lcd.setCursor(0,1);
        lcd.print("Schet: ");
        lcd.print(score);

        delay(2000);
        newQuestion();
        digitalWrite(13, LOW);
        digitalWrite(12, LOW);
        analogWrite(A1, 0);
    }
    

}
