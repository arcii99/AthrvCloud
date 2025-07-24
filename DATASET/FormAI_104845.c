//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    int length, i;
    printf("Welcome to the input sanitizer\n");
    printf("Please enter your input (maximum length of %d): ", MAX_LENGTH);
    fgets(input, MAX_LENGTH, stdin); // read input from user

    length = strlen(input);
    for (i = 0; i < length; i++) {
        if (isalnum(input[i])) {  // leave alphanumeric characters as is
            continue;
        } else if (isspace(input[i])) {  // replace whitespace with underscore
            input[i] = '_';
        } else {  // replace other characters with asterisk
            input[i] = '*';
        }
    }

    printf("\nYour sanitized input: %s\n", input);
    printf("Thank you for using our input sanitizer!\n");

    return 0;
}