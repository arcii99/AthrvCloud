//FormAI DATASET v1.0 Category: Syntax parsing ; Style: futuristic
/* Welcome to the Syntax Parsing program of the future! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Our parser will use a stack to keep track of nested syntax elements */
char stack[100];
int top = -1;

int main()
{
    // Example expression to parse
    char expression[] = "x = 5 * (2 + 3)";

    // Tokenize the expression
    char* token = strtok(expression, " ");
    while (token != NULL)
    {
        // Check if token is an opening parenthesis
        if (strcmp(token, "(") == 0)
        {
            // Push opening parenthesis onto the stack
            stack[++top] = '(';
        }

        // Check if token is a closing parenthesis
        else if (strcmp(token, ")") == 0)
        {
            // Pop stack until matching opening parenthesis is found
            while (top != -1 && stack[top] != '(')
            {
                top--;
            }

            if (top == -1)
            {
                // Syntax error: unmatched closing parenthesis
                printf("Error: unmatched closing parenthesis\n");
                return -1;
            }

            // Pop opening parenthesis from stack
            top--;
        }

        // Check if token is an operator
        else if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
                 strcmp(token, "*") == 0 || strcmp(token, "/") == 0)
        {
            // Push operator onto stack
            stack[++top] = token[0];
        }

        // Check if token is an identifier
        else if (isalpha(token[0]))
        {
            // Do nothing, identifier is valid syntax element
        }

        // Check if token is a literal value
        else if (isdigit(token[0]))
        {
            // Do nothing, literal value is valid syntax element
        }

        // Syntax error: unrecognized token
        else
        {
            printf("Error: unrecognized token\n");
            return -1;
        }

        // Get next token
        token = strtok(NULL, " ");
    }

    // Check for unmatched opening parenthesis
    if (top != -1)
    {
        printf("Error: unmatched opening parenthesis\n");
        return -1;
    }

    // Syntax is valid!
    printf("Syntax is valid!\n");
    return 0;
}