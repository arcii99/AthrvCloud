//FormAI DATASET v1.0 Category: Searching algorithm ; Style: light-weight
#include <stdio.h>

// Returns the index of the first occurrence of search element in array. Returns -1 if not found.
int search(int arr[], int n, int searchElement) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == searchElement) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    int searchElement = 8;
    int index = search(arr, n, searchElement);

    if (index == -1) {
        printf("%d not found in array\n", searchElement);
    } else {
        printf("%d found at index %d in array\n", searchElement, index);
    }

    searchElement = 9;
    index = search(arr, n, searchElement);

    if (index == -1) {
        printf("%d not found in array\n", searchElement);
    } else {
        printf("%d found at index %d in array\n", searchElement, index);
    }

    return 0;
}