//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char* sanitizeInput(char* input) {
    // Allocate memory for sanitized string
    char* sanitized = (char*)malloc(MAX_SIZE*sizeof(char));
    int j = 0; // Index for sanitized string
    
    // Loop through input string and sanitize
    for(int i = 0; i < strlen(input); i++) {
        if(isalpha(input[i])) { // If letter, convert to lowercase and add to sanitized string
            sanitized[j] = tolower(input[i]);
            j++;
        }
        else if(isdigit(input[i])) { // If digit, add to sanitized string
            sanitized[j] = input[i];
            j++;
        }
    }
    
    // Add null terminator to end of sanitized string
    sanitized[j] = '\0';
    
    return sanitized;
}

int main() {
    char input[MAX_SIZE];
    char* sanitizedInput;
    
    printf("Enter input to sanitize: ");
    fgets(input, MAX_SIZE, stdin); // Use fgets to prevent buffer overflow
    
    sanitizedInput = sanitizeInput(input);
    
    printf("Sanitized input: %s\n", sanitizedInput);
    
    free(sanitizedInput); // Free dynamically allocated memory
    
    return 0;
}