//FormAI DATASET v1.0 Category: Syntax parsing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    char input[100];
    printf("Please enter your C program code: \n");
    fgets(input, sizeof(input), stdin);

    char *token;
    char *delim = " ;\t\n";

    token = strtok(input, delim);

    while (token != NULL)
    {
        //checking if the token is a keyword
        if (strcmp(token, "return") == 0 || strcmp(token, "void") == 0 || strcmp(token, "int") == 0 || strcmp(token, "char") == 0 || strcmp(token, "float") == 0 || strcmp(token, "double") == 0)
        {
            printf("Keyword: %s\n", token);
        }
        //checking if the token is an identifier
        else if ((token[0] >= 'a' && token[0] <= 'z') || (token[0] >= 'A' && token[0] <= 'Z') || token[0] == '_')
        {
            bool valid = true;
            for (int i = 1; i < strlen(token); i++)
            {
                if (!((token[i] >= 'a' && token[i] <= 'z') || (token[i] >= 'A' && token[i] <= 'Z') || (token[i] >= '0' && token[i] <= '9') || token[i] == '_'))
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                printf("Identifier: %s\n", token);
            }
            else
            {
                printf("Invalid identifier: %s\n", token);
            }
        }
        //checking if the token is a constant
        else if (token[0] >= '0' && token[0] <= '9')
        {
            bool valid = true;
            for (int i = 1; i < strlen(token); i++)
            {
                if (!(token[i] >= '0' && token[i] <= '9'))
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                printf("Constant: %s\n", token);
            }
            else
            {
                printf("Invalid constant: %s\n", token);
            }
        }
        //checking if the token is an operator
        else if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 || strcmp(token, "/") == 0 || strcmp(token, "=") == 0 || strcmp(token, "==") == 0 || strcmp(token, "!=") == 0 || strcmp(token, ">") == 0 || strcmp(token, "<") == 0 || strcmp(token, ">=") == 0 || strcmp(token, "<=") == 0)
        {
            printf("Operator: %s\n", token);
        }
        //checking if the token is a delimiter
        else if (strcmp(token, "(") == 0 || strcmp(token, ")") == 0 || strcmp(token, "{") == 0 || strcmp(token, "}") == 0 || strcmp(token, ",") == 0 || strcmp(token, ";") == 0)
        {
            printf("Delimiter: %s\n", token);
        }
        else
        {
            printf("Unknown token: %s\n", token);
        }

        token = strtok(NULL, delim);
    }

    return 0;
}