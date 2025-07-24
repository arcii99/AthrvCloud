//FormAI DATASET v1.0 Category: Searching algorithm ; Style: shape shifting
#include <stdio.h>

// Define some shapes
#define LINEAR_SEARCH 0
#define BINARY_SEARCH 1

// Function prototypes
int linear_search(int arr[], int n, int x);
int binary_search(int arr[], int low, int high, int x);

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;

    // Shape-shift the search algorithm based on the array size
    int search_type;
    if (n < 10) {
        search_type = LINEAR_SEARCH;
    } else {
        search_type = BINARY_SEARCH;
    }

    // Search for the value
    int index;
    if (search_type == LINEAR_SEARCH) {
        index = linear_search(arr, n, x);
    } else {
        index = binary_search(arr, 0, n - 1, x);
    }

    // Display the search result
    if (index == -1) {
        printf("Value %d was not found in the array.\n", x);
    } else {
        printf("Value %d was found at index %d in the array.\n", x, index);
    }

    return 0;
}

// Linear search algorithm
int linear_search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// Binary search algorithm
int binary_search(int arr[], int low, int high, int x)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] > x) {
            return binary_search(arr, low, mid - 1, x);
        }

        return binary_search(arr, mid + 1, high, x);
    }

    return -1;
}