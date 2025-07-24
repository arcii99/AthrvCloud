//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a function to sanitize user input
void sanitize_input(char *input) {
    int i = 0, j = 0;

    while (input[i]) {
        // Check if input is a letter, digit, or whitespace
        if (isalnum(input[i]) || isspace(input[i])) {
            input[j++] = input[i];
        }
        i++;
    }

    // Add terminating null character to sanitized input
    input[j] = '\0';
}

int main() {
    char input[100];
    
    // Prompt user for input
    printf("Enter input: ");
    fgets(input, 100, stdin);
    
    // Remove trailing newline character from input
    input[strcspn(input, "\n")] = 0;

    // Sanitize user input
    sanitize_input(input);

    // Print sanitized input
    printf("Sanitized input: %s\n", input);

    return 0;
}