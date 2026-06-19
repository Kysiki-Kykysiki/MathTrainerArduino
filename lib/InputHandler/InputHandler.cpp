#include "InputHandler.h"

InputHandler::InputHandler() : 
    keys{
          { '1', '2', '3', 'A' },
          { '4', '5', '6', 'B' },
          { '7', '8', '9', 'C' },
          { '*', '0', '#', 'D' }
      },
      rowPins{ 9, 8, 7, 6 },
      colPins{ 5, 4, 3, 2 },
      keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS),
      buffer("") {}

InputEvent InputHandler::poll(){
    char key = keypad.getKey();
    if (key == NO_KEY) return InputEvent::NONE;

    if (key >= '0' && key <= '9') {
        if(buffer.length() < MAX_LEN) {
            buffer += key;
        }
        return InputEvent::DIGIT;
    }
    else if(key == '*'){
        buffer = "";
        return InputEvent::CLEAR;
    }
    else if(key == '#') {
        return InputEvent::SUBMIT;
    }
    return InputEvent::NONE;
}

void InputHandler::clear(){
    buffer = "";
}

const String& InputHandler::value() const {
    return buffer;
}
