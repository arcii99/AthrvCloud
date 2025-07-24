//FormAI DATASET v1.0 Category: Sorting ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10 // Defines the size of the array

// Function prototypes
void merge_sort(int[], int, int);
void merge(int[], int, int, int);

int main()
{
    int arr[ARRAY_SIZE];
    int i;

    // Seed random number generator with current time
    srand(time(NULL));

    // Initialize array with random values
    for(i = 0; i < ARRAY_SIZE; i++)
        arr[i] = rand() % 100;

    // Print original array
    printf("Original Array: ");
    for(i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Sort array using merge sort algorithm
    merge_sort(arr, 0, ARRAY_SIZE - 1);

    // Print sorted array
    printf("Sorted Array: ");
    for(i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

// Recursive merge sort function
void merge_sort(int arr[], int left, int right)
{
    int mid;

    if(left < right)
    {
        mid = (left + right) / 2; // Find middle point
        merge_sort(arr, left, mid); // Sort left side
        merge_sort(arr, mid + 1, right); // Sort right side
        merge(arr, left, mid, right); // Merge left and right sides
    }
}

// Merge function to merge 2 sorted arrays
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1; // Size of left side
    int n2 = right - mid; // Size of right side
    int left_arr[n1], right_arr[n2]; // Create temp arrays to hold values

    // Copy left side into temp array
    for(i = 0; i < n1; i++)
        left_arr[i] = arr[left + i];

    // Copy right side into temp array
    for(j = 0; j < n2; j++)
        right_arr[j] = arr[mid + 1 + j];

    i = 0; // Counter for left side
    j = 0; // Counter for right side
    k = left; // Counter for merged array

    // Compare left and right arrays and merge into sorted array
    while(i < n1 && j < n2)
    {
        if(left_arr[i] <= right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
        }
        else
        {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements from left side
    while(i < n1)
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    // Copy any remaining elements from right side
    while(j < n2)
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}