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

void DigiKeyboardMultilang::setLanguage(const uint16_t* language) {
    _lang = language;
}