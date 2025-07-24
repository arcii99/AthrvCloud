//FormAI DATASET v1.0 Category: Searching algorithm ; Style: synchronous
#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 8, 3, 1, 6, 5, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 6, pos;
    pos = linearSearch(arr, n, key);
    if (pos == -1)
        printf("Element not found");
    else
        printf("Element found at position %d", pos);
    return 0;
}