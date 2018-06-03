#ifndef DIGIKEYBOARDMULTILANG_H
#define DIGIKEYBOARDMULTILANG_H

#include "Arduino.h"
#include "languages/languages.h"

class DigiKeyboardMultilang {
    public:
        DigiKeyboardMultilang(const uint16_t* language);
        void print(const char str[]);
        void println(const char str[]);
        void delay(long milli);
        void sendKeyPress(byte keyPress);
        void sendKeyPress(byte keyPress, byte modifiers);
        void sendKeyStroke(byte keyStroke);
        void sendKeyStroke(byte keyStroke, byte modifiers);
        void setLanguage(const uint16_t* language);
    private:
        const uint16_t* _lang;
};

#endif