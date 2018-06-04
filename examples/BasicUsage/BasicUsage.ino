#include <DigiKeyboardMultilang.h>

// Keyboard constructor where you pass the language
// You can find all implemented languages at /languages/languages.h
DigiKeyboardMultilang keyboard(lang_us);

void setup() {
    // We don't need to do anything inhere
}

void loop() {
    keyboard.println("Hello world! :)");

    // Use keyboard delay function for better stability
    keyboard.delay(5000);
}