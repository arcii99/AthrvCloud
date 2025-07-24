//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize user input
char* sanitize(char* input) {
    char* clean = malloc(strlen(input)); // allocate memory for sanitized string
    for (int i = 0, j = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            clean[j] = input[i]; // add letters to sanitized string
            j++;
        }
        else if (isdigit(input[i])) {
            clean[j] = input[i]; // add numbers to sanitized string
            j++;
        }
        // ignore special characters and spaces
    }
    clean[strlen(input)] = '\0'; // add null terminator to sanitized string
    return clean;
}

int main() {
    char* input = malloc(100); // allocate memory for user input
    printf("Enter a string to sanitize: ");
    fgets(input, 100, stdin); // read user input from console
    input[strcspn(input, "\n")] = 0; // remove newline character from input
    
    char* sanitized = sanitize(input); // sanitize user input
    printf("Sanitized string: %s\n", sanitized);

    free(input); // free memory allocated for user input
    free(sanitized); // free memory allocated for sanitized string
    return 0;
}