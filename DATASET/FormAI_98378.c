//FormAI DATASET v1.0 Category: Searching algorithm ; Style: enthusiastic
#include <stdio.h>

/* This program demonstrates the binary search algorithm which is a very efficient way to search for a target value within a sorted array. */

int binarySearch(int arr[], int l, int r, int x) {

    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle itself
        if (arr[mid] == x) {
            return mid;
        }
        
        // If element is smaller than mid, then it can only be present in the left subarray
        if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
        }
        
        // Else the element can only be present in the right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // Element is not present in array
    return -1;
}

int main() {
    
    int arr[] = { 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 23;

    int result = binarySearch(arr, 0, n - 1, x);

    if (result == -1) {
        printf("Element is not present in array.\n");
    }
    else {
        printf("Element is present at index %d.\n", result);
    }

    return 0;
}