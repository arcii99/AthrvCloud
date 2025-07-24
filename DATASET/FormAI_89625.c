//FormAI DATASET v1.0 Category: Searching algorithm ; Style: bold
#include <stdio.h>
#include <stdlib.h>

int binary_search(int target, int *array, int size) {
    int low = 0;
    int high = size - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (array[mid] == target) {
            return mid;
        } else if (array[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int linear_search(int target, int *array, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int array[5] = {5, 10, 15, 20, 25};
    int size = 5;
    int target = 20;

    int result = binary_search(target, array, size);
    if (result != -1) {
        printf("Binary Search: Target found at index %d\n", result);
    } else {
        printf("Binary Search: Target not found in array\n");
    }

    result = linear_search(target, array, size);
    if (result != -1) {
        printf("Linear Search: Target found at index %d\n", result);
    } else {
        printf("Linear Search: Target not found in array\n");
    }

    return 0;
}