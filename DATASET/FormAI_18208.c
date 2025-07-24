//FormAI DATASET v1.0 Category: Searching algorithm ; Style: single-threaded
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
    int arr[] = {99, 43, 67, 12, 89, 34, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 67;
    int index = search(arr, n, x);
    if (index != -1) {
        printf("%d is present at index %d\n", x, index);
    } else {
        printf("%d is not present in the array\n", x);
    }
    return 0;
}