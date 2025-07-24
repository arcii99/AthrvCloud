//FormAI DATASET v1.0 Category: Pattern printing ; Style: real-life
#include <stdio.h>

int main()
{
    int size, i, j, k, l;

    printf("Enter the size of the pattern: ");
    scanf("%d", &size);

    // Printing upper left half of pattern
    for(i = 0; i < size; i++)
    {
        for(j = 0; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    // Printing upper right half of pattern
    for(k = 1; k < size; k++)
    {
        for(l = size - k; l > 0; l--)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}