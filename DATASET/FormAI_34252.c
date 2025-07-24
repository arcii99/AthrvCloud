//FormAI DATASET v1.0 Category: Searching algorithm ; Style: futuristic
#include <stdio.h>

int futuristic_search(int arr[], int size, int value) {
    int start = 0, end = size - 1, mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (arr[mid] == value) {
            // Match found. Return the index.
            return mid;
        }
        else if (value < arr[mid]) {
            // Value is in the lower half of the array.
            // Move end index to mid - 1.
            end = mid - 1;
        }
        else {
            // Value is in the upper half of the array.
            // Move start index to mid + 1.
            start = mid + 1;
        }
    }

    // Value not present in array.
    return -1;
}

int main() {

    // Example usage
    int arr[] = {2, 4, 7, 9, 12, 16, 19, 23, 26, 29};
    int size = 10;
    int value = 16;

    int index = futuristic_search(arr, size, value);

    if (index == -1) {
        printf("Value not found in array");
    }
    else {
        printf("Value found at index %d", index);
    }

    return 0;
}