//FormAI DATASET v1.0 Category: Benchmarking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //Seed the random number generator with the current time
    int array_size = 100000;
    int numbers[array_size];

    //Initialize the array with random numbers between 0 and 99999
    for(int i = 0; i < array_size; i++)
    {
        numbers[i] = rand() % 100000;
    }

    clock_t start_clock, end_clock;
    double start_time, end_time, total_time;

    //Measure the sorting time for the bubble sort algorithm
    start_clock = clock();
    start_time = ((double)start_clock)/CLOCKS_PER_SEC;

    //Bubble Sort Algorithm
    for(int i = 0; i < array_size - 1; i++)
    {
        for(int j = 0; j < array_size - i - 1; j++)
        {
            if(numbers[j] > numbers[j+1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }

    end_clock = clock();
    end_time = ((double)end_clock)/CLOCKS_PER_SEC;
    total_time = end_time - start_time;

    printf("Sorting time for bubble sort algorithm: %lf seconds\n", total_time);

    //Measure the sorting time for the quicksort algorithm
    start_clock = clock();
    start_time = ((double)start_clock)/CLOCKS_PER_SEC;

    //Quicksort Algorithm
    quicksort(numbers, 0, array_size-1);

    end_clock = clock();
    end_time = ((double)end_clock)/CLOCKS_PER_SEC;
    total_time = end_time - start_time;

    printf("Sorting time for quicksort algorithm: %lf seconds\n", total_time);

    return 0;
}

void quicksort(int array[], int low, int high)
{
    if(low < high)
    {
        int partition_index = partition(array, low, high);
        quicksort(array, low, partition_index-1);
        quicksort(array, partition_index+1, high);
    }
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i+1];
    array[i+1] = array[high];
    array[high] = temp;
    return i+1;
}