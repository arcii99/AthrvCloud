//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: shocked
#include <stdio.h>
#include <ctype.h>

#define BUFFER_SIZE 100

int main() {
    char input[BUFFER_SIZE];
    int i;

    printf("Enter your input:\n");
    if (fgets(input, BUFFER_SIZE, stdin) != NULL) {
        for (i = 0; input[i] != '\0'; i++) {
            if (isalnum(input[i]) || isspace(input[i])) {
                continue;
            } else {
                input[i] = '_';
            }
        }

        printf("Sanitized input: %s", input);
    }

    return 0;
}