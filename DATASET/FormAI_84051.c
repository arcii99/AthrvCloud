//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the constants for the program
#define MAX_ARRAY_SIZE 100000 // Maximum array size
#define MAX_RANDOM_NUM 100 // Maximum random number size
#define NUM_TESTS 10 // Number of tests to perform

// Define the function prototypes
void bubble_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void insertion_sort(int arr[], int n);

int main()
{
    int arr[MAX_ARRAY_SIZE]; // Array to hold random numbers
    int i, j; // Loop variables
    clock_t start, end; // Variables for measuring time
    double bubble_sort_time, selection_sort_time, insertion_sort_time; // Variables to hold execution time

    printf("Performance tests for sorting algorithms:\n\n");

    // Perform the tests NUM_TESTS times
    for(i=0; i<NUM_TESTS; i++)
    {
        printf("Test #%d\n", i+1);

        // Fill the array with random numbers
        srand(time(NULL));
        for(j=0; j<MAX_ARRAY_SIZE; j++)
        {
            arr[j] = rand() % MAX_RANDOM_NUM;
        }

        // Measure the execution time for bubble sort
        start = clock();
        bubble_sort(arr, MAX_ARRAY_SIZE);
        end = clock();
        bubble_sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;

        // Measure the execution time for selection sort
        start = clock();
        selection_sort(arr, MAX_ARRAY_SIZE);
        end = clock();
        selection_sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;

        // Measure the execution time for insertion sort
        start = clock();
        insertion_sort(arr, MAX_ARRAY_SIZE);
        end = clock();
        insertion_sort_time = ((double) (end - start)) / CLOCKS_PER_SEC;

        // Print out the execution times for the sorts
        printf("Bubble Sort: %f seconds\n", bubble_sort_time);
        printf("Selection Sort: %f seconds\n", selection_sort_time);
        printf("Insertion Sort: %f seconds\n", insertion_sort_time);
        printf("\n");
    }

    return 0;
}

// Function to perform bubble sort
void bubble_sort(int arr[], int n)
{
    int i, j, temp;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1; j++)
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

// Function to perform selection sort
void selection_sort(int arr[], int n)
{
    int i, j, min_index, temp;

    for(i=0; i<n-1; i++)
    {
        min_index = i;
        for(j=i+1; j<n; j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

// Function to perform insertion sort
void insertion_sort(int arr[], int n)
{
    int i, j, temp;

    for(i=1; i<n; i++)
    {
        temp = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}