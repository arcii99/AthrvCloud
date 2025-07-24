//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256

// Configurable settings
#define ALLOW_LETTERS 1
#define ALLOW_NUMBERS 1
#define ALLOW_SPECIAL_CHARS 1

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter some input: ");

    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Loop through each character in the input and sanitize it
    for(int i = 0; i < strlen(input); i++) {
        if(isalpha(input[i])) {
            // If letters are allowed, keep the character
            if(ALLOW_LETTERS) {
                continue;
            }
            // If letters are not allowed, replace with a space
            else {
                input[i] = ' ';
            }
        }
        else if(isdigit(input[i])) {
            // If numbers are allowed, keep the character
            if(ALLOW_NUMBERS) {
                continue;
            }
            // If numbers are not allowed, replace with a space
            else {
                input[i] = ' ';
            }
        }
        else {
            // If special characters are allowed, keep the character
            if(ALLOW_SPECIAL_CHARS) {
                continue;
            }
            // If special characters are not allowed, replace with a space
            else {
                input[i] = ' ';
            }
        }
    }

    printf("Sanitized input: %s\n", input);

    return 0;
}