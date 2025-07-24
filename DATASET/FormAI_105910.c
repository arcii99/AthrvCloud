//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

// Function to sanitize user input by removing any unwanted characters
char* sanitize_input(char* input) {
    char* sanitized_input = (char*) malloc(sizeof(char) * MAX_LENGTH);
    int j = 0;
    for (int i = 0; i < strlen(input); i++) {
        if ((input[i] >= 'A' && input[i] <= 'Z') ||
            (input[i] >= 'a' && input[i] <= 'z') ||
            (input[i] >= '0' && input[i] <= '9')) {
            sanitized_input[j++] = input[i];
        }
    }
    sanitized_input[j] = '\0';
    return sanitized_input;
}

int main() {
    char input[MAX_LENGTH];
    printf("Please enter your input: ");
    fgets(input, MAX_LENGTH, stdin);
    char* sanitized_input = sanitize_input(input);
    printf("Sanitized input: %s\n", sanitized_input);
    free(sanitized_input);
    return 0;
}