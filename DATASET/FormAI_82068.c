//FormAI DATASET v1.0 Category: Searching algorithm ; Style: synchronous
#include <stdio.h>

int search(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int main() {
    int arr[] = {4, 7, 2, 9, 1, 5, 8, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;
    int result = search(arr, n, x);
    if (result == -1)
        printf("Element is not present in array.\n");
    else
        printf("Element is present at index %d\n", result);
    return 0;
}