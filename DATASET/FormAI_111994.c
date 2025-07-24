//FormAI DATASET v1.0 Category: Benchmarking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

// A function to initialize the array with random values
void initialize_array(int arr[])
{
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = rand() % 1000;
    }
}

// A function to print the array
void print_array(int arr[])
{
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
}

// A function to bubble sort the array
void bubble_sort(int arr[])
{
    int i, j, temp;
    for(i = 0; i < ARRAY_SIZE - 1; i++)
    {
        for(j = 0; j < ARRAY_SIZE - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int arr[ARRAY_SIZE];

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the array with random values
    initialize_array(arr);

    printf("Before sorting:\n");
    print_array(arr);

    clock_t start = clock();

    // Sort the array using bubble sort
    bubble_sort(arr);

    printf("\n\nAfter sorting:\n");
    print_array(arr);

    printf("\n\nTime taken: %f seconds", (double)(clock() - start)/CLOCKS_PER_SEC);

    return 0;
}