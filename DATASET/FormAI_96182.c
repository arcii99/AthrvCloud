//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

// This function trims leading and trailing spaces from a string
char *trimString(char *inputString) {
    char *end;

    // Trim leading spaces
    while (isspace((unsigned char)*inputString)) {
        inputString++;
    }

    // If all spaces are trimmed
    if (*inputString == '\0') {
        return inputString;
    }

    // Trim trailing spaces
    end = inputString + strlen(inputString) - 1;
    while (end > inputString && isspace((unsigned char)*end)) {
        end--;
    }

    // Null terminate the trimmed string
    *(end+1) = '\0';

    return inputString;
}

// This function converts all letters to lowercase
char *toLowerCase(char *inputString) {
    int i = 0;

    while (inputString[i]) {
        inputString[i] = tolower(inputString[i]);
        i++;
    }

    return inputString;
}

// This function checks if a string contains only digits
int isNumeric(const char *inputString) {
    while (*inputString) {
        if (!isdigit(*inputString)) {
            return 0;
        }
        inputString++;
    }
    return 1;
}

// Main function that sanitizes user input
int main() {
    char userInput[MAX_INPUT_LENGTH];

    // Prompt user for input
    printf("Enter a string: ");
    fgets(userInput, MAX_INPUT_LENGTH, stdin);

    // Remove newline character
    userInput[strcspn(userInput, "\n")] = 0;

    // Trim leading and trailing spaces
    char *trimmedInput = trimString(userInput);

    // Convert all letters to lowercase
    char *lowercaseInput = toLowerCase(trimmedInput);

    // Check if input contains only digits
    if (isNumeric(lowercaseInput)) {
        printf("You entered a numeric string: %s\n", lowercaseInput);
    } else {
        printf("You entered a non-numeric string: %s\n", lowercaseInput);
    }

    return 0;
}