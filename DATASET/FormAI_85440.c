//FormAI DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include <stdio.h>

int binary_search(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n = 10;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x = 7;
    int result = binary_search(arr, 0, n - 1, x);
    if (result == -1) {
        printf("Element not present in array.\n");
    } else {
        printf("Element found at index %d.\n", result);
    }
    return 0;
}