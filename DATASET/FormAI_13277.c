//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Function to sanitize user input */
char* sanitize(char* input) {
    char* sanitized = (char*) malloc(sizeof(char) * (strlen(input) + 1)); // Allocate memory
    
    int i, j = 0;
    for (i = 0; i < strlen(input); i++) {
        char c = input[i];
        if (isalnum(c) || isspace(c)) { // Check if alphanumeric or whitespace
            sanitized[j] = c;
            j++;
        }
    }
    sanitized[j] = '\0'; // Terminate string with null character
    
    return sanitized;
}

int main() {
    printf("Welcome to the User Input Sanitizer!\n");
    printf("Please enter some input: ");
    
    char input[1000];
    fgets(input, 1000, stdin); // Get user input
    
    printf("Sanitized input: %s\n", sanitize(input)); // Sanitize input
    
    return 0;
}