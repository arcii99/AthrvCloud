//FormAI DATASET v1.0 Category: Searching algorithm ; Style: enthusiastic
#include <stdio.h>

int search(int arr[], int n, int x) {
    // loop through array
    for (int i = 0; i < n; i++) {
        // if element found, return index
        if (arr[i] == x) {
            return i;
        }
    }

    // return -1 if element not found
    return -1;
}

int main() {
    // initialize array
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    // search for elements in array
    int x = 11;
    int index = search(arr, n, x);
    if (index != -1) {
        printf("%d is found at index %d\n", x, index);
    } else {
        printf("%d is not found in array\n", x);
    }

    x = 4;
    index = search(arr, n, x);
    if (index != -1) {
        printf("%d is found at index %d\n", x, index);
    } else {
        printf("%d is not found in array\n", x);
    }

    return 0;
}