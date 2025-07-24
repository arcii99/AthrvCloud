//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 100

void sanitize_input(char *input) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (!isalnum(input[i])) {
            input[i] = '_'; // replace non-alphanumeric characters with underscore
        }
    }
}

int main(void) {
    char input[MAX_INPUT];
    printf("Please enter your input: ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline from input
    sanitize_input(input);
    printf("Your sanitized input is: %s\n", input);
    return 0;
}