//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256

/* function to sanitize user input */
char *sanitize(char *input) {
    int len = strlen(input);
    char *new_input = malloc(len + 1);
    if (new_input == NULL) {
        printf("Error: unable to allocate memory.\n");
        exit(1);
    }
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalnum(input[i])) {
            new_input[j++] = input[i];
        }
    }
    new_input[j] = '\0';
    return new_input;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter some input:\n");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; /* remove newline character from input */
    char *sanitized_input = sanitize(input);
    printf("Sanitized input: %s\n", sanitized_input);
    free(sanitized_input);
    return 0;
}