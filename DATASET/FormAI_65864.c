//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: innovative
#include <stdio.h>
#include <ctype.h>

/* Define maximum length of input */
#define MAX_LENGTH 1000

/* Function declarations */
int sanitize_input(char input[], int length);

int main() {
    /* Define input array */
    char input[MAX_LENGTH];

    /* Get user input */
    printf("Enter your input:\n");
    fgets(input, MAX_LENGTH, stdin);

    /* Sanitize input */
    int sanitized_length = sanitize_input(input, MAX_LENGTH);

    /* Print sanitized input */
    printf("Sanitized input: %s\n", input);

    return 0;
}

/* This function sanitizes user input by removing invalid characters */
int sanitize_input(char input[], int length) {
    int sanitized_length = 0;

    for (int i = 0; i < length; i++) {
        char c = input[i];

        /* Check for end of input */
        if (c == '\0') {
            break;
        }

        /* Check if character is valid */
        if (isalnum(c) || c == ' ' || c == '.' || c == ',' || c == '?' || c == '!') {
            input[sanitized_length] = c;
            sanitized_length++;
        }
    }

    /* Add null terminator at end of input */
    input[sanitized_length] = '\0';

    return sanitized_length;
}