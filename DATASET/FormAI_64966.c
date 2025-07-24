//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: light-weight
#include <stdio.h>
#include <string.h>

#define MAX_TEXT_LENGTH 100
#define MAX_MORSE_LENGTH 500

char* morseCode(char c) {
    switch (c) {
        case 'a':
            return ".-";
        case 'b':
            return "-...";
        case 'c':
            return "-.-.";
        case 'd':
            return "-..";
        case 'e':
            return ".";
        case 'f':
            return "..-.";
        case 'g':
            return "--.";
        case 'h':
            return "....";
        case 'i':
            return "..";
        case 'j':
            return ".---";
        case 'k':
            return "-.-";
        case 'l':
            return ".-..";
        case 'm':
            return "--";
        case 'n':
            return "-.";
        case 'o':
            return "---";
        case 'p':
            return ".--.";
        case 'q':
            return "--.-";
        case 'r':
            return ".-.";
        case 's':
            return "...";
        case 't':
            return "-";
        case 'u':
            return "..-";
        case 'v':
            return "...-";
        case 'w':
            return ".--";
        case 'x':
            return "-..-";
        case 'y':
            return "-.--";
        case 'z':
            return "--..";
        case ' ':
            return "/";
        default:
            return "";
    }
}

void textToMorse(char text[], char* morse[]) {
    for (int i = 0; i < strlen(text); i++) {
        char c = tolower(text[i]);
        char* code = morseCode(c);
        strcat(morse, code);
        strcat(morse, " ");
    }
}

int main() {
    char text[MAX_TEXT_LENGTH];
    printf("Enter text: ");
    scanf("%[^\n]", text);
    char morse[MAX_MORSE_LENGTH] = "";
    textToMorse(text, &morse);
    printf("Morse code: %s\n", morse);
    return 0;
}