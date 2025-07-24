//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100
#define ALLOWED_CHARACTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+-=[]{}\\|;:\"'<>,.?/"

void sanitizeInput(char *input)
{
    int inputLength = strlen(input);
    int i, j;

    // Replace any non-allowed character with space
    for (i = 0; i < inputLength; i++)
    {
        if (!strchr(ALLOWED_CHARACTERS, input[i]))
        {
            input[i] = ' ';
        }
    }

    // Remove leading and trailing spaces
    while (input[0] == ' ')
    {
        memmove(input, input + 1, strlen(input));
    }

    while ((inputLength > 0) && (input[inputLength - 1] == ' '))
    {
        inputLength--;
    }
    input[inputLength] = '\0';

    // Remove duplicate spaces
    for (i = 0; i < inputLength - 1; i++)
    {
        if ((input[i] == ' ') && (input[i + 1] == ' '))
        {
            for (j = i; j < inputLength; j++)
            {
                input[j] = input[j + 1];
            }
            inputLength--;
            i--;
        }
    }

    // Convert input to lowercase
    for (i = 0; i < inputLength; i++)
    {
        input[i] = tolower(input[i]);
    }
}

int main()
{
    char input[MAX_INPUT_LENGTH];

    printf("Please enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    sanitizeInput(input);

    printf("Your sanitized input is: %s", input);

    return 0;
}