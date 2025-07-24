//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

// Function to convert a character to its Morse code equivalent
char* toMorse(char c) {
    switch(tolower(c)) {
        case 'a': return ".-";
        case 'b': return "-...";
        case 'c': return "-.-.";
        case 'd': return "-..";
        case 'e': return ".";
        case 'f': return "..-.";
        case 'g': return "--.";
        case 'h': return "....";
        case 'i': return "..";
        case 'j': return ".---";
        case 'k': return "-.-";
        case 'l': return ".-..";
        case 'm': return "--";
        case 'n': return "-.";
        case 'o': return "---";
        case 'p': return ".--.";
        case 'q': return "--.-";
        case 'r': return ".-.";
        case 's': return "...";
        case 't': return "-";
        case 'u': return "..-";
        case 'v': return "...-";
        case 'w': return ".--";
        case 'x': return "-..-";
        case 'y': return "-.--";
        case 'z': return "--..";
        case '0': return "-----";
        case '1': return ".----";
        case '2': return "..---";
        case '3': return "...--";
        case '4': return "....-";
        case '5': return ".....";
        case '6': return "-....";
        case '7': return "--...";
        case '8': return "---..";
        case '9': return "----.";
        case ' ': return " ";
        default: return "";
    }
}

// Function to convert a string to its Morse code equivalent
char* stringToMorse(char* str) {
    static char buffer[256];
    buffer[0] = '\0';
    for(int i = 0; i < strlen(str); i++) {
        char* morseChar = toMorse(str[i]);
        strcat(buffer, morseChar);
        strcat(buffer, " ");
    }
    return buffer;
}

int main() {
    char inputString[256];
    printf("Enter a string: ");
    fgets(inputString, 256, stdin);
    char* morseString = stringToMorse(inputString);
    printf("Morse code: %s\n", morseString);
    return 0;
}