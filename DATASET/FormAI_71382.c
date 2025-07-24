//FormAI DATASET v1.0 Category: Educational ; Style: rigorous
#include <stdio.h>

#define MAX 10

int main()
{
    int arr[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i, j, temp;

    // print original array
    printf("Original array: ");
    for (i = 0; i < MAX; i++)
    {
        printf("%d ", arr[i]);
    }

    // bubble sort algorithm
    for (i = 0; i < MAX-1; i++)
    {
        for (j = 0; j < MAX-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                // swap elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // print sorted array
    printf("\nSorted array: ");
    for (i = 0; i < MAX; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}