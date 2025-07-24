//FormAI DATASET v1.0 Category: Searching algorithm ; Style: grateful
#include <stdio.h>

int binary_search(int arr[], int l, int h, int x) {
    while (l <= h) {
        int mid = (l + h) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int main() {
    printf("***** Binary Search Algorithm *****\n\n");

    int arr[10] = {5, 9, 10, 15, 20, 25, 30, 35, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Elements of the array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    int x = 25;
    int result = binary_search(arr, 0, n - 1, x);
    if (result == -1)
        printf("\n\nElement %d was not found in the array.", x);
    else
        printf("\n\nElement %d was found at index %d in the array.", x, result);

    return 0;
}