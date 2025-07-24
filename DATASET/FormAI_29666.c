//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 512

int main() {

    // Allocate memory for user input
    char* user_input = (char*) malloc(MAX_INPUT_LENGTH * sizeof(char));

    // Prompt user to enter input
    printf("Enter a string: ");
    fgets(user_input, MAX_INPUT_LENGTH, stdin);

    // Remove trailing newline character from user input
    user_input[strcspn(user_input, "\n")] = '\0';

    // Allocate memory for sanitized input
    char* sanitized_input = (char*) malloc(MAX_INPUT_LENGTH * sizeof(char));

    int index = 0;

    // Loop through user input and sanitize any unwanted characters
    for (int i = 0; i < strlen(user_input); i++) {
        if ((user_input[i] >= 48 && user_input[i] <= 57) ||
            (user_input[i] >= 65 && user_input[i] <= 90) ||
            (user_input[i] >= 97 && user_input[i] <= 122) ||
            (user_input[i] == 32)) {
            sanitized_input[index++] = user_input[i];
        }
    }

    // Null terminate the sanitized input
    sanitized_input[index] = '\0';

    // Print the sanitized input
    printf("Sanitized input: %s\n", sanitized_input);

    // Free the memory allocated for user input and sanitized input
    free(user_input);
    free(sanitized_input);

    return 0;
}