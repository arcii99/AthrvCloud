//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * charToMorse(char letter) { // converts character to corresponding Morse code symbol

    switch(letter) {
        case 'a':
            return ".- ";
        case 'b':
            return "-... ";
        case 'c':
            return "-.-. ";
        case 'd':
            return "-.. ";
        case 'e':
            return ". ";
        case 'f':
            return "..-. ";
        case 'g':
            return "--. ";
        case 'h':
            return ".... ";
        case 'i':
            return ".. ";
        case 'j':
            return ".--- ";
        case 'k':
            return "-.- ";
        case 'l':
            return ".-.. ";
        case 'm':
            return "-- ";
        case 'n':
            return "-. ";
        case 'o':
            return "--- ";
        case 'p':
            return ".--. ";
        case 'q':
            return "--.- ";
        case 'r':
            return ".-. ";
        case 's':
            return "... ";
        case 't':
            return "- ";
        case 'u':
            return "..- ";
        case 'v':
            return "...- ";
        case 'w':
            return ".-- ";
        case 'x':
            return "-..- ";
        case 'y':
            return "-.-- ";
        case 'z':
            return "--.. ";
        case ' ':
            return "/ "; // Morse code for space
        default:
            return ""; // in case the character isn't a letter or space, return blank
    }
}

void convertToMorse(char *input) { // function to convert text to Morse code
    int length = strlen(input);
    char morseCode[length*4]; // length of Morse code string should be 4 times longer than the input string (each letter could be up to 4 symbols)
    memset(morseCode, 0, sizeof(morseCode)); // initialize Morse code string to empty

    for (int i = 0; i < length; i++) { // loop through each character in the input string
        char *morseSymbol = charToMorse(input[i]); // get the Morse code symbol for the current character
        strcat(morseCode, morseSymbol); // append the Morse code symbol to the Morse code string
    }

    printf("Your text in Morse code is: %s\n", morseCode);
}

int main() {
    char input[100];

    printf("Enter text to convert to Morse code: ");
    fgets(input, 100, stdin);
    strtok(input, "\n"); // remove the newline character at the end of input from fgets

    convertToMorse(input);

    return 0;
}