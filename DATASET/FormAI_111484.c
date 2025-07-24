//FormAI DATASET v1.0 Category: Searching algorithm ; Style: visionary
#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int x)
{
    // Check if the right pointer crossed the left pointer
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // If x is greater, ignore left half
        if (arr[mid] < x)
            left = mid + 1;

        // If x is smaller, ignore right half
        else
            right = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}

// Function to perform exponential search
int exponentialSearch(int arr[], int n, int x)
{
    // Edge case: If first element is the search element
    if (arr[0] == x)
        return 0;

    // Find range for binary search
    int i = 1;
    while (i < n && arr[i] <= x)
        i *= 2;

    // Call binary search for the found range
    return binarySearch(arr, i / 2, 
                        i < n ? i : n - 1, x);
}

// Main function to run the program
int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 23;

    int result = exponentialSearch(arr, n, x);

    if (result == -1)
        printf("Element not present in array");
    else
        printf("Element found at index %d", result);
    return 0;
}