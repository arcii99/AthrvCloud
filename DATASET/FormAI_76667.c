//FormAI DATASET v1.0 Category: Data validation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50

// Function to validate integer input
int validateIntegerInput(char* input) {
    int inputLength = strlen(input) - 1;
    int isDigit = 1;
    int i;

    // Check if each character is a digit
    for (i = 0; i < inputLength; i++) {
        if (!(isdigit(input[i]))) {
            isDigit = 0;
            break;
        }
    }

    if (isDigit) {
        return atoi(input);
    } else {
        printf("Invalid input. Please enter a valid integer.\n");
        return -1;
    }
}

// Function to validate string input
int validateStringInput(char* input) {
    int inputLength = strlen(input) - 1;
    int isAlpha = 1;
    int i;

    // Check if each character is an alphabet
    for (i = 0; i < inputLength; i++) {
        if (!(isalpha(input[i]))) {
            isAlpha = 0;
            break;
        }
    }

    if (isAlpha) {
        return 1;
    } else {
        printf("Invalid input. Please enter a valid string.\n");
        return 0;
    }
}

int main() {
    char integerInput[MAX_INPUT_LENGTH];
    char stringInput[MAX_INPUT_LENGTH];

    printf("Enter an integer: ");
    fgets(integerInput, MAX_INPUT_LENGTH, stdin);
    while (validateIntegerInput((char*) &integerInput) == -1) {
        printf("Enter an integer: ");
        fgets(integerInput, MAX_INPUT_LENGTH, stdin);
    }

    printf("Enter a string: ");
    fgets(stringInput, MAX_INPUT_LENGTH, stdin);
    while (validateStringInput((char*) &stringInput) == 0) {
        printf("Enter a string: ");
        fgets(stringInput, MAX_INPUT_LENGTH, stdin);
    }

    printf("Successfully entered an integer: %d\n", validateIntegerInput((char*) &integerInput));
    printf("Successfully entered a string: %s", stringInput);

    return 0;
}