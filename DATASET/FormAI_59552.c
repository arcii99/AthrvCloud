//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 100 // maximum length of user input

void sanitize(char *input); // function prototype for input sanitizer

int main(void) {
    char input[MAX_INPUT]; // declare input buffer
    printf("Enter a string with special characters: ");
    fgets(input, MAX_INPUT, stdin); // read user input
    sanitize(input); // call input sanitizer function
    printf("Sanitized input: %s", input); // print sanitized input
    return 0; // return success
}

void sanitize(char *input) {
    int i, j = 0;
    char sanitized[MAX_INPUT]; // declare sanitized input buffer
    for (i = 0; input[i] != '\0' && i < MAX_INPUT; i++) {
        if (isalnum(input[i]) || isspace(input[i])) { // check if character is alphanumeric or whitespace
            sanitized[j] = input[i]; // copy character to sanitized input buffer
            j++; // increment sanitized input index
        }
    }
    sanitized[j] = '\0'; // terminate sanitized input string
    strcpy(input, sanitized); // copy sanitized input to original input buffer
}