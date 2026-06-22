// ПРИМЕР интеграции CodeLock с реальным железом (Keypad + LCD + светодиоды).
//
// Это НЕ тест и не часть сборки проекта — справочный скетч для урока.
// Чтобы запустить на плате: скопировать содержимое в src/main.cpp проекта
// с подключёнными библиотеками Keypad и LiquidCrystal_I2C (env:uno).
//
// Обратите внимание: вся "умная" логика — в CodeLock (её мы тестируем),
// а здесь только чтение клавиатуры и вывод на экран/светодиоды.

#include <Arduino.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <CodeLock.h>

const byte ROWS = 4, COLS = 4;
char keys[ROWS][COLS] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int GREEN_LED = 10;
const int RED_LED   = 11;

CodeLock lock("1234", 3);   // PIN 1234, блокировка после 3 ошибок

void render() {
    lcd.clear();
    if (lock.isLockedOut()) {
        lcd.print("ZABLOKIROVANO");
        digitalWrite(RED_LED, HIGH);
        digitalWrite(GREEN_LED, LOW);
    } else if (lock.isUnlocked()) {
        lcd.print("OTKRYTO");
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(RED_LED, LOW);
    } else {
        lcd.print("Vvedite kod:");
        lcd.setCursor(0, 1);
        lcd.print(lock.currentEntry());
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(RED_LED, LOW);
    }
}

void setup() {
    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    lcd.init();
    lcd.backlight();
    render();
}

void loop() {
    char key = keypad.getKey();
    if (key) {
        lock.pressKey(key);   // вся логика — здесь, внутри CodeLock
        render();
    }
}
