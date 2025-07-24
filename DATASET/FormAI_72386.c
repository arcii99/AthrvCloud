//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

int main(void) {
    char input[MAX_INPUT_LENGTH];
    char sanitizedInput[MAX_INPUT_LENGTH];
    int inputIndex = 0;
    int index = 0;

    printf("Enter input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Sanitize input
    while (input[inputIndex] != '\0') {
        if (isalpha(input[inputIndex])) {
            sanitizedInput[index] = tolower(input[inputIndex]);
            index++;
        }
        inputIndex++;
    }
    sanitizedInput[index] = '\0';

    printf("Sanitized Input: %s", sanitizedInput);

    return 0;
}