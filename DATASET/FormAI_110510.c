//FormAI DATASET v1.0 Category: Searching algorithm ; Style: rigorous
#include <stdio.h>

int search(int arr[], int size, int target) {
    int left = 0, right = size - 1, mid;
    
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // target not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    
    int result = search(arr, size, target);
    if (result == -1) {
        printf("Target not found\n");
    } else {
        printf("Target found at index %d\n", result);
    }

    return 0;
}