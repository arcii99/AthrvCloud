//FormAI DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include <stdio.h>

int search(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == x) {
            return mid; // element found
        }
        else if (arr[mid] < x) { 
            left = mid + 1; // search right side
        }
        else {
            right = mid - 1; // search left side
        }
    }
    return -1; // element not found
}

int main() {
    int arr[] = {2, 5, 7, 10, 14, 20, 25, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 14;
    int result = search(arr, n, x);

    if (result == -1) {
        printf("Element not found.\n");
    }
    else {
        printf("Element found at index %d.\n", result);
    }

    return 0;
}