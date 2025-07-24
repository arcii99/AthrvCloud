//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

int main(void) {
    char input[MAX_INPUT_LENGTH];
    printf("Welcome to the input sanitizer program! Please enter some text:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    // Remove newline character from input (if present)
    if ((strlen(input) > 0) && (input[strlen(input) - 1] == '\n')) {
        input[strlen(input) - 1] = '\0';
    }
    
    // Replace any special characters with underscores
    for (int i = 0; i < strlen(input); i++) {
        if (!((input[i] >= 'a' && input[i] <= 'z') ||
              (input[i] >= 'A' && input[i] <= 'Z') ||
              (input[i] >= '0' && input[i] <= '9') ||
              (input[i] == ' '))) {
            input[i] = '_';
        }
    }
    
    printf("Your sanitized input is: %s\n", input);
    
    return EXIT_SUCCESS;
}