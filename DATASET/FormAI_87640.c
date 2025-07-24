//FormAI DATASET v1.0 Category: Searching algorithm ; Style: calm
#include <stdio.h>

int linear_search(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 3;
    int result = linear_search(arr, n, x);
    if (result == -1) {
        printf("%d is not present in the array", x);
    } else {
        printf("%d is present at index %d", x, result);
    }
    return 0;
}