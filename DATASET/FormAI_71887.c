//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

char* sanitize_input(char* input);

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter your input:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    char* sanitized_input = sanitize_input(input);
    printf("The sanitized input is: %s\n", sanitized_input);
    free(sanitized_input);
    return 0;
}

char* sanitize_input(char* input) {
    char* sanitized_input = (char*) malloc(sizeof(char) * MAX_INPUT_LENGTH);
    int i = 0, j = 0;
    while (input[i] != '\0' && j < MAX_INPUT_LENGTH - 1) {
        if (isalnum(input[i])) {
            sanitized_input[j] = input[i];
            j++;
        }
        i++;
    }
    sanitized_input[j] = '\0';
    return sanitized_input;
}