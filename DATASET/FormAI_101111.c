//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100 // Maximum length of input string
#define DOT '.'
#define DASH '-'

// Morse code data structure
struct MorseCode {
    char letter;
    char code[50];
};

// Array of Morse code data
struct MorseCode data[] = {
    {'A', ".-"},
    {'B', "-..."},
    {'C', "-.-."},
    {'D', "-.."},
    {'E', "."},
    {'F', "..-."},
    {'G', "--."},
    {'H', "...."},
    {'I', ".."},
    {'J', ".---"},
    {'K', "-.-"},
    {'L', ".-.."},
    {'M', "--"},
    {'N', "-."},
    {'O', "---"},
    {'P', ".--."},
    {'Q', "--.-"},
    {'R', ".-."},
    {'S', "..."},
    {'T', "-"},
    {'U', "..-"},
    {'V', "...-"},
    {'W', ".--"},
    {'X', "-..-"},
    {'Y', "-.--"},
    {'Z', "--.."},
    {'0', "-----"},
    {'1', ".----"},
    {'2', "..---"},
    {'3', "...--"},
    {'4', "....-"},
    {'5', "....."},
    {'6', "-...."},
    {'7', "--..."},
    {'8', "---.."},
    {'9', "----."},
    {' ', "/"}, // Space
};

// Function to convert a single character into Morse code
void convertToMorse(char ch) {
    int found = 0;
    int i;
    for (i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        if (toupper(ch) == data[i].letter) {
            found = 1;
            printf("%s ", data[i].code);
            break;
        }
    }
    if (!found) {
        printf("# ");
    }
}

// Function to convert a string of text into Morse code
void textToMorse(char *text) {
    int len = strlen(text);
    int i;
    for (i = 0; i < len; i++) {
        convertToMorse(text[i]);
    }
}

// Function to convert Morse code into a single character
char convertToChar(char *code) {
    int found = 0;
    int i;
    for (i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        if (strcmp(code, data[i].code) == 0) {
            found = 1;
            return data[i].letter;
        }
    }
    if (!found) {
        return '#';
    }
    return 0;
}

// Function to convert Morse code into a string of text
void morseToText(char *morse) {
    int len = strlen(morse);
    char code[50];
    int codeIndex = 0;
    int i;
    for (i = 0; i < len; i++) {
        if (morse[i] == DOT || morse[i] == DASH) {
            code[codeIndex++] = morse[i];
        } else if (morse[i] == ' ') {
            code[codeIndex] = '\0';
            printf("%c", convertToChar(code));
            codeIndex = 0;
        }
    }
    code[codeIndex] = '\0';
    printf("%c", convertToChar(code));
}

int main() {
    char input[MAX_LENGTH];
    int choice;
    printf("Enter 1 to convert text to Morse code or 2 to convert Morse code to text: ");
    scanf("%d", &choice);
    getchar(); // Clear input buffer
    if (choice == 1) {
        printf("Enter text to convert to Morse code: ");
        fgets(input, MAX_LENGTH, stdin);
        printf("Morse code: ");
        textToMorse(input);
    } else if (choice == 2) {
        printf("Enter Morse code to convert to text: ");
        fgets(input, MAX_LENGTH, stdin);
        printf("Text: ");
        morseToText(input);
    } else {
        printf("Invalid choice");
    }
    printf("\n");
    return 0;
}