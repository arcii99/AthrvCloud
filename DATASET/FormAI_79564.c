//FormAI DATASET v1.0 Category: Searching algorithm ; Style: mathematical
#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        // If element is present at the middle
        if (arr[mid] == x) {
            return mid;
        }
        // If element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
        }
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
    // Element is not present in array
    return -1;
}

int main() {
    int arr[] = {1, 3, 4, 5, 7, 8, 9, 11, 14, 17};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 9;
    int result = binarySearch(arr, 0, n-1, x);
    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d", result);
    return 0;
}