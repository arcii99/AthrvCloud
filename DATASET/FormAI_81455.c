//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000
#define MAX_NUMBER 100

int compare(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int array[ARRAY_SIZE];
    int i, j, temp;
    double bubble_time, qsort_time;

    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = rand() % MAX_NUMBER;
    }

    // Bubble Sort
    clock_t start = clock();
    for (i = 0; i < ARRAY_SIZE - 1; i++)
    {
        for (j = 0; j < ARRAY_SIZE - i - 1; j++)
        {
            if (array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    clock_t end = clock();
    bubble_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Quick Sort
    start = clock();
    qsort(array, ARRAY_SIZE, sizeof(int), compare);
    end = clock();
    qsort_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Bubble Sort: %.6fs\n", bubble_time);
    printf("Quick Sort: %.6fs\n", qsort_time);

    return 0;
}