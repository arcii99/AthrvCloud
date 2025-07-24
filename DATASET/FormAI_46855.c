//FormAI DATASET v1.0 Category: Benchmarking ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int array_size = 1000000;
    int array[array_size];
    int i, j, temp;

    for (i = 0; i < array_size; i++)
    {
        array[i] = rand() % 1000000;
    }

    printf("Sorting the array using bubble sort algorithm...\n");
    clock_t start = clock();

    for (i = 0; i < array_size - 1 ; i++)
    {
        for (j = 0; j < array_size - i - 1; j++)
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
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");

    for (i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);

        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }

    printf("\nTime taken to sort: %f seconds\n", time_spent);
    return 0;
}