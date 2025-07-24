//FormAI DATASET v1.0 Category: Searching algorithm ; Style: romantic
#include <stdio.h>

// function to perform binary search
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int mid = l + (r - l) / 2;

        // check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // if x is greater than mid, ignore left half
        if (arr[mid] < x)
            l = mid + 1;

        // if x is smaller than mid, ignore right half
        else
            r = mid - 1;
    }

    // element not found
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        printf("Element is not present in the array.\n");
    else
        printf("Element is present at index %d.\n", result);
    return 0;
}