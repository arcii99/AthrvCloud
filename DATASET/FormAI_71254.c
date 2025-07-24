//FormAI DATASET v1.0 Category: Benchmarking ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main()
{
    int array[ARRAY_SIZE];
    int i, j, temp;

    // Initialize array with random values
    srand(time(NULL));
    for(i=0; i<ARRAY_SIZE; i++)
    {
        array[i] = rand() % 1000;
    }

    // Bubble Sort
    clock_t start_bubble_sort = clock();
    for(i=0; i<ARRAY_SIZE; i++)
    {
        for(j=0; j<ARRAY_SIZE-i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    clock_t end_bubble_sort = clock();
    printf("Bubble Sort Time: %f seconds\n", (double)(end_bubble_sort - start_bubble_sort) / CLOCKS_PER_SEC);

    // Quick Sort
    clock_t start_quick_sort = clock();
    quickSort(array, 0, ARRAY_SIZE-1);
    clock_t end_quick_sort = clock();
    printf("Quick Sort Time: %f seconds\n", (double)(end_quick_sort - start_quick_sort) / CLOCKS_PER_SEC);

    return 0;
}

void quickSort(int array[], int left, int right)
{
    int i = left;
    int j = right;
    int temp;
    int pivot = array[(left + right) / 2];

    while(i <= j)
    {
        while(array[i] < pivot)
        {
            i++;
        }

        while(array[j] > pivot)
        {
            j--;
        }

        if(i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }

    if(left < j)
    {
        quickSort(array, left, j);
    }

    if(i < right)
    {
        quickSort(array, i, right);
    }
}