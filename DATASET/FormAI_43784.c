//FormAI DATASET v1.0 Category: Searching algorithm ; Style: relaxed
#include <stdio.h>

/* Function to perform linear search */
int linear_search(int arr[], int n, int key) {
    int i;

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }

    return -1;
}

int main() {
    int arr[] = {5, 9, 2, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    /* Perform linear search */
    int result = linear_search(arr, n, key);

    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result);
    }

    return 0;
}