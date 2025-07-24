//FormAI DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
#include <stdio.h>

int linear_search(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[10] = {2, 4, 6, 8, 10, 3, 1, 7, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    int index = linear_search(arr, n, x);
    if (index != -1) {
        printf("Element %d found at index %d\n", x, index);
    } else {
        printf("Element not found\n");
    }
    return 0;
}