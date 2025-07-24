//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sanitizeInput(char *input);

int main() {
    char input[256];

    printf("Enter some input: ");
    fgets(input, 256, stdin);

    sanitizeInput(input);

    printf("\nSanitized input: %s", input);

    return 0;
}

void sanitizeInput(char *input) {
    int len = strlen(input);
    char sanitized[len];
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (!isalnum(input[i])) {
            continue;
        }
        sanitized[j++] = tolower(input[i]);
    }
    sanitized[j] = '\0';
    strcpy(input, sanitized);

    return;
}