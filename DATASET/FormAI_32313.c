//FormAI DATASET v1.0 Category: Searching algorithm ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int custom_binary_search(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int custom_linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int custom_search(int arr[], int size, int target) {
    if (size < 10) {
        return custom_linear_search(arr, size, target);
    } else {
        return custom_binary_search(arr, size, target);
    }
}

int main() {
    int arr[10] = {1, 3, 4, 5, 7, 8, 9, 11, 12, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Searching for a number that exists in the array
    int target1 = 7;
    int index1 = custom_search(arr, size, target1);
    if (index1 != -1) {
        printf("The number %d is found at index %d\n", target1, index1);
    } else {
        printf("The number %d is not found in the array\n", target1);
    }

    // Searching for a number that doesn't exist in the array
    int target2 = 6;
    int index2 = custom_search(arr, size, target2);
    if (index2 != -1) {
        printf("The number %d is found at index %d\n", target2, index2);
    } else {
        printf("The number %d is not found in the array\n", target2);
    }
    
    return 0;
}