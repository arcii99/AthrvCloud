//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void sanitizeInput(char *input) {
    char *p = input;
    while (*p) {
        if (!isalnum(*p)) {
            *p = ' ';
        } else {
            *p = tolower(*p);
        }
        p++;
    }
}

int main() {
    char input[100];
    printf("Enter your input: ");
    fgets(input, 100, stdin);

    sanitizeInput(input);

    printf("Sanitized input: %s", input);

    return 0;
}