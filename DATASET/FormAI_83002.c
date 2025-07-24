//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* sanitize_input(char* input);

int main() {
    char input[50];
    printf("Enter your input: ");
    fgets(input, 50, stdin);
    char* sanitized_input = sanitize_input(input);
    printf("Sanitized input: %s\n", sanitized_input);
    free(sanitized_input);
    return 0;
}

char* sanitize_input(char* input) {
    int length = strlen(input);
    char* sanitized_input = (char*) malloc(length + 1);
    int i, j = 0;
    for (i = 0; i < length; i++) {
        if (isalnum(input[i]) || isspace(input[i])) {
            sanitized_input[j++] = input[i];
        }
    }
    sanitized_input[j] = '\0';
    return sanitized_input;
}