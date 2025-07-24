//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100];
    printf("Enter your input: ");
    fgets(input, 100, stdin);

    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        if (input[i] == '\n') {
            input[i] = '\0';
            break;
        }
    }

    char sanitized[100];
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalnum(input[i]) || isspace(input[i])) {
            sanitized[j++] = input[i];
        }
    }
    sanitized[j] = '\0';

    printf("Sanitized input: %s\n", sanitized);

    return 0;
}