//FormAI DATASET v1.0 Category: Searching algorithm ; Style: scientific
#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i; // Element found at index i
    }
    return -1; // Element not found
}

// Function to perform binary search
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid; // Element found at index mid

        if (arr[mid] < x)
            l = mid + 1; // Search the right half
        else
            r = mid - 1; // Search the left half
    }
    return -1; // Element not found
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x1 = 10; // Element to search
    int x2 = 5;

    int result1 = linearSearch(arr, n, x1);
    if (result1 == -1)
        printf("Element %d not found in array\n", x1);
    else
        printf("Element %d found at index %d using linear search\n", x1, result1);

    int result2 = binarySearch(arr, 0, n - 1, x1);
    if (result2 == -1)
        printf("Element %d not found in array\n", x1);
    else
        printf("Element %d found at index %d using binary search\n", x1, result2);

    int result3 = linearSearch(arr, n, x2);
    if (result3 == -1)
        printf("Element %d not found in array\n", x2);
    else
        printf("Element %d found at index %d using linear search\n", x2, result3);

    int result4 = binarySearch(arr, 0, n - 1, x2);
    if (result4 == -1)
        printf("Element %d not found in array\n", x2);
    else
        printf("Element %d found at index %d using binary search\n", x2, result4);

    return 0;
}