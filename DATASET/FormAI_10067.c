//FormAI DATASET v1.0 Category: Benchmarking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000000

int main()
{
    int array[ARRAY_SIZE];
    int i, j;
    clock_t start, end;
    double insertion_sort_time, bubble_sort_time; 
    
    // Filling the array with random numbers
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = rand();
    }

    printf("Array of %d elements created.\n", ARRAY_SIZE);
    
    // Insertion sort
    printf("\nSorting array with Insertion Sort...\n");
    start = clock();
    for(i = 1; i < ARRAY_SIZE; i++)
    {
        int temp = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > temp)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }
    end = clock();
    insertion_sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Array sorted with Insertion Sort in %f seconds.\n", insertion_sort_time);
    
    // Bubble sort
    printf("\nSorting array with Bubble Sort...\n");
    start = clock();
    for(i = 0; i < ARRAY_SIZE; i++)
    {
        for(j = 0; j < ARRAY_SIZE-i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    end = clock();
    bubble_sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Array sorted with Bubble Sort in %f seconds.\n", bubble_sort_time);
    
    // Comparison of sorting time
    printf("\nComparison of Sorting Time:\n");
    if(insertion_sort_time < bubble_sort_time)
    {
        printf("Insertion Sort is Faster.\n");
    }
    else if(insertion_sort_time > bubble_sort_time)
    {
        printf("Bubble Sort is Faster.\n");
    }
    else
    {
        printf("Both Sorting Algorithms have the same time.\n");
    }
    
    return 0;
}