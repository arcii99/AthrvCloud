//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: scalable
#include <stdio.h>

#define MAX_ARRAY_SIZE 1000

// function to multiply each element of an array with a given scalar
void scalar_multiply(int *arr, int scalar, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] * scalar;
    }
}

// function to add two arrays element-wise
void element_wise_addition(int *arr1, int *arr2, int size) {
    for (int i = 0; i < size; i++) {
        arr1[i] = arr1[i] + arr2[i];
    }
}

int main() {
    int array1[MAX_ARRAY_SIZE];
    int array2[MAX_ARRAY_SIZE];

    // initialize the arrays with random values
    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        array1[i] = i + 1;
        array2[i] = i + 3;
    }
    int scalar = 5; // scalar to multiply array1 with

    // Perform operations on the arrays
    scalar_multiply(array1, scalar, MAX_ARRAY_SIZE);
    element_wise_addition(array1, array2, MAX_ARRAY_SIZE);

    // print the resultant array
    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        printf("%d ", array1[i]);
    }
    return 0;
}