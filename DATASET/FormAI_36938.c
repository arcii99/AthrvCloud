//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

void sanitize_input(char *input)
{
    int i = 0;
    char sanitized[MAX_INPUT_LENGTH] = {0};

    while (input[i])
    {
        if (isalpha(input[i]))
        {
            sanitized[i] = tolower(input[i]);
        }
        else if (isdigit(input[i]))
        {
            sanitized[i] = input[i];
        }
        else if (isspace(input[i]))
        {
            sanitized[i] = ' ';
        }
        else
        {
            sanitized[i] = '_';
        }

        i++;
    }

    strncpy(input, sanitized, MAX_INPUT_LENGTH);
}

int main()
{
    char input[MAX_INPUT_LENGTH] = {0};
    printf("Please enter some input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    sanitize_input(input);

    printf("Sanitized input: %s\n", input);
    
    return 0;
}