//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000

void sanitize_input(char *input) {
    char *src = input;
    char *dst = input;
    int len = strlen(input);
    int is_space = 0;

    for (int i = 0; i < len; i++) {
        char c = *(src + i);

        // handle spaces
        if (isspace(c)) {
            if (!is_space) {
                *dst++ = ' ';
                is_space = 1;
            }
        // handle non-spaces
        } else {
            *dst++ = tolower(c);
            is_space = 0;
        }
    }

    // terminate sanitized string
    *dst = '\0';
}

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Enter some text: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    sanitize_input(input);

    printf("Sanitized input: %s\n", input);

    return 0;
}