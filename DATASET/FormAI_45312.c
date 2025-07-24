//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main()
{
    char input[MAX_SIZE];
    int count = 0;
    int i;

    printf("Enter a string:\n");
    fgets(input, MAX_SIZE, stdin);

    for (i = 0; i < strlen(input); ++i)
    {
        if (input[i] == '(')
        {
            ++count;
        }
        else if (input[i] == ')')
        {
            --count;
        }

        if (count < 0)
        {
            printf("Error: There are more ')' than '('.\n");
            return 1;
        }
    }

    if (count > 0)
    {
        printf("Error: There are more '(' than ')'.\n");
        return 1;
    }

    printf("Success: The parentheses in the string are balanced.\n");

    return 0;
}