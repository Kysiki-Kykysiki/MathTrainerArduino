#include <LedDisplay.h>

LedDisplay::LedDisplay(int count, int pins[]) {
    ledCount = count; 
    currentLevel = 0; 
    isInicialize =
    false;
    
    ledPins = new int[ledCount];

    for (int i = 0; i < ledCount; i++){
        if(isValidPin(pins[i])) ledPins[i] = pins[i];
        else {
            Serial.print("Ошибка создания!");
            Serial.println(pins[i]);
            ledPins[i] = pins[i];
        }
    }
    // отладочная информация
}

void LedDisplay::init(){
    if(isInicialize){
        Serial.println("Inicialized!");
        return;
    }
    for (int i = 0; i < ledCount; i++){
        Serial.println(i);
        pinMode(ledPins[i], OUTPUT);
        digitalWrite(ledPins[i], LOW);
        Serial.println("LedDisplay inicialized");
        
    }
    isInicialize = true;
    currentLevel = 0;
    
}

bool LedDisplay::setLevel(int level){
    if(level < 0 || level > 100){
        Serial.println("Error Level");
        return false;
    }

    int ledCountToTurn = map(level, 0, 100, 0, ledCount);
    currentLevel = ledCountToTurn;

    update();

    return true;
}

bool LedDisplay::setLedCount(int count) {
    if(!isInicialize){
        Serial.println("Inicialized!");
        return false;
    }

    if(!isValidLevel(count)){
        return false;
    }

    currentLevel = count;
    update();

    return true;
}

int LedDisplay::getLevel() const{
    return currentLevel;
}

int LedDisplay::getLedCount() const{
    return ledCount;
}


void LedDisplay::clear(){
    for (int i = 0; i < ledCount; i++){
        digitalWrite(ledPins[i], LOW);
    }

    currentLevel = 0;
}

void LedDisplay::fillAll(){
    for (int i = 0; i < ledCount; i++){
        digitalWrite(ledPins[i], HIGH);
    }

    currentLevel = ledCount;
}

void LedDisplay::update(){
    for (int i = 0; i < ledCount; i++){
        if (i < currentLevel) digitalWrite(ledPins[i], HIGH);
        else digitalWrite(ledPins[i], LOW);
    }
}

