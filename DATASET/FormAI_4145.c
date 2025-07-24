//FormAI DATASET v1.0 Category: Text processing ; Style: immersive
#include <stdio.h>
#include <string.h>

/* Function prototype declaration */

void printPattern(char* str, int len);

int main()
{
    char str[] = "We love C programming";
    int len = strlen(str);

    /* Call the function */
    printPattern(str, len);

    return 0;
}

/* Function definition */

void printPattern(char* str, int len)
{
    int i, j;

    /* Outer loop to print each character of string */
    for (i = 0; i < len; i++)
    {
        printf("%c\t", str[i]);

        /* Inner loop to print each character before the current one */
        for (j = 0; j < i; j++)
        {
            printf("%c\t", str[j]);
        }
        printf("\n"); // Move to next line
    }
}