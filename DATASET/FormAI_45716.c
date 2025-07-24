//FormAI DATASET v1.0 Category: Benchmarking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Welcome message
    printf("Welcome to the Medieval Benchmarking Program!\n\n");

    // Setting up variables and arrays
    int array[1000];
    int size = sizeof(array)/sizeof(array[0]);

    srand(time(NULL));

    // Populating array with random numbers between 1 and 100
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 100 + 1;
    }

    // Sorting array using Bubble Sort algorithm
    clock_t start_bubble_sort = clock();
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    clock_t end_bubble_sort = clock();

    // Displaying sorted array
    printf("Sorted Array:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Calculating and displaying bubble sort time
    double time_bubble_sort = (double)(end_bubble_sort - start_bubble_sort) / CLOCKS_PER_SEC;
    printf("Time for Bubble Sort: %lf seconds\n\n", time_bubble_sort);

    // Sorting array using Quick Sort algorithm
    clock_t start_quick_sort = clock();
    quickSort(array, 0, size - 1);
    clock_t end_quick_sort = clock();

    // Displaying sorted array
    printf("Sorted Array:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Calculating and displaying quick sort time
    double time_quick_sort = (double)(end_quick_sort - start_quick_sort) / CLOCKS_PER_SEC;
    printf("Time for Quick Sort: %lf seconds\n\n", time_quick_sort);

    // Checking which algorithm performed better
    if (time_bubble_sort < time_quick_sort)
    {
        printf("Bubble Sort is faster than Quick Sort.\n");
    }
    else if (time_bubble_sort > time_quick_sort)
    {
        printf("Quick Sort is faster than Bubble Sort.\n");
    }
    else
    {
        printf("Both Bubble Sort and Quick Sort took the same time.\n");
    }

    // Farewell message
    printf("\nThank you for using the Medieval Benchmarking Program!\n");

    return 0;
}

// Quick Sort algorithm
void quickSort(int array[], int low, int high)
{
    int i = low;
    int j = high;
    int pivot = array[(low + high) / 2];

    while (i <= j)
    {
        while (array[i] < pivot)
        {
            i++;
        }

        while (array[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;

            i++;
            j--;
        }
    }

    if (low < j)
    {
        quickSort(array, low, j);
    }

    if (i < high)
    {
        quickSort(array, i, high);
    }
}