//FormAI DATASET v1.0 Category: Searching algorithm ; Style: imaginative
#include <stdio.h>

// function to perform binary search on the given array
int binarySearch(int arr[], int l, int r, int key) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
 
        // Check if key is present at mid
        if (arr[mid] == key)
            return mid;
 
        // If key is greater, ignore left half
        if (arr[mid] < key)
            l = mid + 1;
 
        // If key is smaller, ignore right half
        else
            r = mid - 1;
    }

    // key was not present in the array 
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Enter the number to be searched:\n");
    int key;
    scanf("%d", &key);

    int index = binarySearch(arr, 0, n - 1, key);

    if (index == -1) {
        printf("Element not present in the array\n");
    } else {
        printf("Element found at index %d\n", index);
    }

    return 0;
}