//FormAI DATASET v1.0 Category: Searching algorithm ; Style: portable
#include <stdio.h>

// Function to perform binary search recursively
int binarySearchRecursive(int arr[], int l, int r, int x) {
    if (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] > x) {
            return binarySearchRecursive(arr, l, mid - 1, x);
        } else {
            return binarySearchRecursive(arr, mid + 1, r, x);
        }
    }
    return -1;
}

// Function to perform binary search iteratively
int binarySearchIterative(int arr[], int l, int r, int x) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] > x) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
    int n = sizeof(arr)/sizeof(int);
    int x = 14;
    
    // Searching using recursive approach
    int result1 = binarySearchRecursive(arr, 0, n-1, x);
    
    if (result1 == -1) {
        printf("Element not present in array\n");
    } else {
        printf("Element found at index %d using recursive approach\n", result1);
    }
    
    // Searching using iterative approach
    int result2 = binarySearchIterative(arr, 0, n-1, x);
    
    if (result2 == -1) {
        printf("Element not present in array\n");
    } else {
        printf("Element found at index %d using iterative approach\n", result2);
    }
    
    return 0;
}