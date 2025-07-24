//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sanitizeInput(char input[]);

int main() {
    // Declare variables
    char input[100];

    // Prompt user for input
    printf("Please enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Sanitize input
    sanitizeInput(input);

    // Print sanitized input
    printf("Your input after sanitation: %s", input);

    return 0;
}

void sanitizeInput(char input[]) {
    // Declare variables
    int i, j;
    char sanitizedInput[100];

    // Loop through each character of the input
    for (i = 0, j = 0; i < strlen(input); i++) {
        // If the character is alphanumeric, lowercase it and add it to sanitizedInput
        if (isalnum(input[i])) {
            sanitizedInput[j] = tolower(input[i]);
            j++;
        }
    }

    // Null-terminate sanitizedInput
    sanitizedInput[j] = '\0';

    // Copy sanitizedInput back into input
    strcpy(input, sanitizedInput);
}