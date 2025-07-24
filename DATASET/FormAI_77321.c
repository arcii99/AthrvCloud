//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 256

void sanitizeInput(char *input);

int main()
{
    char input[BUFFER_SIZE];

    printf("Welcome to the Input Sanitizer program!\n");
    printf("Please enter some input below:\n");

    fgets(input, BUFFER_SIZE, stdin);
    sanitizeInput(input);

    printf("\nYour sanitized input is:\n%s", input);

    return 0;
}

void sanitizeInput(char *input)
{
    int i, j;
    char c;

    for (i = 0, j = 0; input[i] != '\0'; i++) {
        c = input[i];

        if (isalnum(c) || isspace(c)) {
            input[j++] = c;
        }
    }

    input[j] = '\0';

    printf("\nSanitization complete!\n");
}