//FormAI DATASET v1.0 Category: Searching algorithm ; Style: careful
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
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 8;
    int result = search(arr, n, x);
    if (result == -1) {
        printf("Element is not present in array.");
    } else {
        printf("Element is present at index %d", result);
    }
    return 0;
}