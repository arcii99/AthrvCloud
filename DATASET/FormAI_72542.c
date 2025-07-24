//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum character limit
#define MAX_LIMIT 50

// Function to sanitize user input and remove any unwanted characters
void sanitizeInput(char *str, int len) {
    int i, j;
    char c;
    for(i = 0, j = 0; i < len; i++) {
        c = str[i];
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            str[j++] = c;
        }
    }
    str[j] = '\0';
}

int main() {
    // Define variables
    char input[MAX_LIMIT];
    int input_length;
    
    // Prompt user for input
    printf("Please enter your input (maximum %d characters):\n", MAX_LIMIT);
    fgets(input, MAX_LIMIT, stdin);
    
    // Get length of input
    input_length = strlen(input);
    
    // Remove trailing newline character from input
    if(input[input_length-1] == '\n') {
        input[input_length-1] = '\0';
        input_length--;
    }
    
    // Sanitize user input
    sanitizeInput(input, input_length);
    
    // Display sanitized input
    printf("Sanitized input: %s\n", input);
    
    return 0;
}