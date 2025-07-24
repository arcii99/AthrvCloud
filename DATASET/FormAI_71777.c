//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

// function to sanitize user input
void sanitize(char *input) {
    int i;
    int length = strlen(input);

    // iterate over each character in the input string
    for (i = 0; i < length; i++) {
        // if the character is not alphanumeric, replace it with a space
        if (!isalnum(input[i])) {
            input[i] = ' ';
        }

        // convert uppercase letters to lowercase
        if (isupper(input[i])) {
            input[i] = tolower(input[i]);
        }
    }
}

int main() {
    char input[MAX_INPUT_LENGTH]; // buffer for user input
    memset(input, 0, MAX_INPUT_LENGTH); // initialize input buffer to zeros

    // prompt the user for input
    printf("Enter some text to sanitize:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin); // read user input from stdin

    // sanitize the input and print the sanitized version
    sanitize(input);
    printf("Sanitized input:\n%s", input);

    return 0;
}