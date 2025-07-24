//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int main() {
    char userInput[MAX_SIZE];
    printf("Enter your input: ");
    fgets(userInput, MAX_SIZE, stdin);

    // Remove newline character
    userInput[strcspn(userInput, "\n")] = 0;

    // Ensure input is alphanumeric
    for (int i = 0; i < strlen(userInput); i++) {
        if (!isalnum(userInput[i])) {
            printf("Invalid input. Only alphanumeric characters are allowed.\n");
            exit(0);
        }
    }

    // Output sanitized input
    printf("Sanitized input: %s\n", userInput);

    return 0;
}