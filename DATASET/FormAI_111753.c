//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: minimalist
#include <stdio.h>
#include <string.h>

int main() {
    char input[50];
    printf("Enter a string: "); // Prompt the user for input
    fgets(input, sizeof(input), stdin); // Store the user input into the buffer

    // Remove new line character from stdin buffer
    if(input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    // Remove any unwanted characters
    for(int i = 0; input[i] != '\0'; i++) {
        if(!(input[i] >= 'a' && input[i] <= 'z') && !(input[i] >= 'A' && input[i] <= 'Z') && !(input[i] >= '0' && input[i] <= '9')) {
            input[i] = '\0';
            break;
        }
    }

    printf("Sanitized input: %s\n", input); // Output the sanitized input

    return 0;
}