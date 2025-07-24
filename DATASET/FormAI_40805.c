//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

char* sanitize_input(char* input_str);

int main()
{
    char input[MAX_INPUT_LENGTH];
    printf("Please enter a string of up to %d characters:\n", MAX_INPUT_LENGTH);
    fgets(input, MAX_INPUT_LENGTH, stdin);

    char* sanitized_input = sanitize_input(input);
    printf("Sanitized input: %s\n", sanitized_input);

    free(sanitized_input);

    return 0;
}

char* sanitize_input(char* input_str)
{
    char* sanitized_str = malloc(MAX_INPUT_LENGTH * sizeof(char));
    int index = 0;

    for (int i = 0; i < strlen(input_str); i++)
    {
        if (isalpha(input_str[i]))
        {
            sanitized_str[index++] = tolower(input_str[i]);
        }
    }

    sanitized_str[index] = '\0';

    return sanitized_str;
}