//FormAI DATASET v1.0 Category: Sorting ; Style: medieval
#include <stdio.h>

int main()
{
    int arr[10] = {4, 2, 8, 5, 1, 7, 3, 6, 10, 9};
    int i, j, temp, n = 10;

    printf("Before Sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Medieval Sorting Begins...
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Sword Swapping Technique...
                printf("\nKnight 1 swaps his sword with Knight 2's sword...\n");
                
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                printf("Knight 2 gives his sword to Knight 1...\n");
            }
            else
            {
                // Knights shake hands...
                printf("\nKnight 1 shakes hands with Knight 2...\n");
            }
        }
        // Knights Celebrate after each iteration...
        printf("\nKnights Celebrate the Victory after the %dth Battle\n", i+1);
        printf("----------------------------------------------------\n");
    }

    printf("\nAfter Sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}