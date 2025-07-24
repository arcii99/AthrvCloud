//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Linus Torvalds
#include <stdio.h>

#define MAX_INPUT_LENGTH 50

/**
 * Sanitizes user input to prevent unexpected behavior.
 * Removes any characters that are not numbers or letters.
 */
void sanitizeInput(char* userInput) {
    int i = 0;
    char c;
    while ((c = *(userInput+i)) != '\0') {
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))) {
            *(userInput+i) = '\0';
            break;
        }
        i++;
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sanitizeInput(input);
    printf("Sanitized input: %s\n", input);
    return 0;
}