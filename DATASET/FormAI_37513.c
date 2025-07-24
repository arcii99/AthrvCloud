//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[50];
    printf("Enter your name: ");
    fgets(input, 50, stdin); // Get the user input

    // Sanitize the input
    for (int i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            // Convert letters to uppercase
            input[i] = toupper(input[i]);
        } else if (isdigit(input[i])) {
            // Replace digits with asterisks
            input[i] = '*';
        } else if (isspace(input[i])) {
            // Remove spaces
            for (int j = i; j < strlen(input); j++) {
                input[j] = input[j+1];
            }
            i--; // Decrement i to check the new character at i
        } else {
            // Remove non-alphanumeric characters
            for (int j = i; j < strlen(input); j++) {
                input[j] = input[j+1];
            }
            i--;
        }
    }

    printf("Sanitized input: %s\n", input);
    return 0;
}