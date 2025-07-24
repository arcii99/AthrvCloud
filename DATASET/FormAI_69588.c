//FormAI DATASET v1.0 Category: Searching algorithm ; Style: accurate
#include <stdio.h>

// function to perform binary search
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was not present
    return -1;
}

// function to print array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    printArray(arr, n);

    int result = binarySearch(arr, 0, n - 1, x);

    if (result == -1)
        printf("Element not found");
    else
        printf("Element found at index %d", result);
    return 0;
}