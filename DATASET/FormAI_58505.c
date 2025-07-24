//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: modular
#include <stdio.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 50

// Function to sanitize user input
void sanitizeInput(char input[]) {
    int i = 0;
    while (input[i]) {
        // Convert all uppercase letters to lowercase
        input[i] = tolower(input[i]);
        // Replace any non-alphanumeric characters with a space
        if (!isalnum(input[i])) {
            input[i] = ' ';
        }
        i++;
    }
}

int main() {
    char userInput[MAX_INPUT_LENGTH];
    
    printf("Enter your input (max length: %d): ", MAX_INPUT_LENGTH);
    fgets(userInput, MAX_INPUT_LENGTH, stdin);
    
    // Sanitize the user input
    sanitizeInput(userInput);
    
    // Print the sanitized input
    printf("Sanitized Input: %s", userInput);
    
    return 0;
}