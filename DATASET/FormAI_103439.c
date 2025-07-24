//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256

void sanitize_input(char* input) {
    int len = strlen(input);
    int new_len = 0;
    char new_input[MAX_INPUT_LENGTH];

    // iterate over the original input
    for (int i = 0; i < len; i++) {
        char c = input[i];
        if (c >= 'a' && c <= 'z') {
            new_input[new_len++] = c;
        } else if (c >= 'A' && c <= 'Z') {
            new_input[new_len++] = c;
        } else if (c >= '0' && c <= '9') {
            new_input[new_len++] = c;
        } else if (c == ' ') {
            new_input[new_len++] = c;
        }
    }

    // null-terminate the new input
    new_input[new_len] = '\0';

    // copy the sanitized input back into the original input buffer
    strncpy(input, new_input, MAX_INPUT_LENGTH);
}

int main() {
    char input[MAX_INPUT_LENGTH];

    // get input from the user
    printf("Enter some un-sanitized input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // sanitize the input
    sanitize_input(input);

    // print the sanitized input
    printf("The sanitized input is: %s\n", input);

    return 0;
}