//FormAI DATASET v1.0 Category: Benchmarking ; Style: detailed
#include <stdio.h>
#include <time.h>

#define MAX 1000000 // Maximum size of the array
#define ITERATIONS 10 // Number of iterations for benchmarking

/* Function to swap two elements */
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to perform bubble sort */
void bubble_sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

/* Function to perform insertion sort */
void insertion_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int i,j;
    double bubble_sort_time=0, insertion_sort_time=0; // Time variables to store benchmarking results

    srand(time(NULL)); // Initializing random number generator with current time
    int arr[MAX]; // Array to be sorted
    
    // Generating random numbers to populate the array
    for(i=0;i<MAX;i++)
        arr[i]=rand();

    printf("Benchmarking Bubble Sort and Insertion Sort for an array size of %d\n", MAX);

    // Benchmarking Bubble sort
    printf("Benchmarking Bubble Sort for %d iterations...\n", ITERATIONS);
    for(i=0;i<ITERATIONS;i++)
    {
        clock_t start = clock(); // Starting timer
        bubble_sort(arr, MAX);
        clock_t end = clock(); // Ending timer
        bubble_sort_time += ((double) (end - start)) / CLOCKS_PER_SEC; // Calculating time taken by Bubble sort
    }
    printf("Average time taken by Bubble Sort: %lf seconds\n", bubble_sort_time/ITERATIONS);

    // Benchmarking Insertion sort
    printf("Benchmarking Insertion Sort for %d iterations...\n", ITERATIONS);
    for(j=0;j<ITERATIONS;j++)
    {
        clock_t start = clock(); // Starting timer
        insertion_sort(arr, MAX);
        clock_t end = clock(); // Ending timer
        insertion_sort_time += ((double) (end - start)) / CLOCKS_PER_SEC; // Calculating time taken by Insertion sort
    }
    printf("Average time taken by Insertion Sort: %lf seconds\n", insertion_sort_time/ITERATIONS);

    return 0;
}