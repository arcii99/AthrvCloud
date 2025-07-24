//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1000

char* sanitize_input(char* input);

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter input: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    char* sanitized_input = sanitize_input(input);
    printf("Sanitized input: %s\n", sanitized_input);
    free(sanitized_input);
    return 0;
}

char* sanitize_input(char* input) {
    char* sanitized_input = (char*) malloc(MAX_INPUT_SIZE * sizeof(char));
    int index = 0;

    for(int i = 0; input[i] != '\0'; i++) {
        if(isalpha(input[i])) {
            sanitized_input[index++] = tolower(input[i]);
        } else if(isspace(input[i])) {
            sanitized_input[index++] = ' ';
        }
    }
    sanitized_input[index] = '\0';

    return sanitized_input;
}