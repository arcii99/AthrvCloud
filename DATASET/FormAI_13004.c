//FormAI DATASET v1.0 Category: Searching algorithm ; Style: configurable
#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int start, int end, int key) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(int);
    int key = 7;
    
    // Linear search
    int result = linearSearch(arr, n, key);
    if (result == -1) {
        printf("Element not found using linear search\n");
    }
    else {
        printf("Element found at index %d using linear search\n", result);
    }
    
    // Binary search
    int binaryResult = binarySearch(arr, 0, n-1, key);
    if (binaryResult == -1) {
        printf("Element not found using binary search\n");
    }
    else {
        printf("Element found at index %d using binary search\n", binaryResult);
    }
    
    return 0;
}