//FormAI DATASET v1.0 Category: Searching algorithm ; Style: mathematical
#include<stdio.h>

// Mathematical Style Binary Search Algorithm
int binary_search(int arr[], int size, int key) {
    int low = 0, high = size - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (key == arr[mid]) {
            return mid;
        }
        else if (key < arr[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 9;

    int index = binary_search(arr, size, key);

    if (index != -1) {
        printf("Element %d is found at index %d.\n", key, index);
    }
    else {
        printf("Element %d is not found in the array.\n", key);
    }
    
    return 0;
}