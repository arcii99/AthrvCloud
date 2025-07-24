//FormAI DATASET v1.0 Category: Syntax parsing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[1000];
    char tokens[50][50];
    int i, j = 0, k = 0, len;

    printf("Enter a C program to parse: ");
    fgets(input, 1000, stdin);
    len = strlen(input);

    for (i = 0; i < len; i++)
    {
        if (input[i] == ' ' || input[i] == '\n' || input[i] == '\t')
        {
            tokens[j][k] = '\0';
            j++;
            k = 0;
        }
        else
        {
            tokens[j][k] = input[i];
            k++;
        }
    }

    printf("\nTokens are:\n");
    for (i = 0; i < j; i++)
    {
        printf("%s\n", tokens[i]);
    }

    return 0;
}