//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: mathematical
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to check if character is an alphanumeric or not
int is_alphanumeric(char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}

// Function to sanitize string input
void sanitize_input(char *str) {
    int i, j = 0;
    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);
    
    // Loop through the string
    for (i = 0; str[i] != '\0'; i++) {
        if (is_alphanumeric(str[i])) {
            // If character is alphanumeric, add it to buffer
            buffer[j] = str[i];
            j++;
        }
    }
    
    // Copy buffer back to original string
    strcpy(str, buffer);
}

// Main function
int main() {
    char input_string[BUFFER_SIZE];

    // Get input from user
    printf("Enter your input string: ");
    fgets(input_string, BUFFER_SIZE, stdin);
    
    // Sanitize input string
    sanitize_input(input_string);
    
    // Print sanitized string
    printf("\nSanitized input string: %s", input_string);

    return 0;
}