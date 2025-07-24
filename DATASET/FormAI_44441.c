//FormAI DATASET v1.0 Category: Syntax parsing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Constants */
#define MAX_LENGTH 255
#define OPEN_BRACKET '('
#define CLOSE_BRACKET ')'
#define OPEN_BRACE '{'
#define CLOSE_BRACE '}'
#define OPEN_SQUARE '['
#define CLOSE_SQUARE ']'

/* Function declarations */
bool is_valid_syntax(char* expression);

/* Main function */
int main()
{
    char expression[MAX_LENGTH];
    printf("Enter a C syntax expression: ");
    fgets(expression, MAX_LENGTH, stdin);

    if(is_valid_syntax(expression))
        printf("The C syntax expression is valid.");
    else
        printf("The C syntax expression is invalid.");

    return 0;
}

/* Function to check for valid syntax */
bool is_valid_syntax(char* expression)
{
    int length = strlen(expression);
    char stack[length];
    int top = -1;

    for(int i = 0; i < length; i++)
    {
        char current_char = expression[i];

        if(current_char == OPEN_BRACKET || current_char == OPEN_BRACE || current_char == OPEN_SQUARE)
        {
            stack[++top] = current_char;
        }

        else if(current_char == CLOSE_BRACKET || current_char == CLOSE_BRACE || current_char == CLOSE_SQUARE)
        {
            if(top == -1)
                return false;

            char last_char = stack[top--];

            if(current_char == CLOSE_BRACKET && last_char != OPEN_BRACKET)
                return false;
            else if(current_char == CLOSE_BRACE && last_char != OPEN_BRACE)
                return false;
            else if(current_char == CLOSE_SQUARE && last_char != OPEN_SQUARE)
                return false;
        }
    }

    if(top == -1)
        return true;

    return false;
}