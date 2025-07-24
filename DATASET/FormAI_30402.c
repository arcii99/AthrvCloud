//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

int main() {

    char input[MAX_INPUT_LENGTH];
    char sanitizedInput[MAX_INPUT_LENGTH];
    int inputLength, sanitizedInputLength;

    printf("Please enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    inputLength = strlen(input);

    // Remove newline character
    if (input[inputLength - 1] == '\n') {
        input[inputLength - 1] = '\0';
        inputLength--;
    }

    // Sanitize input by removing non-alphanumeric characters and converting to lowercase
    sanitizedInputLength = 0;
    for (int i = 0; i < inputLength; i++) {
        if (isalnum(input[i])) {
            sanitizedInput[sanitizedInputLength] = tolower(input[i]);
            sanitizedInputLength++;
        }
    }
    sanitizedInput[sanitizedInputLength] = '\0';

    printf("\nSanitized input: %s", sanitizedInput);

    return 0;
}