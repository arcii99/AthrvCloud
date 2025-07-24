//FormAI DATASET v1.0 Category: Searching algorithm ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int search(int array[], int size, int element) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
    
        printf("Low index: %d\nHigh index: %d\nMiddle index: %d\n", low, high, mid);
        
        if (array[mid] == element) {
            return mid;
        } else if (array[mid] > element) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int size = sizeof(array) / sizeof(array[0]);
    int element = 50;

    int result = search(array, size, element);

    if (result == -1) {
        printf("Element not found in the array\n");
    } else {
        printf("Element found at index: %d\n", result);
    }

    return 0;
}