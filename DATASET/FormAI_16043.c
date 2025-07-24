//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 256

void sanitize_input(char input[]) {
    int i, j;

    for (i = 0, j = 0; input[i]; i++) {
        if (isalnum(input[i])) {
            input[j++] = tolower(input[i]);
        }
    }
    input[j] = '\0';
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter your input:\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    sanitize_input(input);

    printf("Sanitized input: %s\n", input);

    return 0;
}