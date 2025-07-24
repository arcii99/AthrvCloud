//FormAI DATASET v1.0 Category: Pattern printing ; Style: surprised
#include <stdio.h>

int main()
{
    int size = 11;
    int row, col, mid = size / 2, count = 1;

    printf("Oh my gosh! Check out this amazing pattern that I came up with:\n\n");

    for (row = 0; row < size; row++)
    {
        for (col = 0; col < size; col++)
        {
            if (col == mid || row == mid || col == 0 && row <= mid || row == size-1 && col <= mid)
            {
                printf("* ");
            }
            else if (row == 0 && col > mid || col == size-1 && row <= mid || row == size-1 && col > mid || col == 0 && row > mid)
            {
                printf("| ");
            }
            else if (row > mid)
            {
                printf("+ ");
            }
            else
            {
                printf("  ");
            }
        }

        if (row < mid)
        {
            count++;
        }
        else
        {
            count--;
        }

        printf("\n");
    }

    printf("\nWowza, pretty impressive, huh?\n");

    return 0;
}