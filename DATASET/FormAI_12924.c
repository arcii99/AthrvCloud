//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: retro
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 256

void sanitize_input(char *input);

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter your name: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sanitize_input(input);
    printf("Hello, %s!\n", input);
    return 0;
}

void sanitize_input(char *input) {
    int i, j;
    for (i = 0, j = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            input[j++] = tolower(input[i]);
        }
    }
    input[j] = '\0';
}