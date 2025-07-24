//FormAI DATASET v1.0 Category: Searching algorithm ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search recursively
int binarySearch(int arr[], int low, int high, int key)
{
    // base case
    if (low > high) {
        return -1;
    }

    // find the mid-value of the array
    int mid = (low + high) / 2;

    // if the key is present at the mid,
    // return its index
    if (arr[mid] == key) {
        return mid;
    }

    // if the left half of the array is sorted
    if (arr[low] <= arr[mid]) {
        // if the key lies between low and mid value,
        // search in the left subarray
        if (key >= arr[low] && key <= arr[mid]) {
            return binarySearch(arr, low, mid - 1, key);
        }

        // search in the right subarray
        return binarySearch(arr, mid + 1, high, key);
    }

    // if the right half of the array is sorted
    if (key >= arr[mid] && key <= arr[high]) {
        // search in the right subarray
        return binarySearch(arr, mid + 1, high, key);
    }

    // search in the left subarray
    return binarySearch(arr, low, mid - 1, key);
}

// Driver code
int main()
{
    int arr[] = { 4, 5, 6, 7, 1, 2, 3 };
    int n = sizeof(arr) / sizeof(int);
    int key = 2;

    int index = binarySearch(arr, 0, n - 1, key);

    if (index != -1) {
        printf("Element found at index %d", index);
    }
    else {
        printf("Element not found in the array");
    }

    return 0;
}