#include <Arduino.h>

class LedDisplay {
private:
    int* ledPins;
    int ledCount;
    int currentLevel;
    bool isInicialize;

    bool isValidPin(int pin) const{
        return pin >= 2 && pin <= 13;
    }
    bool isValidLevel(int level) const{
        return level >= 0 && level <= ledCount;
    }

public:
    LedDisplay(int, int []);

    void init();

    bool setLevel(int);

    bool setLedCount(int);

    int getLevel() const;

    int getLedCount() const;

    void clear();

    void fillAll();

    void update();

    void printStatus() const;

};