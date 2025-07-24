//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 256
#define MAX_SANITIZED_SIZE 1024

int main() {

    // Create buffers for input and sanitized output
    char input[MAX_INPUT_SIZE];
    char sanitized[MAX_SANITIZED_SIZE];
    memset(sanitized, 0, MAX_SANITIZED_SIZE);
    
    // Prompt user for input
    printf("Please enter a string to sanitize: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Find the length of the input string
    int input_len = strlen(input) - 1; // Remove the newline character from the input
    
    // Loop through each character in the input string to sanitize it
    int sanitized_index = 0;
    for (int i = 0; i < input_len; i++) {
        char current_char = input[i];

        // Sanitize the current character based on its ASCII code
        if (current_char >= 32 && current_char <= 126) {
            sanitized[sanitized_index] = current_char;
            sanitized_index++;
        }
        else if (current_char == '\t') {
            sanitized[sanitized_index] = '\\';
            sanitized[sanitized_index+1] = 't';
            sanitized_index += 2;
        }
        else if (current_char == '\n') {
            sanitized[sanitized_index] = '\\';
            sanitized[sanitized_index+1] = 'n';
            sanitized_index += 2;
        }
        else if (current_char == '\r') {
            sanitized[sanitized_index] = '\\';
            sanitized[sanitized_index+1] = 'r';
            sanitized_index += 2;
        }
    }
    sanitized[sanitized_index] = '\0'; // Add null terminator to sanitized output
    
    // Print the sanitized string
    printf("Sanitized string: %s\n", sanitized);

    return 0;

}