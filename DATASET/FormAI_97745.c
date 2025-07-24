//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: multivariable
#include <stdio.h>
#include <string.h>

// Function for converting characters to Morse code
char *convertToMorse(char letter) {

    char *morseCode;

    switch (letter) {
        case 'a': morseCode = ".- "; break;
        case 'b': morseCode = "-... "; break;
        case 'c': morseCode = "-.-. "; break;
        case 'd': morseCode = "-.. "; break;
        case 'e': morseCode = ". "; break;
        case 'f': morseCode = "..-. "; break;
        case 'g': morseCode = "--. "; break;
        case 'h': morseCode = ".... "; break;
        case 'i': morseCode = ".. "; break;
        case 'j': morseCode = ".--- "; break;
        case 'k': morseCode = "-.- "; break;
        case 'l': morseCode = ".-.. "; break;
        case 'm': morseCode = "-- "; break;
        case 'n': morseCode = "-. "; break;
        case 'o': morseCode = "--- "; break;
        case 'p': morseCode = ".--. "; break;
        case 'q': morseCode = "--.- "; break;
        case 'r': morseCode = ".-. "; break;
        case 's': morseCode = "... "; break;
        case 't': morseCode = "- "; break;
        case 'u': morseCode = "..- "; break;
        case 'v': morseCode = "...- "; break;
        case 'w': morseCode = ".-- "; break;
        case 'x': morseCode = "-..- "; break;
        case 'y': morseCode = "-.-- "; break;
        case 'z': morseCode = "--.. "; break;
        case '0': morseCode = "----- "; break;
        case '1': morseCode = ".---- "; break;
        case '2': morseCode = "..--- "; break;
        case '3': morseCode = "...-- "; break;
        case '4': morseCode = "....- "; break;
        case '5': morseCode = "..... "; break;
        case '6': morseCode = "-.... "; break;
        case '7': morseCode = "--... "; break;
        case '8': morseCode = "---.. "; break;
        case '9': morseCode = "----. "; break;
        case ' ': morseCode = "  "; break;
        default: morseCode = ""; break;
    }

    return morseCode;
}

// Function for getting user input
char *getUserInput() {
    char input[100];
    char *userInput = (char *) malloc(sizeof(char) * 100);

    printf("Enter the text you want to convert to Morse code: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;
    strcpy(userInput, input);

    return userInput;
}

// Function for converting user input to Morse code
char *convertTextToMorseCode(char *text) {
    char *morseCode = (char *) malloc(sizeof(char) * 1000);

    for (int i = 0; i < strlen(text); i++) {
        char letter = tolower(text[i]);

        strcat(morseCode, convertToMorse(letter));
    }

    return morseCode;
}

int main() {
    char *userInput = getUserInput();
    char *morseCode = convertTextToMorseCode(userInput);

    printf("Morse code: %s\n", morseCode);

    free(userInput);
    free(morseCode);

    return 0;
}