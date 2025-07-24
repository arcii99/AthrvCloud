//FormAI DATASET v1.0 Category: Searching algorithm ; Style: creative
#include <stdio.h>

int BinarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        // If element is present at middle.
        if (arr[mid] == x)
            return mid;
        // If arr[mid] is smaller than x, ignore left half
        if (arr[mid] < x)
            left = mid + 1;
        // If arr[mid] is greater than x, ignore right half
        else
            right = mid - 1;
    }
    // If element wasn't found.
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    printf("Enter the element to be searched: ");
    scanf("%d", &x);
    int result = BinarySearch(arr, 0, n - 1, x);
    if (result == -1)
        printf("Element not found.\n");
    else
        printf("Element found at index %d.\n", result);
    return 0;
}