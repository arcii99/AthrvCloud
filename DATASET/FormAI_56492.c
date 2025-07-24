//FormAI DATASET v1.0 Category: Searching algorithm ; Style: portable
#include <stdio.h>

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 8;
    int result = linearSearch(arr, n, x);
    if (result == -1) {
        printf("Element not found");
    } else {
        printf("Element found at index %d", result);
    }
    return 0;
}