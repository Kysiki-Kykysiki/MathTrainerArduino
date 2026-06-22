#include <CodeLock.h>
#include <string.h>

CodeLock::CodeLock(const char* pinCode, int attempts) {
    // копируем PIN в буфер фиксированного размера (без динамической памяти)
    strncpy(pin, pinCode, MAX_LEN);
    pin[MAX_LEN] = '\0';

    maxAttempts = (attempts > 0) ? attempts : 1;
    reset();
}

void CodeLock::reset() {
    failedAttempts = 0;
    unlocked = false;
    lockedOut = false;
    clearEntry();
}

void CodeLock::clearEntry() {
    entryLen = 0;
    entry[0] = '\0';
}

void CodeLock::pressKey(char key) {
    // если замок заблокирован — игнорируем всё, пока не сделают reset()
    if (lockedOut) return;

    if (key >= '0' && key <= '9') {
        if (entryLen < MAX_LEN) {        // лишние цифры не переполняют буфер
            entry[entryLen++] = key;
            entry[entryLen] = '\0';
        }
    } else if (key == '*') {
        clearEntry();                    // стереть набор
    } else if (key == '#') {
        submit();                        // подтвердить
    }
    // прочие символы игнорируются
}

void CodeLock::submit() {
    if (strcmp(entry, pin) == 0) {
        unlocked = true;
        failedAttempts = 0;              // успех сбрасывает счётчик ошибок
    } else {
        unlocked = false;
        failedAttempts++;
        if (failedAttempts >= maxAttempts) {
            lockedOut = true;            // лимит исчерпан — блокировка
        }
    }
    clearEntry();                        // после проверки набор всегда чистый
}

bool CodeLock::isUnlocked() const { return unlocked; }
bool CodeLock::isLockedOut() const { return lockedOut; }
int  CodeLock::getFailedAttempts() const { return failedAttempts; }
const char* CodeLock::currentEntry() const { return entry; }
