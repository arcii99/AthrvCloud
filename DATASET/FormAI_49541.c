//FormAI DATASET v1.0 Category: Searching algorithm ; Style: innovative
#include <stdio.h>

int search(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[10] = {3, 7, 12, 4, 5, 2, 8, 1, 10, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 8;
    int result = search(arr, n, x);
    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result);
    }
    return 0;
}