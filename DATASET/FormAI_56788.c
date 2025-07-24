//FormAI DATASET v1.0 Category: Searching algorithm ; Style: decentralized
#include <stdio.h>

// Decentralized searching algorithm
int decentralizedSearch(int arr[], int left, int right, int x) {

    if (left > right)
        return -1;

    // Define mid index and value
    int mid = (left + right) / 2;
    int midValue = arr[mid];

    // Check if x is at mid index
    if (midValue == x)
        return mid;

    // Check if the left half is ordered
    if (arr[left] <= arr[mid-1]) {
        // Check if x is within the left half
        if (x >= arr[left] && x <= arr[mid-1]) {
            // Recursive call to search the left half
            return decentralizedSearch(arr, left, mid-1, x);
        }
        // If x is not within the left half, search the right half
        return decentralizedSearch(arr, mid+1, right, x);
    }

    // If the left half is not ordered, the right half must be ordered
    // Check if x is within the right half
    if (x >= arr[mid+1] && x <= arr[right]) {
        // Recursive call to search the right half
        return decentralizedSearch(arr, mid+1, right, x);
    }
    // If x is not within the right half, search the left half
    return decentralizedSearch(arr, left, mid-1, x);
}

// Main function to test the algorithm
int main() {
    // Initialize and define array
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Define value to search for and call decentralized search algorithm
    int x = 7;
    int result = decentralizedSearch(arr, 0, n-1, x);

    if (result == -1) {
        printf("Element %d is not present in the array\n", x);
    } else {
        printf("Element %d is present at index %d\n", x, result);
    }
    return 0;
}