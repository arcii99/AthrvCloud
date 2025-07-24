//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: modular
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

void sanitize(char*);

int main(void)
{
    char input[MAX_INPUT_SIZE];
    
    printf("Enter your input: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    
    //remove newline character from input string
    input[strcspn(input, "\n")] = '\0';
    
    sanitize(input);
    
    printf("Sanitized input: %s\n", input);
    
    return 0;
}

void sanitize(char* input)
{
    int i, j;
    
    //convert all characters to lowercase
    for(i = 0; input[i]; i++)
    {
        input[i] = tolower(input[i]);
    }
    
    //replace all non-alphanumeric characters with spaces
    for(i = 0, j = 0; input[i]; i++, j++)
    {
        if(isalnum(input[i]))
        {
            input[j] = input[i];
        }
        else
        {
            input[j] = ' ';
        }
    }
    
    //remove any multiple spaces
    for(i = 0; input[i]; i++)
    {
        if(input[i] == ' ' && input[i+1] == ' ')
        {
            for(j = i; input[j]; j++)
            {
                input[j] = input[j+1];
            }
            i--;
        }
    }
}