//FormAI DATASET v1.0 Category: Searching algorithm ; Style: protected
#include <stdio.h>

// Protected Searching Algorithm
int protectedSearch(int arr[], int n, int key) {
    // indices for start and end
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        // calculate middle index
        int mid = start + (end - start) / 2;

        // if key is found at middle index, return index
        if (arr[mid] == key) {
            return mid;
        }
        // check if left half of array is sorted and 
        // key is present in it
        else if (arr[start] <= arr[mid] && 
                 key <= arr[mid] && key >= arr[start]) {
            end = mid - 1;
        }
        // check if right half of array is sorted and 
        // key is present in it
        else if (arr[mid] <= arr[end] && 
                 key >= arr[mid] && key <= arr[end]) {
            start = mid + 1;
        }
        // if key is not present in either half, return -1
        else {
            return -1;
        }
    }
    // key not found in array, return -1
    return -1;
}

// main function to test protectedSearch function
int main() {
    int arr[] = { 4, 5, 6, 7, 8, 1, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 6;
    int index = protectedSearch(arr, n, key);

    if (index != -1) {
        printf("Key %d found at index %d", key, index);
    } else {
        printf("Key %d not found in array", key);
    }

    return 0;
}