//FormAI DATASET v1.0 Category: Sorting ; Style: Ken Thompson
#include <stdio.h>

int main()
{
    int numbers[10] = { 10, 8, 7, 5, 4, 3, 1, 2, 6, 9 };
    int i, j, temp;

    printf("Before sorting:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", numbers[i]);
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 9-i; j++)
        {
            if (numbers[j] > numbers[j+1])
            {
                temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }

    printf("\nAfter sorting:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", numbers[i]);
    }

    return 0;
}