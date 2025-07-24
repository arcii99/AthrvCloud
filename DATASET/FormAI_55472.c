//FormAI DATASET v1.0 Category: Sorting ; Style: genious
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Quick Sort algorithm to sort an array in ascending order
 * 
 * @param arr Pointer to the array to be sorted
 * @param start Index of the first element of the array
 * @param end Index of the last element of the array
 */
void quickSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int pivot = arr[start]; // Selecting the first element as pivot
        int i = start + 1;      // Starting with the second element

        for (int j = start + 1; j <= end; j++)
        {
            if (arr[j] < pivot) // If current element is smaller than the pivot
            {
                // Swap current element with the element at the i-th position
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                i++;
            }
        }

        // Swap the pivot element with the element at the (i-1)-th position
        int temp = arr[start];
        arr[start] = arr[i - 1];
        arr[i - 1] = temp;

        // Recursive call to sort the left and right sub-arrays
        quickSort(arr, start, i - 2);
        quickSort(arr, i, end);
    }
}

/**
 * @brief Function to print the contents of an array
 * 
 * @param arr Pointer to the array to be printed
 * @param size Size of the array
 */
void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main(void)
{
    int arr[] = {64, 25, 12, 22, 11, 90}; // Input array to be sorted
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Input Array: ");
    printArray(arr, size);

    quickSort(arr, 0, size - 1); // Sorting the array using Quick Sort algorithm

    printf("Sorted Array: ");
    printArray(arr, size);

    return EXIT_SUCCESS;
}