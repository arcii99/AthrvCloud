//FormAI DATASET v1.0 Category: Searching algorithm ; Style: thoughtful
#include <stdio.h>

// function to search for a value in an array using linear search algorithm
int linearSearch(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;  // indicate value not found
}

// function to search for a value in a sorted array using binary search algorithm
int binarySearch(int arr[], int size, int value) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // indicate value not found
}

// main function to test linear search and binary search
int main() {
    int arr[] = {3, 5, 1, 9, 4, 2, 8, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    int value = 9;
    int index = linearSearch(arr, size, value);
    if (index == -1) {
        printf("%d not found in the array!\n", value);
    } else {
        printf("%d found at index %d using linear search.\n", value, index);
    }
    
    value = 7;
    index = binarySearch(arr, size, value);
    if (index == -1) {
        printf("%d not found in the array!\n", value);
    } else {
        printf("%d found at index %d using binary search.\n", value, index);
    }
    
    return 0;
}