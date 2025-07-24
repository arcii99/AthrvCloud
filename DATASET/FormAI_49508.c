//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize user input
char* sanitize(char* input) {
    int len = strlen(input);
    char* sanitized = (char*)malloc(len+1);
    int j = 0;
    for (int i = 0; i < len; i++) {
        // If character is alphabetic, convert to lowercase
        if (isalpha(input[i])) {
            sanitized[j] = tolower(input[i]);
            j++;
        }
        // If character is a digit, append to output
        else if (isdigit(input[i])){
            sanitized[j] = input[i];
            j++;
        }
        // If character is a space or comma, ignore
        else if (input[i] == ' ' || input[i] == ',') {
            continue;
        }
        // For all other characters, replace with '_'
        else {
            sanitized[j] = '_';
            j++;
        }
    }
    sanitized[j] = '\0'; // Add null character at end of string
    return sanitized;
}

int main() {
    printf("Please enter your name and age (separated by comma):\n");
    char input[50];
    scanf("%49[^\n]", input); // Read input from user
    char* sanitized_input = sanitize(input); // Sanitize input
    printf("Sanitized input: %s\n", sanitized_input); // Output sanitized input
    free(sanitized_input); // Free memory allocated to sanitized input
    return 0;
}