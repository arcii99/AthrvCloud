//FormAI DATASET v1.0 Category: Searching algorithm ; Style: grateful
#include <stdio.h>

// function for binary search
int binarySearch(int arr[], int low, int high, int key) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        // if the key is present at the middle itself
        if (arr[mid] == key)
            return mid;

        // if key is smaller than mid, then it can only be present in left subarray
        if (arr[mid] > key)
            return binarySearch(arr, low, mid - 1, key);

        // else the key lies in right subarray
        return binarySearch(arr, mid + 1, high, key);
    }

    // key not found
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    int result = binarySearch(arr, 0, n - 1, key);
    if (result == -1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d", result);

    return 0;
}