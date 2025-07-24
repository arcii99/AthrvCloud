//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    int i, j, len;
    int flag = 0;

    printf("Enter an expression: ");
    fgets(input, 100, stdin);

    len = strlen(input);

    for (i = 0; i < len; i++)
    {
        if (input[i] == '(')
        {
            flag++;
        }
        else if (input[i] == ')')
        {
            flag--;
        }
    }

    if (flag == 0)
    {
        printf("Valid expression\n");
    }
    else
    {
        printf("Invalid expression\n");
    }

    return 0;
}