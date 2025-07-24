//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

char* sanitizeInput(char*);

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Please enter your name: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    printf("Sanitized input: %s\n", sanitizeInput(input));
    return 0;
}

/* Sanitizes user input */
char* sanitizeInput(char* input) {
    /* Allocate memory for sanitized input */
    char* sanitized = (char*) malloc(MAX_INPUT_LENGTH);
    int numChars = 0;

    /* Loop through each character of input */
    for (int i = 0; input[i] != '\0' && i < MAX_INPUT_LENGTH; i++) {
        /* Ignore non-alphabetic characters */
        if (isalpha(input[i])) {
            /* Convert to lowercase and add to sanitized input */
            sanitized[numChars++] = tolower(input[i]);
        }
    }

    /* Add null terminator to sanitized input */
    sanitized[numChars] = '\0';

    return sanitized;
}