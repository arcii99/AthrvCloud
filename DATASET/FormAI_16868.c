//FormAI DATASET v1.0 Category: Searching algorithm ; Style: recursive
#include <stdio.h>

// Recursive function for binary search
int RecursiveBinarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // If the element is present at the middle
        if (arr[mid] == x) {
            return mid;
        }

        // If the element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x) {
            return RecursiveBinarySearch(arr, left, mid - 1, x);
        }

        // Else  the element can only be present in right subarray
        return RecursiveBinarySearch(arr, mid + 1, right, x);
    }

    // We reach here when element is not present in array
    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = RecursiveBinarySearch(arr, 0, n - 1, x);
    if(result == -1) {
        printf("Element is not present in array\n");
    } else {
        printf("Element is present at index %d\n", result);
    }
    return 0;
}