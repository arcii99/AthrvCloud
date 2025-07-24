//FormAI DATASET v1.0 Category: Searching algorithm ; Style: synchronous
#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int l, int r, int key) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == key)
            return m;
        if (arr[m] < key)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main() {
    int arr[] = {5, 7, 9, 11, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 11;

    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\n");

    printf("Searching for key %d using linear search...\n", key);
    int linIndex = linearSearch(arr, n, key);
    if (linIndex != -1) {
        printf("Key found at index %d\n", linIndex);
    } else {
        printf("Key not found\n");
    }

    printf("\n");

    printf("Sorting array using bubble sort...\n");
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\n");

    printf("Searching for key %d using binary search...\n", key);
    int binIndex = binarySearch(arr, 0, n-1, key);
    if (binIndex != -1) {
        printf("Key found at index %d\n", binIndex);
    } else {
        printf("Key not found\n");
    }

    return 0;
}