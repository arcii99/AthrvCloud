//FormAI DATASET v1.0 Category: Syntax parsing ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given string 
// is a valid variable name 
int isVariable(char *str)
{
    // First character must be an alphabet 
    if (!isalpha(str[0]))
        return 0;

    int len = strlen(str);
    for (int i = 1; i < len; i++)
        // Check if each character is alphanumeric or underscore 
        if (!isalnum(str[i]) && str[i] != '_')
            return 0;

    return 1;
}

// Function to parse a C syntax expression 
void parseExpression(char *expr)
{
    int len = strlen(expr);
    char* token = strtok(expr, " ");

    // Loop through each token in the expression 
    while (token != NULL)
    {
        // Determine the type of token 
        if (isVariable(token)) 
            printf("%s is a variable\n", token);
        else if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 || strcmp(token, "/") == 0)
            printf("%s is an operator\n", token);
        else if (strcmp(token, "{") == 0 || strcmp(token, "}") == 0 || strcmp(token, "(") == 0 || strcmp(token, ")") == 0)
            printf("%s is a bracket\n", token);
        else if (strcmp(token, ";") == 0)
            printf("%s is a semicolon\n", token);
        else if (strcmp(token, "=") == 0)
            printf("%s is an assignment operator\n", token);
        else if (strcmp(token, "int") == 0 || strcmp(token, "char") == 0 || strcmp(token, "float") == 0)
            printf("%s is a data type\n", token); 
        else
            printf("%s is an unknown token\n", token);

        // Get the next token 
        token = strtok(NULL, " ");
    }
}

// Main program 
int main()
{
    char expr[100];
    printf("Enter a C syntax expression: ");
    fgets(expr, 100, stdin);

    // Remove the newline character from fgets 
    expr[strcspn(expr, "\n")] = 0; 

    // Parse the expression 
    parseExpression(expr);

    return 0;
}