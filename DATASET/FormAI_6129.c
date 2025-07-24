//FormAI DATASET v1.0 Category: Searching algorithm ; Style: visionary
/* 

Visionary C Searching Algorithm

Objective: This algorithm aims to provide a unique and efficient way of searching for a target value in an array.

Approach: The algorithm will first sort the array in ascending order using a bubble sort. Then, it will perform a binary search to find the target value.

*/

#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            l = mid + 1;

        else
            r = mid - 1;
    }

    return -1;
}

int main() {
    int arr[] = {9, 6, 3, 7, 2, 1, 5, 4, 8, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    printf("Original Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    bubbleSort(arr, n);

    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    int index = binarySearch(arr, 0, n-1, target);

    if (index == -1)
        printf("\nTarget value not found\n");
    else
        printf("\nTarget value found at index %d\n", index);

    return 0;
}