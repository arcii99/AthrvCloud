//FormAI DATASET v1.0 Category: Searching algorithm ; Style: optimized
#include <stdio.h>

// function to search an element in an array
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {

        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

int main(void) 
{
    int arr[] = { 2, 4, 5, 7, 10, 12, 15, 20 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d", result);
    return 0;
}