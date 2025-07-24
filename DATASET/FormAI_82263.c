//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

int main() {
    char input[MAX_INPUT_LENGTH];
    char sanitized_input[MAX_INPUT_LENGTH];
    int i, j, k;

    printf("Enter your input:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin); // Get user input

    // Sanitize the input
    for (i = 0, j = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) { // If a letter is found
            sanitized_input[j] = tolower(input[i]); // Convert to lowercase
            j++;
        }
        else if (isdigit(input[i])) { // If a digit is found
            sanitized_input[j] = input[i];
            j++;
        }
    }
    sanitized_input[j] = '\0'; // Terminate the sanitized input string with a null character

    // Print the sanitized input
    printf("Sanitized input: %s\n", sanitized_input);

    return 0;
}