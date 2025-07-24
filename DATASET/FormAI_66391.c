//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: grateful
#include <stdio.h>

#define ARRAY_SIZE 1000000

int main()
{
    int i, j, temp;
    int arr[ARRAY_SIZE];

    // populate array with random integers between 1 and 100
    for (i = 0; i < ARRAY_SIZE; i++)
        arr[i] = (rand() % 100) + 1;

    // bubble sort algorithm to sort array in ascending order
    for (i = 0; i < ARRAY_SIZE - 1; i++)
    {
        for (j = 0; j < ARRAY_SIZE - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // output sorted array
    for (i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", arr[i]);

    return 0;
}