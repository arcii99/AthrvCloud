//FormAI DATASET v1.0 Category: Searching algorithm ; Style: portable
#include <stdio.h>

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i; // return index of element if found
    }
    return -1; // return -1 if element not found
}

int main() {
    int arr[] = {2, 4, 1, 6, 5, 9, 8, 12, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 11;
    int result = linearSearch(arr, n, x);
    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result);
    }
    return 0;
}