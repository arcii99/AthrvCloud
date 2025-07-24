//FormAI DATASET v1.0 Category: Benchmarking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000000
#define MAX_VALUE 1000

int main()
{
    int i;
    int arr[ARRAY_SIZE];

    /* Initialize array with random values */
    srand(time(NULL));
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = rand() % MAX_VALUE;
    }

    /* Sort array using bubble sort */
    clock_t start = clock();
    int temp, j, k;
    for(j = 0; j < ARRAY_SIZE-1; j++)
    {
        for(k = 0; k < ARRAY_SIZE-j-1; k++)
        {
            if(arr[k] > arr[k+1])
            {
                temp = arr[k];
                arr[k] = arr[k+1];
                arr[k+1] = temp;
            }
        }
    }
    clock_t end = clock();

    printf("Sorted array of size %d in %f seconds\n", ARRAY_SIZE, ((double) (end - start)) / CLOCKS_PER_SEC);

    return 0;
}