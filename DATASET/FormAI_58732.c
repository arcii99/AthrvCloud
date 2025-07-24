//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize user input
char* sanitize_input(char* input) {
    int len = strlen(input);
    char* sanitized_input = (char*) malloc(sizeof(char) * len);
    int j = 0;
    
    for (int i = 0; i < len; i++) {
        // Check if character is alphanumeric or whitespace
        if (isalnum(input[i]) || isspace(input[i])) {
            // Convert all alphabets to lowercase
            sanitized_input[j++] = tolower(input[i]);
        }
    }
    sanitized_input[j] = '\0';
    return sanitized_input;
}

int main() {
    char input[100];
    printf("Enter input to sanitize: ");
    fgets(input, 100, stdin);
    
    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;
    
    char* sanitized_input = sanitize_input(input);
    printf("Sanitized input: %s\n", sanitized_input);
    free(sanitized_input);
    return 0;
}