//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

int main()
{
    int arr[N];

    // Initialize the array with random values
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand();
    }

    // Find the maximum value in the array
    int max = arr[0];
    for (int i = 1; i < N; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    printf("The maximum value in the array is: %d\n", max);

    return 0;
}