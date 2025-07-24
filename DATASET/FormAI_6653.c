//FormAI DATASET v1.0 Category: Sorting ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Function to print array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to swap two variables
void swap(int *xp, int *yp) 
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Bubble sort function
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)      
        for (int j = 0; j < n-i-1; j++) 
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

// Selection sort function
void selectionSort(int arr[], int n)
{ 
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) 
    {
        // Find the minimum element in the unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

// Main function
int main()
{
    int arr[] = {64, 34, 25, 67, 12, 22, 11, 90, 87, 56};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, n);

    printf("Array sorted with Bubble Sort: ");
    bubbleSort(arr, n);
    printArray(arr, n);

    printf("Array sorted with Selection Sort: ");
    selectionSort(arr, n);
    printArray(arr, n);

    return 0;
}