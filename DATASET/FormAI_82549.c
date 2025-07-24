//FormAI DATASET v1.0 Category: Pattern printing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, i, j, count = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for(i = 1; i <= rows; i++)
    {
        for(j = 1; j <= i; j++)
        {
            printf("%d ", j);
        }
        count++; // Increment count after each row printed

        // After printing 5 rows, start printing rows in reverse order
        if(count == 5)
        {
            for(j = i-1; j >= 1; j--)
            {
                printf("%d ", j);
            }
            count = 0; // Reset the count for next batch of 5 rows
        }
        printf("\n");
    }

    return 0;
}