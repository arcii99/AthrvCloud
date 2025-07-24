//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: modular
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

// Function to sanitize user input
void sanitizeInput(char *input) {
    char sanitizedInput[MAX_INPUT_SIZE];
    int j = 0;
    
    for(int i = 0; input[i] != '\0'; i++) {
        // Ignore non-alphanumeric characters
        if(!isalnum(input[i])) {
            continue;
        }
        // Convert uppercase characters to lowercase
        if(isupper(input[i])) {
            sanitizedInput[j++] = tolower(input[i]);
            continue;
        }
        sanitizedInput[j++] = input[i];
    }
    sanitizedInput[j] = '\0';   // Terminate the string
    strcpy(input, sanitizedInput);  // Copy sanitized input back to original input
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter some input: ");
    fgets(input, MAX_INPUT_SIZE, stdin);   // Get user input
    sanitizeInput(input);   // Sanitize user input
    printf("Sanitized input: %s", input);
    return 0;
}