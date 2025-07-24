//FormAI DATASET v1.0 Category: Benchmarking ; Style: post-apocalyptic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_ARR_SIZE 1000000

int main()
{
    int arr[MAX_ARR_SIZE];
    int i, j, temp, n = MAX_ARR_SIZE;

    // genearte random array values
    srand(time(NULL));
    for(i=0; i<n; i++)
        arr[i] = rand()%1000;

    // Bubble Sort
    clock_t start = clock();
    for(i=0; i<n-1; i++)
        for(j=0; j<n-i-1; j++)
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
    clock_t end = clock();

    double elapsed_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted Array: ");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);

    printf("\nElapsed Time: %f seconds", elapsed_time);

    return 0;
}