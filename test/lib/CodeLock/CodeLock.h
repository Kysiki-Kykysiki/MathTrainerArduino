#pragma once
#include <Arduino.h>


class CodeLock {
public:
    static const byte MAX_LEN = 8;
    
    CodeLock(const char* pin, int maxAttempts = 3);

    void pressKey(char key);     // обработать нажатие одной клавиши
    void reset();                // полный сброс: закрыть, снять блокировку, обнулить ошибки

    bool isUnlocked() const;     // замок открыт?
    bool isLockedOut() const;    // замок заблокирован из-за лимита ошибок?
    int  getFailedAttempts() const;
    const char* currentEntry() const; // что сейчас набрано (для показа на LCD)

private:
    char pin[MAX_LEN + 1];
    char entry[MAX_LEN + 1];
    byte entryLen;
    int  maxAttempts;
    int  failedAttempts;
    bool unlocked;
    bool lockedOut;

    void clearEntry();
    void submit();
};
