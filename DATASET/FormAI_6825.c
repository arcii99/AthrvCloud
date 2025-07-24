//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 500

// Function to sanitize user input
void sanitize_input(char* str) {
    char sanitized_str[MAX_INPUT_LENGTH];
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {  // Check if character is alphanumeric
            sanitized_str[j] = str[i];  // Add it to sanitized string
            j++;
        }
    }

    sanitized_str[j] = '\0';  // Add null terminator to end sanitized string
    strcpy(str, sanitized_str);  // Copy sanitized string to original string
}

int main() {
    char input[MAX_INPUT_LENGTH];
  
    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin);  // Use fgets to get user input

    sanitize_input(input);  // Sanitize user input

    printf("Sanitized input: %s\n", input);

    return 0;
}