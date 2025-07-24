//FormAI DATASET v1.0 Category: Searching algorithm ; Style: scientific
#include <stdio.h>

/* Function to search for an element in the array using Binary search */
int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;
 
        if (arr[mid] < x)
            low = mid + 1;
 
        else
            high = mid - 1;
    }
    return -1;
}
 
/* Function to search for an element in the array using Linear Search */
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
 
int main() {
    int arr[] = { 2, 5, 7, 12, 18, 22, 25, 29, 32, 38, 42 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x1 = 25, x2 = 49;

    // Binary Search
    int binary_result = binarySearch(arr, 0, n - 1, x1);
    (binary_result == -1) ? printf("Element %d is not present in the array\n", x1)
                          : printf("Element %d is present at index %d using Binary search\n", x1, binary_result);

    binary_result = binarySearch(arr, 0, n - 1, x2);
    (binary_result == -1) ? printf("Element %d is not present in the array\n", x2)
                          : printf("Element %d is present at index %d using Binary search\n", x2, binary_result);
     
    // Linear Search
    int linear_result = linearSearch(arr, n, x1);
    (linear_result == -1) ? printf("Element %d is not present in the array\n", x1)
                          : printf("Element %d is present at index %d using Linear search\n", x1, linear_result);

    linear_result = linearSearch(arr, n, x2);
    (linear_result == -1) ? printf("Element %d is not present in the array\n", x2)
                          : printf("Element %d is present at index %d using Linear search\n", x2, linear_result);
    return 0;
}