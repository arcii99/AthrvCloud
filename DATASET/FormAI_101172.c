//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: energetic
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100 // max length of input text
#define DOT_LENGTH 250 // length of a dot in milliseconds 
#define DASH_LENGTH 750 // length of a dash in milliseconds 
#define SPACE_LENGTH 1000 // length of space between letters in milliseconds 
#define WORD_SPACE_LENGTH 3000 // length of space between words in milliseconds

// function to convert a single character to Morse code
void charToMorse(char c) {
    switch (c) {
        case 'a':
        case 'A':
            printf(".- ");
            break;
        case 'b':
        case 'B':
            printf("-... ");
            break;
        // add more cases for other characters...
        default:
            break;
    }
}

// function to convert the input text to Morse code
void textToMorse(char text[MAX_LENGTH]) {
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        charToMorse(text[i]);
        if (text[i] != ' ') {
            printf(" ");
        }
        // space between letters
        usleep(SPACE_LENGTH * 1000); // usleep() is used to pause execution for a given number of microseconds
    }
    // space between words
    usleep(WORD_SPACE_LENGTH * 1000);
}

int main() {
    char text[MAX_LENGTH];
    
    printf("Welcome to the Morse code generator! Enter your text: ");
    fgets(text, MAX_LENGTH, stdin);
    
    printf("\nConverting text to Morse code...\n\n");
    textToMorse(text);
    
    return 0;
}