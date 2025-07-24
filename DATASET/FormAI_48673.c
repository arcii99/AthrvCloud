//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: standalone
#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100];
    char sanitized[100];
    int i, j = 0;

    printf("Enter your input: ");
    fgets(input, sizeof(input), stdin);

    for (i = 0; input[i] != '\0'; i++) {
        if (isalnum(input[i]) || input[i] == ' ') {
            sanitized[j++] = input[i];
        }
    }
    sanitized[j] = '\0';

    printf("Sanitized input: %s", sanitized);

    return 0;
}