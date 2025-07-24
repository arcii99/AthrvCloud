//FormAI DATASET v1.0 Category: Searching algorithm ; Style: inquisitive
#include<stdio.h>

int bottomsup_search(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int size = sizeof(arr) / sizeof(int);
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int key = 7;
    int idx = bottomsup_search(arr, size, key);
    if (idx != -1) {
        printf("%d is found at index %d\n", key, idx);
    } else {
        printf("%d is not found in the array\n", key);
    }
    return 0;
}