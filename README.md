# MathTrainerArduino + Smart alarm

```
MathTrainerArduino/
├─ README.md        # обзор проекта
├─ lib/
│  ├─ Buzzer/ # пищалка
│  │      ├─ Buzzer.h    # заголовочный файл пищалки
│  │      └─ Buzzer.cpp  # исходный файл пищалки
│  └─ Led/    # светодиод
│       ├─ Led.h    # заголовочный файл светодиода
│       └─ Led.cpp  # исходный файл светодиода
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

## Реализация
После запуска проекта, программа отсчитывает 5 секунд, которые выводятся на LCD. После истечения 5 секунд звенит будильник(пищалка+светодиод). Для отключения будильника пользователю нужно решить 5 примеров.

**Buzzer.cpp**
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

```