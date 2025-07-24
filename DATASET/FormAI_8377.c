//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Linus Torvalds
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
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;
    int result = linearSearch(arr, n, x);
    if (result == -1) {
        printf("Element is not present in the array.\n");
    } else {
        printf("Element is present at index %d.\n", result);
    }
    return 0;
}