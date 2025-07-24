//FormAI DATASET v1.0 Category: Sorting ; Style: brave
#include <stdio.h>
#include <stdlib.h>

/* Brave Sorting Example Program */
/* I will not apologize for my code */

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to perform quicksort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Select a pivot point
        int pivot = arr[high];

        // Initialize variables to partition array
        int i = (low - 1);
        int j;

        // Partition array
        for (j = low; j <= high - 1; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // Move pivot to its correct position
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        // Recursively sort sub-arrays
        quickSort(arr, low, i);
        quickSort(arr, i + 2, high);    
    }
}

// Main function
int main()
{
    int arr[] = {23, 56, 12, 45, 67, 43, 1, 90, 87, 32};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}