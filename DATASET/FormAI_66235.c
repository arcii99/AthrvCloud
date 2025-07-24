//FormAI DATASET v1.0 Category: Searching algorithm ; Style: recursive
#include <stdio.h>

int recursive_search(int* arr, int low, int high, int target) {
    int mid;

    if (low > high) {
        return -1; // target not found in array
    }

    mid = (low + high) / 2;

    if (target == arr[mid]) {
        return mid; // target found
    } else if (target < arr[mid]) {
        return recursive_search(arr, low, mid - 1, target); // search left side of array
    } else {
        return recursive_search(arr, mid + 1, high, target); // search right side of array
    }
}

int main() {
    int arr[] = {1, 3, 4, 5, 6, 7, 9, 10, 11, 12};
    int target = 5;
    int index = recursive_search(arr, 0, 9, target);

    if (index != -1) {
        printf("Target %d found at index %d\n", target, index);
    } else {
        printf("Target %d not found in array\n", target);
    }

    return 0;
}