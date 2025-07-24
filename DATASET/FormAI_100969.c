//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to remove unwanted characters from user input
void sanitize_input(char* input) {
    int i, j = 0;
    char sanitized_input[100];
    
    // Loop through each character in input
    for (i = 0; i < strlen(input); i++) {
        // Check if character is alphanumeric or a space
        if (isalnum(input[i]) || isspace(input[i])) {
            sanitized_input[j] = input[i];
            j++;
        }
    }
    
    // Add null terminator to sanitized_input
    sanitized_input[j] = '\0';
    
    // Copy sanitized_input back to input
    strcpy(input, sanitized_input);
}

int main() {
    char user_input[100];
    
    // Prompt user for input
    printf("Enter a sentence: ");
    fgets(user_input, 100, stdin);
    
    // Sanitize user input
    sanitize_input(user_input);
    
    // Print sanitized input
    printf("Sanitized Input: %s\n", user_input);
    
    return 0;
}