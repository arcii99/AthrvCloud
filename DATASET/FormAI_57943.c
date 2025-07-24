//FormAI DATASET v1.0 Category: Searching algorithm ; Style: single-threaded
#include <stdio.h>

/* A simple function to search for an element in an array */
int search(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int main() {
    int arr[] = {4, 2, 7, 5, 1, 3, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;
    int result = search(arr, n, x);
    if (result == -1)
        printf("Element not found\n");
    else
        printf("Element found at index %d\n", result);
    return 0;
}