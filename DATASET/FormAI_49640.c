//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

const int MAX_INPUT_LENGTH = 1000;

char* sanitize(char* input);

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter some text: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    char* sanitized_input = sanitize(input);
    printf("\nSanitized text: %s", sanitized_input);
    free(sanitized_input);
    return 0;
}

char* sanitize(char* input) {
    char* sanitized_input = malloc(sizeof(char) * (strlen(input) + 1));
    int i = 0, j = 0;
    while (input[i] != '\0') {
        if (isalnum(input[i])) {
            sanitized_input[j] = input[i];
            j++;
        }
        i++;
    }
    sanitized_input[j] = '\0';
    return sanitized_input;
}