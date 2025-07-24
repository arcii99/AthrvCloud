//FormAI DATASET v1.0 Category: Searching algorithm ; Style: shape shifting
#include <stdio.h>

int search(int arr[], int n, int x) {
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 8;
    int result = search(arr, n, x);
    if (result == -1)
        printf("Element is not present in the array.\n");
    else
        printf("Element is present at position %d.\n", result + 1);
    return 0;
}