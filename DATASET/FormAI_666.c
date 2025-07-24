//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter a string with special characters or spaces:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove new line character

    char sanitizedInput[MAX_INPUT_LENGTH];
    int j = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (isalnum(input[i])) {
            sanitizedInput[j++] = input[i];
        }
    }
    sanitizedInput[j] = '\0'; // null terminate the string

    printf("Sanitized string: %s", sanitizedInput);

    return 0;
}