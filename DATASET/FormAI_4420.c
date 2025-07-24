//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

char *sanitize_input(char *);

int main()
{
    char input[MAX_INPUT_SIZE];
    char *sanitized_input;

    printf("Enter your input: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    sanitized_input = sanitize_input(input);

    printf("Sanitized input: %s\n", sanitized_input);

    free(sanitized_input);

    return 0;
}

char *sanitize_input(char *input)
{
    char *sanitized_input = (char*)malloc(MAX_INPUT_SIZE * sizeof(char));
    int sanitized_idx = 0;

    for (int i = 0; i < strlen(input); i++) {
        if (isalnum(input[i])) {
            sanitized_input[sanitized_idx] = input[i];
            sanitized_idx++;
        }
    }

    return sanitized_input;
}