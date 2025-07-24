//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize the array
void initializeArray(int arr[], int n)
{
    srand(time(NULL)); // Set seed for random number generator
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100; // Assign random values between 0-99
    }
}

// Function to print the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to implement Bubble Sort algorithm
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    const int n = 50;
    int arr[n];
    
    // Initialize and print unsorted array
    initializeArray(arr, n);
    printf("Unsorted Array:\n");
    printArray(arr, n);
    
    // Sort and print sorted array
    bubbleSort(arr, n);
    printf("Sorted Array:\n");
    printArray(arr, n);
    
    return 0;
}