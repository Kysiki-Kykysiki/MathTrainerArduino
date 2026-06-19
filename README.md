# MathTrainerArduino + Smart alarm

**Структура проекта**
```
MathTrainerArduino/
├─ README.md        # обзор проекта
├─ lib/
│  ├─ Buzzer/ # пищалка
│  │      ├─ Buzzer.h    # заголовочный файл пищалки
│  │      └─ Buzzer.cpp  # исходный файл пищалки
│  ├─ Led/    # светодиод
│  │     ├─ Led.h    # заголовочный файл светодиода
│  │     └─ Led.cpp  # исходный файл светодиода
│  ├─ QuestionGen/    
│  │        ├─ QuetionGen.h    
│  │        └─ QuetionGen.cpp 
│  ├─ Display/    
│  │        ├─ Display.h    
│  │        └─ Display.cpp 
│  └─ InputHandler/    
│        ├─ InputHandler.h    
│        └─ InputHandler.cpp 
│     
├─ src/
│   └─ main.cpp      # основной файл
│
└─ diagram.json      # схема подключения        
```

## Зависимости проекта

platform.ini
```ini
    [env:uno]
    platform = atmelavr
    board = uno
    framework = arduino
    lib_deps = 
        marcoschwartz/LiquidCrystal_I2C@^1.1.4
        chris--a/Keypad@^3.1.1
```

## Проект
Простой математический тренажёр, реализованный в VSCode, с использованием PlatformIO + Wokwi.

<!-- **Buzzer.cpp**
```C++
void on(){
    tone(pinBuzz, Hz, t);
}

void off(){
    tone(pinBuzz, Hz, t);
}

```

**Led.cpp**
```C++
void on(){
    blinking = false;
    digitalWrite(ledPin,HIGH);
}

void off(){
    blinking = false;
    digitalWrite(ledPin,LOW);
}

void blink(int inter){
    blinking = true;
    interval = inter;
}
void update(){
    if(!blinking) return;
    if(millis() - lastToggle >= (unsigned long)interval){
        lastToggle = millis();
        state = !state;
        digitalWrite(pin, state ? HIGH : LOW);
    }
}

``` -->

## Реализация

|Название|Путь|Описание|
|--------|----|--------|
|QuestionGen|```\lib\QuestionGen```|Модуль генерации вопросов|
|Display|```\lib\Display```|Модуль LCD I2C|
|InputHandler|```\lib\InputHandler```|Модуль ввода с Keypad 4x4|








