//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: energetic
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char userInput[1000];
    printf("Welcome to Input Sanitizer!\n");
    printf("Please enter your input: ");

    fgets(userInput, sizeof(userInput), stdin);

    // Remove trailing newline from user input
    userInput[strcspn(userInput, "\n")] = 0;

    // Convert all characters to uppercase
    for (int i = 0; i < strlen(userInput); i++) {
        userInput[i] = toupper(userInput[i]);
    }

    // Remove any non-alphabetic characters
    char sanitizedInput[1000];
    int j = 0;
    for (int i = 0; i < strlen(userInput); i++) {
        if (isalpha(userInput[i])) {
            sanitizedInput[j] = userInput[i];
            j++;
        }
    }
    sanitizedInput[j] = '\0';

    printf("\nSanitized input: %s", sanitizedInput);

    return 0;
}