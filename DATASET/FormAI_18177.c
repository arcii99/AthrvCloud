//FormAI DATASET v1.0 Category: Syntax parsing ; Style: light-weight
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main()
{
    char input[MAX_LENGTH];
    printf("Enter a valid C syntax: ");
    fgets(input, MAX_LENGTH, stdin);

    int length = strlen(input);

    // check for an opening curly brace
    if (input[0] != '{')
    {
        printf("Invalid C syntax! Opening curly brace is missing.\n");
        return 1;
    }

    // check for a closing curly brace
    if (input[length - 2] != '}' && input[length - 1] != ';')
    {
        printf("Invalid C syntax! Closing curly brace or semicolon is missing.\n");
        return 1;
    }

    // parse the syntax, checking for keywords
    char *keyword = strtok(input, " ,;()\n");
    while (keyword != NULL)
    {
        if (strcmp(keyword, "int") == 0 ||
            strcmp(keyword, "char") == 0 ||
            strcmp(keyword, "float") == 0 ||
            strcmp(keyword, "double") == 0 ||
            strcmp(keyword, "void") == 0)
        {
            printf("Keyword '%s' found.\n", keyword);
        }

        keyword = strtok(NULL, " ,;()\n");
    }

    // syntax is valid
    printf("C syntax is valid.\n");
    return 0;
}