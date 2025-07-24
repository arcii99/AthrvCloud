//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: all-encompassing
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100 // maximum input message length

// Morse code table
const char *TABLE_MORSE[26] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", 
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", 
    "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// function to convert a character to Morse code
char* charToMorse(char c) {
    c = toupper(c); // convert to uppercase
    if (c < 'A' || c > 'Z') {
        return ""; // return empty string for non-alphabetic chars
    }
    return TABLE_MORSE[c - 'A'];
}

// function to convert a message to Morse code
char* convertToMorse(char *message) {
    static char morse[MAX_LENGTH*5]; // Morse code length <= 5 times input length
    morse[0] = '\0';
    for (int i = 0; i < strlen(message); i++) {
        char *morseChar = charToMorse(message[i]);
        strcat(morse, morseChar);
        if (i < strlen(message) - 1) {
            strcat(morse, " "); // add space between Morse characters
        }
    }
    return morse;
}

int main() {
    char input[MAX_LENGTH+1]; // input message
    printf("Enter a message to convert to Morse code: ");
    fgets(input, MAX_LENGTH+1, stdin); // read input message
    if (input[strlen(input)-1] == '\n') {
        input[strlen(input)-1] = '\0'; // remove newline character
    }
    char *morseCode = convertToMorse(input);
    printf("Morse code: %s\n", morseCode);
    return 0;
}