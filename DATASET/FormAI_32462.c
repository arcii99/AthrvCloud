//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sanitize_input(char *input);

int main()
{
    char input[100];
    printf("Enter your input: ");
    fgets(input, 100, stdin);
    sanitize_input(input);
    printf("Sanitized input: %s", input);
    return 0;
}

void sanitize_input(char *input)
{
    int i, j;
    for (i = 0, j = 0; i <= strlen(input); i++, j++)
    {
        if (input[i] == '\n') 
        {
            input[j] = '\0';
            break;
        } 
        else if (isalpha(input[i]) || isdigit(input[i]) || input[i] == ' ')
        {
            input[j] = input[i];
        } 
        else 
        {
            j--;
        }
    }
}