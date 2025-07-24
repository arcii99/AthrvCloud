//FormAI DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
// A program to demonstrate sequential search algorithm in C

#include <stdio.h>
#include <stdbool.h>

int sequentialSearch(int arr[], int size, int searchKey);

int main() {
    int arr[] = {1, 4, 5, 2, 7, 8, 3, 6}; // Array to search
    int size = sizeof(arr) / sizeof(arr[0]); // Size of the array
    int searchKey = 8; // Key to search
    int result = sequentialSearch(arr, size, searchKey); // Search for the key in the array

    if (result == -1)
        printf("Key not found in the array\n"); // If key not found
    else
        printf("Key found at index %d in the array\n", result); // If key found

    return 0;
}

// Function to perform sequential search
int sequentialSearch(int arr[], int size, int searchKey) {
    int i;

    for (i = 0; i < size; i++) {
        if (arr[i] == searchKey) {
            return i; // Returning the index of the search key
        }
    }

    return -1; // If the search key is not found, return -1
}