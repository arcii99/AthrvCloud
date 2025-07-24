//FormAI DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
// A beginner-friendly example program for linear search algorithm
#include <stdio.h>

// function to perform linear search on an array
int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// main function
int main() {
    int arr[] = {32, 45, 67, 89, 12, 56, 31, 78, 23, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    int result = linear_search(arr, n, key);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }
    return 0;
}