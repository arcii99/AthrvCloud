//FormAI DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>

int search(int arr[], int n, int x) {
    int i, j;
    for (i = 0, j = n - 1; i <= j;) {
        int mid = (i + j) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] < x) {
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 8;
    int result = search(arr, n, x);
    if (result == -1) {
        printf("%d not present in array", x);
    } else {
        printf("%d found at index %d", x, result);
    }
    return 0;
}