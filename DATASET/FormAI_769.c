//FormAI DATASET v1.0 Category: Syntax parsing ; Style: careful
#include<stdio.h>
#include<string.h>

int main()
{
    char input[100];
    int i;

    printf("Enter a C code snippet: ");
    gets(input);

    int len = strlen(input);
    int brackets = 0, semicolons = 0, braces = 0;

    for(i=0; i<len; i++)
    {
        if(input[i] == '{')
            braces++;
        else if(input[i] == '}')
            braces--;
        else if(input[i] == '(')
            brackets++;
        else if(input[i] == ')')
            brackets--;
        else if(input[i] == ';')
            semicolons++;
    }

    if(braces == 0 && brackets == 0 && semicolons > 0) 
        printf("The code is valid!");
    else
        printf("The code is not valid.");

    return 0;
}