//FormAI DATASET v1.0 Category: Pattern printing ; Style: introspective
#include <stdio.h>

int main() {
    printf("Hello there! I am a C program that prints a unique pattern.\n");

    int i, j, k;

    //First half of pattern
    for (i = 1; i <= 4; i++) 
    {
        for (j = 1; j <= 4 - i; j++)
        {
            printf("  "); //Prints a space if i is less than 4-i
        }
        for (k = 1; k <= (2 * i - 1); k++)
        {
            if (k == 1 || k == (2 * i - 1)) //Prints * if k is the first or last index
            {
                printf("* ");
            }
            else
            {
                printf("  "); //Prints space if k is not first or last index
            }
        }
        printf("\n");
    }

    //Second half of pattern
    for (i = 3; i >= 1; i--)
    {
        for (j = 1; j <= 4 - i; j++)
        {
            printf("  "); //Prints a space if i is less than 4-i
        }
        for (k = 1; k <= (2 * i - 1); k++)
        {
            if (k == 1 || k == (2 * i - 1)) //Prints * if k is the first or last index
            {
                printf("* ");
            }
            else
            {
                printf("  "); //Prints space if k is not first or last index
            }
        }
        printf("\n");
    }

    return 0;
}