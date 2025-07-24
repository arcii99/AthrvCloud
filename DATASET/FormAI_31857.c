//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: careful
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to sanitize the user input
char* sanitize_input(char* input) 
{
    int i, j;
    char* sanitized = (char*)malloc(strlen(input) + 1);

    j = 0;
    for(i = 0; input[i] != '\0'; i++)
    {
        // ignore leading white spaces
        while(input[i] == ' ')
            i++;
        // convert alphabetic characters to lowercase
        if(isalpha(input[i]))
            sanitized[j++] = tolower(input[i]);
        // ignore non-alphanumeric characters
        else if(isalnum(input[i]))
            sanitized[j++] = input[i];
    }
    sanitized[j] = '\0';
    return sanitized;
}

int main() 
{
    char input[100];

    // accept user input
    printf("Enter your input: ");
    fgets(input, 100, stdin);

    // sanitize the user input
    char* sanitized_input = sanitize_input(input);

    // display the sanitized input
    printf("Sanitized input: %s", sanitized_input);

    // free the dynamically allocated memory
    free(sanitized_input);

    return 0;
}