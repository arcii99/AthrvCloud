//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Cryptic
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(void)
{
    char input[50];
    char sanitized[50];
    int i = 0;

    printf("Enter input to be sanitized:\n");
    fgets(input, 50, stdin);

    while(input[i])
    {
        if(isalpha(input[i]))
        {
            if(isupper(input[i]))
                sanitized[i] = tolower(input[i]);
            else
                sanitized[i] = input[i];
        }
        else if(isdigit(input[i]))
        {
            sanitized[i] = input[i];
        }
        else if(input[i] == '_' || input[i] == '-' || input[i] == '.')
        {
            sanitized[i] = input[i];
        }
        else
        {
            sanitized[i] = '_';
        }
        i++;
    }

    printf("Sanitized input: %s\n", sanitized);

    return 0;
}