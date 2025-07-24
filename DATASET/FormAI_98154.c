//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: ephemeral
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void sanitizeInput(char* input);

int main()
{
    char input[MAX_INPUT_LENGTH];

    printf("Enter a string: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    sanitizeInput(input);

    printf("Sanitized Input: %s", input);

    return 0;
}

void sanitizeInput(char* input)
{
    int length = strlen(input);

    for (int i = 0; i < length; i++)
    {
        if (!isalpha(input[i]))
        {
            input[i] = '\0';
            break;
        }
        input[i] = tolower(input[i]);
    }
}