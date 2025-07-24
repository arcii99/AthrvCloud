//FormAI DATASET v1.0 Category: Searching algorithm ; Style: post-apocalyptic
#include <stdio.h>

#define ARRAY_SIZE 10

int binary_search(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {
    // initialize array and target element
    int arr[ARRAY_SIZE] = {5, 8, 9, 12, 15, 17, 19, 21, 25, 27};
    int target = 17;

    // search for target element
    int index = binary_search(arr, 0, ARRAY_SIZE - 1, target);

    // process search results
    if (index != -1) {
        printf("Target element %d found at index %d\n", target, index);
    } else {
        printf("Target element %d not found\n", target);
    }

    return 0;
}