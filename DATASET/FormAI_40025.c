//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

char* sanitize_input(char*);

int main()
{
    char input[MAX_INPUT_LENGTH];
    printf("Please enter a string: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    char* sanitized_input = sanitize_input(input);

    printf("The sanitized input is: %s\n", sanitized_input);
    
    free(sanitized_input);
    return 0;
}

char* sanitize_input(char* input)
{
    int input_length = strlen(input);
    char* sanitized_input = (char*) malloc(sizeof(char) * input_length);
    
    int sanitized_index = 0;

    for(int i = 0; i < input_length; i++)
    {
        // skip non-alpha numeric characters except whitespaces
        if(!isalnum(input[i]) && !isspace(input[i]))
            continue;

        // convert uppercase characters to lowercase
        if(isupper(input[i]))
            sanitized_input[sanitized_index++] = tolower(input[i]);
        else
            sanitized_input[sanitized_index++] = input[i];
    }

    sanitized_input[sanitized_index] = '\0';

    return sanitized_input;
}