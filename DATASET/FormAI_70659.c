//FormAI DATASET v1.0 Category: Benchmarking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000 // Define array size here

// Function to perform selection sort on the array
void selection_sort(int arr[])
{
    int i, j, min_index, temp;
    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        min_index = i;
        for (j = i + 1; j < ARRAY_SIZE; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

// Function to perform bubble sort on the array
void bubble_sort(int arr[])
{
    int i, j, temp;
    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        for (j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int i;
    int arr[ARRAY_SIZE];
    clock_t start, end;

    // Seed the random number generator
    srand(time(NULL));

    // Generate random integers and fill the array
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand();
    }

    // Perform selection sort and measure the time it takes
    start = clock();
    selection_sort(arr);
    end = clock();
    printf("Selection sort took %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Generate new random integers and fill the array again
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand();
    }

    // Perform bubble sort and measure the time it takes
    start = clock();
    bubble_sort(arr);
    end = clock();
    printf("Bubble sort took %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}