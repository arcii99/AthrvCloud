//FormAI DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>

int binarySearch(int arr[], int low, int high, int item) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == item)
            return mid;
        if (arr[mid] > item)
            return binarySearch(arr, low, mid-1, item);
        return binarySearch(arr, mid+1, high, item);
    }
    return -1;
}

int main() {
    int arr[] = {2, 5, 7, 12, 14, 17, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    int item = 14;
    int result = binarySearch(arr, 0, n-1, item);
    if (result == -1)
        printf("Item not found");
    else
        printf("Item found at index %d", result);
    return 0;
}