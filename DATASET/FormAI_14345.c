//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000 // Maximum length of input string

/*
* Function to sanitize user input
* Removes leading and trailing whitespaces
* Converts all lowercase letters to uppercase
*/

void sanitizeInput(char *input) {
    // Remove leading whitespaces
    while (isspace((unsigned char)*input))
        input++;

    // Remove trailing whitespaces
    int length = strlen(input);
    while (length > 0 && isspace((unsigned char)input[length - 1]))
        length--;
    input[length] = '\0';

    // Convert all lowercase letters to uppercase
    for (int i = 0; i < length; i++) {
        if (islower((unsigned char)input[i]))
            input[i] = toupper((unsigned char)input[i]);
    }
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter your name: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove newline character from input
    if (input[strlen(input) - 1] == '\n')
        input[strlen(input) - 1] = '\0';

    // Sanitize user input
    sanitizeInput(input);

    printf("Hello, %s!\n", input);

    return 0;
}