//FormAI DATASET v1.0 Category: Searching algorithm ; Style: standalone
#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int mid = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // If x greater, ignore left half
        if (arr[mid] < x)
            l = mid + 1;

        // If x is smaller, ignore right half
        else
            r = mid - 1;
    }

    // if we reach here, then element was not present
    return -1;
}

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        // Return the index of the element if found
        if (arr[i] == x)
            return i;
    }

    // Return -1 if element is not present
    return -1;
}

// Driver code
int main() {
    int arr[] = {2, 4, 5, 7, 10, 21, 32, 50, 55, 64};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 21;

    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d", result);
    printf("\n");

    result = linearSearch(arr, n, x);
    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d", result);

    return 0;
}