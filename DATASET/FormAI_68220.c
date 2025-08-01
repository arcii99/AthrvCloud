//FormAI DATASET v1.0 Category: Searching algorithm ; Style: thoughtful
#include <stdio.h>

int linearSearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

// This function assumes that input array is sorted in non-decreasing order
int binarySearch(int arr[], int start, int end, int x)
{
    if (end >= start) {
        int mid = start + (end - start) / 2;

        // If the element is present at the middle itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, start, mid - 1, x);

        // Else the element is in right subarray
        return binarySearch(arr, mid + 1, end, x);
    }

    // We reach here when element is not present in array
    return -1;
}

int main()
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    int result = linearSearch(arr, n, x);
    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d", result);

    result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("\nElement is not present in array")
                   : printf("\nElement is present at index %d", result);
    return 0;
}