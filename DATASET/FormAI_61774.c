//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 100

void sanitizeInput(char userInput[], int length);
void printArray(char arr[], int length);

int main(void) {
    char userInput[MAX_LENGTH];
    int length = 0;

    // Get user input
    printf("Enter a string (max length %d): ", MAX_LENGTH);
    fgets(userInput, MAX_LENGTH, stdin);

    // Get user input length
    while (userInput[length] != '\0') {
        length++;
    }

    // Sanitize user input
    sanitizeInput(userInput, length);

    // Print sanitized user input
    printf("Sanitized user input: ");
    printArray(userInput, length);

    return 0;
}

// Sanitize user input
void sanitizeInput(char userInput[], int length) {
    int i = 0;
    char sanitizedInput[MAX_LENGTH];
    
    // Replace non-alphanumeric characters with a space
    for (i = 0; i < length; i++) {
        if (!isalnum(userInput[i])) {
            sanitizedInput[i] = ' ';
        } else {
            sanitizedInput[i] = userInput[i];
        }
    }

    // Copy sanitized input to user input
    for (i = 0; i < length; i++) {
        userInput[i] = sanitizedInput[i];
    }
}

// Print array with a certain length
void printArray(char arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", arr[i]);
    }
    printf("\n");
}