//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: active
#include <stdio.h>
#include <time.h>

#define SIZE 10000

int main()
{
    int array[SIZE];
    int i, j, temp;
    clock_t start, end;
    double cpu_time_used;

    // initialize array in reverse order
    for (i = 0; i < SIZE; i++)
    {
        array[i] = SIZE - i;
    }

    // perform bubble sort
    start = clock();
    for (i = 0; i < SIZE - 1; i++)
    {
        for (j = 0; j < SIZE - i - 1; j++)
        {
            if (array[j] > array[j+1])
            {
                // swap elements
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    end = clock();

    // calculate CPU time used in seconds
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // print sorted array and CPU time used
    printf("Sorted array:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n\nCPU time used: %f seconds", cpu_time_used);

    return 0;
}