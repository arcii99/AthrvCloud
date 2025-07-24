//FormAI DATASET v1.0 Category: Searching algorithm ; Style: systematic
#include <stdio.h>

// function to perform binary search
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        
        // if element is present at the middle
        if (arr[mid] == x) {
            return mid;
        }
        
        // if element is smaller than middle
        if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
        }
        
        // if element is larger than middle
        return binarySearch(arr, mid + 1, r, x);
    }
    
    // if element is not present in array
    return -1;
}

int main(void) {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 50;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array.")
                   : printf("Element is present at index %d", result);
    return 0;
}