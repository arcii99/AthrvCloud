//FormAI DATASET v1.0 Category: Searching algorithm ; Style: ephemeral
#include <stdio.h>

// Custom search function to find the index of the key
int ephemeral_search(int arr[], int key, int n) {
    int left = 0, right = n - 1;

    while (left <= right) {
        // Finding the middle index
        int middle = left + (right - left) / 2;

        // If the key is found, return the index
        if (arr[middle] == key) {
            printf("Found the key at index %d\n", middle);
            return middle;
        }

        // If key is smaller than the middle element, narrow search interval to left half
        if (arr[middle] > key) {
            right = middle - 1;
        }

        // If the key is larger than the middle element, widen search interval to right half
        else {
            left = middle + 1;
        }
    }

    // If key is not found, return -1
    printf("Key not found in the array\n");
    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    ephemeral_search(arr, key, n);
    return 0;
}