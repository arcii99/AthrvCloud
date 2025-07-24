//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: real-life
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void sanitize(char *input) {
    int i, j = 0;
    char sanitized[100]; // assumes input will not exceed 100 characters

    for (i = 0; input[i] != '\0'; i++) {
        if (isalnum(input[i])) { // checks if character is alphanumeric
            sanitized[j++] = input[i]; // adds character to sanitized string
        }
    }
    sanitized[j] = '\0'; // adds null terminator to end of string

    strcpy(input, sanitized); // copies sanitized string to original input string
}

int main() {
    char input[100];
    printf("Enter some input: ");
    fgets(input, 100, stdin); // gets input from user

    printf("Input before sanitization: %s\n", input);
    sanitize(input);
    printf("Input after sanitization: %s\n", input);

    return 0;
}