//FormAI DATASET v1.0 Category: Pattern printing ; Style: protected
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, i, j, count = 0, k = 0;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    for (i = 1; i <= rows; ++i) 
    {
        for (j = 1; j <= i; ++j) 
        {
            if (count % 2 == 0) 
            {
                printf("* ");
            } 
            else 
            {
                printf("# ");
            }
            ++count;
        }
        count = 0;
        if (i % 2 == 0) 
        {
            k = 1;
        }
        for (j = i + 1; j <= rows; ++j) 
        {
            if (k % 2 == 0) 
            {
                printf("# ");
            } 
            else 
            {
                printf("* ");
            }
            ++k;
        }
        k = 0;
        printf("\n");
    }
    return 0;
}