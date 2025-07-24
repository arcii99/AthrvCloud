//FormAI DATASET v1.0 Category: Benchmarking ; Style: Linus Torvalds
#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 100000

// Function to populate array with random integers
void populate_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
}

// Function to print array
void print_array(int *arr, int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
        {
            printf(",");
        }
    }
    printf("]\n");
}

// Function to bubble sort array
void bubble_sort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to measure time taken by a function to execute
double measure_time(void (*func)(int*, int), int *arr, int size)
{
    clock_t start, end;
    double time_taken;
    start = clock();
    func(arr, size);
    end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    return time_taken;
}

int main()
{
    int arr[ARRAY_SIZE];
    populate_array(arr, ARRAY_SIZE);
    printf("Unsorted Array: ");
    print_array(arr, ARRAY_SIZE);

    double bubble_sort_time = measure_time(bubble_sort, arr, ARRAY_SIZE);
    printf("Sorted Array: ");
    print_array(arr, ARRAY_SIZE);
    printf("Time taken by bubble sort: %f seconds\n", bubble_sort_time);

    return 0;
}