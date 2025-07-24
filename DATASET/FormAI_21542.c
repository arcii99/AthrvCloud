//FormAI DATASET v1.0 Category: Benchmarking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// Function that generates a random array of integers
void generate_random_array(int *array)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = rand();
    }
}

// Function that sorts an array of integers using bubble sort algorithm
void bubble_sort(int *array)
{
    for (int i = 0; i < ARRAY_SIZE - 1; i++)
    {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Function that measures the time it takes to sort an array using bubble sort algorithm
void measure_bubble_sort_time()
{
    int array[ARRAY_SIZE];
    generate_random_array(array);
    
    clock_t start = clock();
    bubble_sort(array);
    clock_t end = clock();
    
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble sort took %f seconds to sort %d integers.\n", time_taken, ARRAY_SIZE);
}

int main()
{
    measure_bubble_sort_time();
    return 0;
}