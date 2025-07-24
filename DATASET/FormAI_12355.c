//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Dennis Ritchie
#include <stdio.h>

// Function to find the index of the element in
// the given array if it exists, else return -1
int binarySearch(int arr[], int n, int x)
{
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // If x is greater, ignore the left half
        if (arr[mid] < x)
            left = mid + 1;

        // If x is smaller, ignore the right half
        else
            right = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}

int main(void) {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;

    int result = binarySearch(arr, n, x);

    if (result == -1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d", result);
        
    return 0;
}