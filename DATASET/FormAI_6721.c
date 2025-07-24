//FormAI DATASET v1.0 Category: Searching algorithm ; Style: energetic
#include <stdio.h>

// Function to implement Binary Search Algorithm
int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
 
        if (arr[mid] == x) {
            return mid;
        }
 
        if (arr[mid] < x) {
            left = mid + 1;
        }
 
        else {
            right = mid - 1;
        }
    }
 
    // If the element is not found 
    return -1;
}

int main() {
    int arr[] = { 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 23;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1) {
        printf("Element is not present in the array.");
    }
    else {
        printf("Element is present at index %d", result);
    }
    
    return 0;
}