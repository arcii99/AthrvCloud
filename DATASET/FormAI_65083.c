//FormAI DATASET v1.0 Category: Searching algorithm ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Function for performing Binary Search
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // If we reach here, then element was not present
    return -1;
}

int main()
{
    // Initializing variables 
    int arr[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    // Calling Binary Search function to find the index of element x in array arr
    int result = binarySearch(arr, 0, n - 1, x);

    // If x was found in the array, print the index and element
    if (result != -1)
        printf("Element %d is present at index %d in array arr", x, result);

    // If x was not found in the array, print the message
    else
        printf("Element %d is not present in array arr", x);

    return 0;
}