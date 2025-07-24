//FormAI DATASET v1.0 Category: Searching algorithm ; Style: content
#include <stdio.h>

// Function to perform the unique searching algorithm
int uniqueSearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[left] <= arr[mid]) {
            if (key >= arr[left] && key < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (key > arr[mid] && key <= arr[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1;  // Key not found
}

// Main function
int main() {
    int arr[] = {7, 8, 9, 10, 1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 3;

    int result = uniqueSearch(arr, size, key);

    if (result == -1) {
        printf("Key not found in array.\n");
    } else {
        printf("Key found at index: %d\n", result);
    }

    return 0;
}