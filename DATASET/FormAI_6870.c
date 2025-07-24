//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 256

void sanitizeInput(char input[MAX_INPUT_SIZE]);

int main()
{
    char input[MAX_INPUT_SIZE];

    printf("Please enter your input: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    sanitizeInput(input);

    printf("Your sanitized input is: %s\n", input);

    return 0;
}

void sanitizeInput(char input[MAX_INPUT_SIZE])
{
    char sanitized[MAX_INPUT_SIZE] = "";
    int i, j = 0;

    for (i = 0; input[i] != '\0' && input[i] != '\n'; i++)
    {
        if (isalnum(input[i]))
        {
            sanitized[j++] = input[i];
        }
    }

    sanitized[j] = '\0';
    strcpy(input, sanitized);
}