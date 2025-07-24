//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

char *sanitize_input(char *input);

int main()
{
    char *input = (char *) malloc(MAX_INPUT_LENGTH * sizeof(char));
    
    printf("Enter a string: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    printf("Sanitized input: %s\n", sanitize_input(input));
    
    free(input);
    return 0;
}

char *sanitize_input(char *input)
{
    int length = strlen(input);
    char *sanitized_input = (char *) calloc(length, sizeof(char));
    int j = 0;
    
    for (int i = 0; i < length; i++)
    {
        if (isalnum(input[i]) || isspace(input[i]))
        {
            sanitized_input[j++] = input[i];
        }
    }
    
    return sanitized_input;
}