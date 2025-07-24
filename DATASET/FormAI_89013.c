//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert character to Morse code
char* charToMorse(char c) {
    char *morseCode;

    switch (c) {
        case 'a':
            morseCode = ".-";
            break;
        case 'b':
            morseCode = "-...";
            break;
        case 'c':
            morseCode = "-.-.";
            break;
        case 'd':
            morseCode = "-..";
            break;
        case 'e':
            morseCode = ".";
            break;
        case 'f':
            morseCode = "..-.";
            break;
        case 'g':
            morseCode = "--.";
            break;
        case 'h':
            morseCode = "....";
            break;
        case 'i':
            morseCode = "..";
            break;
        case 'j':
            morseCode = ".---";
            break;
        case 'k':
            morseCode = "-.-";
            break;
        case 'l':
            morseCode = ".-..";
            break;
        case 'm':
            morseCode = "--";
            break;
        case 'n':
            morseCode = "-.";
            break;
        case 'o':
            morseCode = "---";
            break;
        case 'p':
            morseCode = ".--.";
            break;
        case 'q':
            morseCode = "--.-";
            break;
        case 'r':
            morseCode = ".-.";
            break;
        case 's':
            morseCode = "...";
            break;
        case 't':
            morseCode = "-";
            break;
        case 'u':
            morseCode = "..-";
            break;
        case 'v':
            morseCode = "...-";
            break;
        case 'w':
            morseCode = ".--";
            break;
        case 'x':
            morseCode = "-..-";
            break;
        case 'y':
            morseCode = "-.--";
            break;
        case 'z':
            morseCode = "--..";
            break;
        case ' ':
            morseCode = "/";
            break;
        default:
            morseCode = "";
    }

    return morseCode;
}

int main() {
    char text[100];
    char morseCode[1000] = "";
  
    printf("Enter text to convert to Morse code: ");
    gets(text);
  
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        strcat(morseCode, charToMorse(tolower(text[i])));
        strcat(morseCode, " ");
    }
  
    printf("The Morse code for the text \"%s\" is: %s", text, morseCode);
  
    return 0;
}