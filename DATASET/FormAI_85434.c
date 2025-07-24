//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void parse(char* input);

int main()
{
    char input[50];

    printf("Enter an expression with operators +, -, *, /\n");
    scanf("%s", input);

    parse(input);

    return 0;
}

void parse(char* input)
{
    int i = 0;
    char c = input[0];

    // check if the input starts with a digit or a minus sign
    if (!isdigit(c) && c != '-')
    {
        printf("Invalid input!\n");
        return;
    }

    // check the rest of the input
    for (i = 1; input[i] != '\0'; i++)
    {
        c = input[i];
        if (!isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/')
        {
            printf("Invalid input!\n");
            return;
        }
    }

    printf("Valid input!\n");
}