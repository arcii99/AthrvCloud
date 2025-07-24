//FormAI DATASET v1.0 Category: Searching algorithm ; Style: real-life
#include <stdio.h>

/* Quicksearch Function */
int quicksearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

/* Main Function */
int main() {
    int arr[] = {2, 4, 7, 8, 12, 15, 19, 20, 23, 27, 30, 32, 34, 38, 41};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 27;

    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n\nSearching for %d...\n\n", key);
    int index = quicksearch(arr, n, key);

    if (index != -1)
        printf("%d found at index %d.\n", key, index);
    else
        printf("%d not found in the array.\n", key);

    return 0;
}