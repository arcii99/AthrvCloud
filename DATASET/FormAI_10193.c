//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024

/* Function prototypes */
char *sanitize_input(char *input);

/* Entry point */
int main(void) {
    char input[MAX_INPUT_SIZE], *sanitized_input;
    printf("Enter your input: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    sanitized_input = sanitize_input(input);
    printf("The sanitized input is: %s\n", sanitized_input);
    free(sanitized_input);
    return 0;
}

/* Function to sanitize the input */
char *sanitize_input(char *input) {
    int i, j;
    char *sanitized = malloc(sizeof(char) * (strlen(input) + 1));
    if (sanitized == NULL) {
        fprintf(stderr, "Error: memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0, j = 0; i < strlen(input); i++) {
        if (isalnum((unsigned char)input[i])) {
            sanitized[j++] = input[i];
        } else if (isspace((unsigned char)input[i])) {
            sanitized[j++] = ' ';
        }
    }
    sanitized[j] = '\0';
    return sanitized;
}