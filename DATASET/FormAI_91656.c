//FormAI DATASET v1.0 Category: Searching algorithm ; Style: systematic
#include <stdio.h>

int binary_search(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        else if (arr[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 5, 7, 8, 9, 10, 12, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 8;
    int index = binary_search(arr, n, x);
    if (index == -1) {
        printf("Element not found in the array!\n");
    }
    else {
        printf("Element found at index %d in the array.\n", index);
    }
    return 0;
}