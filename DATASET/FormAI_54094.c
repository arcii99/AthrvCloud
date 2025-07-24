//FormAI DATASET v1.0 Category: Searching algorithm ; Style: interoperable
#include <stdio.h>

// Interoperable searching algorithm function that searches for a given value in a given array
int search(int arr[], int n, int value) {

    // Set the starting index and ending index of the array
    int start = 0;
    int end = n - 1;

    // Check if the value is present at the start or end of the array
    if (arr[start] == value) {
        return start;
    } else if (arr[end] == value) {
        return end;
    }

    // Iterate through the array until the value is found or the start and end indices overlap
    while (start <= end) {

        // Get the midpoint index of the array
        int mid = (start + end) / 2;

        // If the value is found in the midpoint index, return the index
        if (arr[mid] == value) {
            return mid;
        }

        // If the value is greater than the midpoint value, search the right half of the array
        if (arr[mid] < value) {
            start = mid + 1;
        } 
        // If the value is less than the midpoint value, search the left half of the array
        else {
            end = mid - 1;
        }
    }

    // If the value is not found in the array, return -1
    return -1;
}

int main() {
    // Create an array of integers to test the search function
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int value = 5;

    // Call the search function and print the result
    int result = search(arr, n, value);
    if (result == -1) {
        printf("Value not found in array.");
    } else {
        printf("Value found at index %d.", result);
    }

    return 0;
}