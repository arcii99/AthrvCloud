//FormAI DATASET v1.0 Category: Searching algorithm ; Style: calm
#include<stdio.h>

// Function for binary search algorithm
int binary_search(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // If x greater, ignore left half
        if (arr[mid] < x)
            l = mid + 1;

        // If x is smaller, ignore right half
        else
            r = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}

// Driver code
int main()
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binary_search(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array\n")
                   : printf("Element is present at index %d\n",
                            result);
    return 0;
}