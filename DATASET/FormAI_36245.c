//FormAI DATASET v1.0 Category: Syntax parsing ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPRESSION_LENGTH 100

int main()
{
    // Define the input expression
    char expression[MAX_EXPRESSION_LENGTH];
    
    // Get the input from the user
    printf("Enter the expression: ");
    fgets(expression, MAX_EXPRESSION_LENGTH, stdin);
    
    // Define the variables to be used in parsing
    int i = 0;
    int open_parens = 0;
    int close_parens = 0;
    int double_quotes = 0;
    int single_quotes = 0;

    // Loop through the input expression and parse the syntax
    while (expression[i] != '\0')
    {
        switch (expression[i])
        {
            case '(':
                open_parens++;
                break;
            case ')':
                close_parens++;
                break;
            case '\"':
                double_quotes++;
                break;
            case '\'':
                single_quotes++;
                break;
            default:
                break;
        }

        // Check for syntax errors
        if (close_parens > open_parens)
        {
            printf("Syntax error: extra close parentheses\n");
            exit(1);
        }
        else if (double_quotes % 2 != 0)
        {
            printf("Syntax error: mismatched double quotes\n");
            exit(1);
        }
        else if (single_quotes % 2 != 0)
        {
            printf("Syntax error: mismatched single quotes\n");
            exit(1);
        }

        i++;
    }

    // Check for final syntax errors
    if (open_parens != close_parens)
    {
        printf("Syntax error: mismatched parentheses\n");
        exit(1);
    }
    else if (double_quotes % 2 != 0)
    {
        printf("Syntax error: mismatched double quotes\n");
        exit(1);
    }
    else if (single_quotes % 2 != 0)
    {
        printf("Syntax error: mismatched single quotes\n");
        exit(1);
    }
    else
    {
        printf("Syntax is correct\n");
    }

    return 0;
}