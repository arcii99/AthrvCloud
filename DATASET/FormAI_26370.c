//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Sherlock Holmes
#include <stdio.h>

int search(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 4, 6, 7, 8, 9, 12, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;
    int result = search(arr, n, x);
    (result == -1)
        ? printf("Element is not present in the array")
        : printf("Element is present at index %d", result);
    return 0;
}