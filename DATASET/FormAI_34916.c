//FormAI DATASET v1.0 Category: Searching algorithm ; Style: future-proof
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
    int arr[10] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 32;
    int result = search(arr, n, x);
    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result);
    }
    return 0;
}