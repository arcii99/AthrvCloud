//FormAI DATASET v1.0 Category: Searching algorithm ; Style: optimized
#include <stdio.h>

int optimized_linear_search(int arr[], int n, int x) {
    int i, pos = -1;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            pos = i;
            break;
        }
    }
    return pos;
}

int optimized_binary_search(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 30;
    
    printf("The array is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n\nLooking for %d in the array...\n", x);

    // Optimized Linear Search
    printf("\nLinear Search: ");
    int lin_pos = optimized_linear_search(arr, n, x);
    if (lin_pos == -1)
        printf("%d not found!", x);
    else
        printf("%d found at position %d.", x, lin_pos+1);

    // Optimized Binary Search
    printf("\nBinary Search: ");
    int bin_pos = optimized_binary_search(arr, 0, n-1, x);
    if (bin_pos == -1)
        printf("%d not found!", x);
    else
        printf("%d found at position %d.", x, bin_pos+1);

    return 0;
}