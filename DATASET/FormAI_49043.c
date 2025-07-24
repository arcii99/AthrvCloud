//FormAI DATASET v1.0 Category: Searching algorithm ; Style: interoperable
#include <stdio.h>

// Function to perform binary search recursively
int binarySearch(int arr[], int low, int high, int key)
{
    if (high < low)
        return -1;
 
    int mid = (low + high)/2; /* mid = (low + high)/2 */
    if (key == arr[mid])
        return mid;
 
    if (key > arr[mid])
        return binarySearch(arr, (mid + 1), high, key);
 
    // else
    return binarySearch(arr, low, (mid -1), key);
}

// Function to perform linear search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Main function
int main() {
    int arr[] = {11, 23, 34, 45, 56, 67, 78, 89, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 78;
    
    // Perform binary search
    int binaryIndex = binarySearch(arr, 0, n-1, key);
    if (binaryIndex == -1) {
        printf("Element not found using binary search\n");
    } else {
        printf("Element found at index %d using binary search\n", binaryIndex);
    }
    
    // Perform linear search
    int linearIndex = linearSearch(arr, n, key);
    if (linearIndex == -1) {
        printf("Element not found using linear search\n");
    } else {
        printf("Element found at index %d using linear search\n", linearIndex);
    }
    
    return 0;
}