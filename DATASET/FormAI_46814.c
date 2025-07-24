//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

/* Morse code mapping */
const char *morseTable[26] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", 
    ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

/* Function to convert a character to morse code */
void charToMorse(char c, char* morse) {
    int index = (int)tolower(c) - (int)'a';
    if (index < 0 || index > 25) {
        /* Character not in range a-z, ignore */
        morse[0] = '\0';
        return;
    }
    strcpy(morse, morseTable[index]);
}

/* Function to convert a string to morse code */
void stringToMorse(char* input, char* output) {
    int length = strlen(input);
    char morse[MAX_STRING_LENGTH];
    output[0] = '\0'; /* clear output string */

    for (int i = 0; i < length; i++) {
        charToMorse(input[i], morse); /* get morse code for character */
        strcat(output, morse); /* append morse code to output string */
        strcat(output, " "); /* add space between characters */
    }
}

int main() {
    char input[MAX_STRING_LENGTH];
    char output[MAX_STRING_LENGTH];

    /* Get input string from user */
    printf("Enter text to convert to morse code: ");
    fgets(input, MAX_STRING_LENGTH, stdin);
    /* Remove newline character from input (added by fgets) */
    input[strcspn(input, "\n")] = '\0';

    stringToMorse(input, output);

    /* Print morse code to console */
    printf("%s\n", output);

    return 0;
}