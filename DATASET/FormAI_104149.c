//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// This function removes any non-alphabetic characters from the input string
void sanitizeInputString(char* inputString) {
    int i, j = 0;
    for (i = 0; inputString[i]; i++) {
        // Convert each character to lowercase
        inputString[i] = tolower(inputString[i]);
        if (isalpha(inputString[i])) {
            // If the character is alphabetic, copy it to the output string
            inputString[j++] = inputString[i];
        }
    }
    inputString[j] = '\0';
}

int main() {
    char userInput[100];

    printf("Enter a message: ");
    fgets(userInput, sizeof(userInput), stdin);

    // Sanitize the user input
    sanitizeInputString(userInput);

    // Print the sanitized input
    printf("Sanitized input: %s\n", userInput);

    return 0;
}