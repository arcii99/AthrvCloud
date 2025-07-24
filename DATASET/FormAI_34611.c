//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256

// Function to sanitize user input by removing non-alphanumeric characters and converting to lowercase
void sanitizeInput(char* input) {
    int i, j;
    char sanitized[MAX_INPUT_LENGTH];
    
    // Removing non-alphanumeric characters and converting to lowercase
    for (i = 0, j = 0; i < strlen(input); i++) {
        if (isalnum(input[i])) {
            sanitized[j] = tolower(input[i]);
            j++;
        }
    }
    sanitized[j] = '\0'; // Adding null terminator to end the sanitized input string
    
    // Copying the sanitized input back to the original input string
    strcpy(input, sanitized);
}

int main() {
    char userInput[MAX_INPUT_LENGTH];
    
    printf("Enter your input: ");
    fgets(userInput, MAX_INPUT_LENGTH, stdin); // Reading user input from standard input
    
    // Removing newline character from user input if present
    if (userInput[strlen(userInput)-1] == '\n') {
        userInput[strlen(userInput)-1] = '\0';
    }
    
    sanitizeInput(userInput); // Sanitizing user input
    
    printf("Sanitized input: %s\n", userInput); // Printing sanitized input
    
    return 0;
}