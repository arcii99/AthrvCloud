//FormAI DATASET v1.0 Category: Recursive ; Style: configurable
#include <stdio.h>

// Recursive function to calculate the sum of all elements in an array
int sum(int arr[], int size) {
    if (size == 1) {    // Base case: array has only one element
        return arr[0];
    } else {
        return arr[size-1] + sum(arr, size-1);    // Recursive case: add last element to sum of all others
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("The sum of all elements in the array is: %d", sum(arr, size));
    return 0;
}