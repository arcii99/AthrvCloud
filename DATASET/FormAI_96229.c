//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitize_input(char *str) {
    // TODO: implement input sanitization
}

int main() {
    char input[100];
    printf("Enter your name:\n");
    fgets(input, sizeof(input), stdin);

    sanitize_input(input);

    printf("Hello, %s!\n", input);
    return 0;
}