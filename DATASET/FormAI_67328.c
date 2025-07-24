//FormAI DATASET v1.0 Category: Syntax parsing ; Style: immersive
#include <stdio.h>

int main()
{
    printf("Welcome to the Syntax Parser!\n\n");
    char input[100];
    printf("Enter your C code:\n");
    fgets(input, 100, stdin);

    int bracesCount = 0;
    int bracketsCount = 0;
    int parenthesesCount = 0;

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '{')
            bracesCount++;
        else if (input[i] == '}')
            bracesCount--;

        if (input[i] == '[')
            bracketsCount++;
        else if (input[i] == ']')
            bracketsCount--;

        if (input[i] == '(')
            parenthesesCount++;
        else if (input[i] == ')')
            parenthesesCount--;
        if (bracesCount < 0 || bracketsCount < 0 || parenthesesCount < 0)
        {
            printf("There is a syntax error in your code!\n");
            return 0;
        }
    }

    if (bracesCount != 0 || bracketsCount != 0 || parenthesesCount != 0)
    {
        printf("There is a syntax error in your code!\n");
        return 0;
    }

    printf("Your code is free of syntax errors!\n");
    return 0;
}