//FormAI DATASET v1.0 Category: Syntax parsing ; Style: irregular
#include <stdio.h>
int main()
{
    printf("Hello, welcome to the ultimate C Syntax parsing program!\n\n");

    char arr[50];
    int i, j, varCount = 0, opCount = 0;

    printf("Enter a C program to parse:\n");
    scanf("%[^\n]%*c", arr);

    printf("\nParsing program...\n\n");

    for (i = 0; arr[i] != '\0'; i++)
    {
        if ((arr[i] == '=') && (arr[i+1] != '='))
        {
            varCount++;
            printf("Variable declaration: ");

            for (j = i-1; j >= 0; j--)
            {
                if ((arr[j] != ' ') && (arr[j] != '\t'))
                {
                    printf("%c", arr[j]);
                }
                else
                {
                    break;
                }
            }
            printf("\n");
        }

        if ((arr[i] == '+') || (arr[i] == '-') || (arr[i] == '*') || (arr[i] == '/') || (arr[i] == '%') || (arr[i] == '&') || (arr[i] == '|') || (arr[i] == '!') || (arr[i] == '<') || (arr[i] == '>'))
        {
            opCount++;
            printf("Operator: %c\n", arr[i]);
        }
    }

    printf("\nProgram parsed successfully!\n");
    printf("Total variables declared: %d\n", varCount);
    printf("Total operators found: %d\n", opCount);

    return 0;
}