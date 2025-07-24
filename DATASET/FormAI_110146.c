//FormAI DATASET v1.0 Category: Searching algorithm ; Style: rigorous
#include <stdio.h>

int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // found at index i
        }
    }
    return -1; // not found
}

int main() {
    int arr[] = {6, 2, 8, 5, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 8;

    int result = linear_search(arr, n, target);

    if (result == -1) {
        printf("%d not found in the array\n", target);
    } else {
        printf("%d found at index %d\n", target, result);
    }

    return 0;
}