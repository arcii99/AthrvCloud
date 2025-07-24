//FormAI DATASET v1.0 Category: Syntax parsing ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char input[100], output[100];
    int i,j;

    printf("Please type a line of C Syntax code: ");
    fgets(input, sizeof(input), stdin);

    for(i = 0, j = 0; i < strlen(input); i++)
    {
        if(input[i] == '{' || input[i] == '}' || input[i] == ';' || input[i] == '(' || input[i] == ')' || input[i] == ',' || input[i] == '=')
        {
            output[j++] = ' ';
            output[j++] = input[i];
            output[j++] = ' ';
        }
        else
        {
            output[j++] = input[i];
        }
    }

    output[j] = '\0';

    printf("Parsed Output: %s", output);

    return 0;
}