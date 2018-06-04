#include <DigiKeyboardMultilang.h>

// Keyboard constructor where you pass the language
// You can find all implemented languages at /languages/languages.h
DigiKeyboardMultilang keyboard(lang_us);

void setup() {
    // Set another language if pin 0 is high
    if (digitalRead(0)) {
        keyboard.setLanguage(lang_cs);
    }
    
    keyboard.write("Everything works, even special characters like !@#$%^&* :)");
}

void loop() {
    // We don't need that in this example
}