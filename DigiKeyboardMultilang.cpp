#include "Arduino.h"
#include "DigiKeyboardMultilang.h"
#include "DigiKeyboard.h"

DigiKeyboardMultilang::DigiKeyboardMultilang(const uint16_t* language) {
    this->setLanguage(language);
}

void DigiKeyboardMultilang::print(const char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        // Check if character isn't printable
        if (str[i] - 32 < 0) {
            DigiKeyboard.sendKeyStroke(str[i]);
        } else {
            uint16_t code = pgm_read_word_near(_lang + str[i] - 32);
            DigiKeyboard.sendKeyStroke((char)(code & 0xFF), code >> 8);
        }
    }
}

void DigiKeyboardMultilang::println(const char str[]) {
    this->print(str);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void DigiKeyboardMultilang::delay(long milli) {
    DigiKeyboard.delay(milli);
}

void DigiKeyboardMultilang::sendKeyPress(byte keyPress) {
    DigiKeyboard.sendKeyPress(keyPress);
}

void DigiKeyboardMultilang::sendKeyPress(byte keyPress, byte modifiers) {
    DigiKeyboard.sendKeyPress(keyPress, modifiers);
}

void DigiKeyboardMultilang::sendKeyStroke(byte keyStroke) {
    DigiKeyboard.sendKeyStroke(keyStroke);
}

void DigiKeyboardMultilang::sendKeyStroke(byte keyStroke, byte modifiers) {
    DigiKeyboard.sendKeyStroke(keyStroke, modifiers);
}

void DigiKeyboardMultilang::setLanguage(const uint16_t* language) {
    _lang = language;
}