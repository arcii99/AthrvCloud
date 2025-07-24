//FormAI DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>

int search(int *arr, int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int size = sizeof(arr) / sizeof(int);
    int key = 7;
    int index = search(arr, size, key);
    if (index != -1)
        printf("Key found at index %d\n", index);
    else
        printf("Key not found\n");
    return 0;
}