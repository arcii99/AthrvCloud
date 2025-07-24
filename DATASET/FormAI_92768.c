//FormAI DATASET v1.0 Category: Benchmarking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// Function to generate random integers
void generate_random_ints(int arr[])
{
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = rand() % 1000;
    }
}

// Function to bubble sort an array
void bubble_sort(int arr[])
{
    int temp;
    for (int i = 0; i < ARRAY_SIZE - 1; i++)
    {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    // Generate an array of random integers
    int arr[ARRAY_SIZE];
    generate_random_ints(arr);

    // Benchmarking bubble sort algorithm
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    bubble_sort(arr);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble sort took %lf seconds to sort an array of size %d!\n", cpu_time_used, ARRAY_SIZE);

    return 0;
}