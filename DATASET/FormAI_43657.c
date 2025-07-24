//FormAI DATASET v1.0 Category: Syntax parsing ; Style: random
#include<stdio.h>
#include<stdlib.h>

void printWelcomeMessage()
{
    printf("Welcome to my unique C syntax parsing program!\n");
}

int main()
{
    printWelcomeMessage();

    char inputString[100];
    printf("Please enter a C program:\n");
    fgets(inputString, 100, stdin);

    int bracesCount = 0;
    int bracketsCount = 0;
    int parenthesesCount = 0;
    int inputFileLineCount = 1;
    int inputStringLength = strlen(inputString);

    for(int i=0; i<inputStringLength; i++)
    {
        if(inputString[i] == '{')
        {
            bracesCount++;
        }
        else if(inputString[i] == '}')
        {
            bracesCount--;
        }
        else if(inputString[i] == '[')
        {
            bracketsCount++;
        }
        else if(inputString[i] == ']')
        {
            bracketsCount--;
        }
        else if(inputString[i] == '(')
        {
            parenthesesCount++;
        }
        else if(inputString[i] == ')')
        {
            parenthesesCount--;
        }
        else if(inputString[i] == '\n')
        {
            inputFileLineCount++;
        }
    }

    if(bracesCount == 0 && bracketsCount == 0 && parenthesesCount == 0)
    {
        printf("Congratulations! The syntax is correct.\n");
        printf("The program has %d lines.\n", inputFileLineCount);
    }
    else
    {
        printf("Unfortunately, the syntax is incorrect.\n");
        printf("There are %d unmatched braces, %d unmatched brackets, and %d unmatched parentheses.\n", bracesCount, bracketsCount, parenthesesCount);
    }

    return 0;
}