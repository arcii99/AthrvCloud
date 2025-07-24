//FormAI DATASET v1.0 Category: Searching algorithm ; Style: thoughtful
#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

// Function to perform binary search
int binarySearch(int arr[], int low, int high, int x)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;

        // If the element is present at the middle
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid
        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);

        // Else the element is in the right subarray
        return binarySearch(arr, mid + 1, high, x);
    }

    // If the element is not present in array
    return -1;
}

// Function to print array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main()
{
    int arr[] = { 2, 5, 7, 9, 13, 15 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 9;

    // Performing Linear Search and printing result
    printf("Searching for %d using Linear Search...\n", x);
    int indexLinear = linearSearch(arr, n, x);
    if (indexLinear == -1)
        printf("%d is not present in the array.\n", x);
    else
        printf("%d is present at index %d.\n", x, indexLinear);

    // Performing Binary Search and printing result
    printf("\nSearching for %d using Binary Search...\n", x);
    int indexBinary = binarySearch(arr, 0, n - 1, x);
    if (indexBinary == -1)
        printf("%d is not present in the array.\n", x);
    else
        printf("%d is present at index %d.\n", x, indexBinary);

    return 0;
}