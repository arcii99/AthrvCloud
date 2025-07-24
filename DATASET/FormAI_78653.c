//FormAI DATASET v1.0 Category: Educational ; Style: single-threaded
// Single-threaded program to find the sum of an array of integers

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main() {
    int arr[SIZE];
    int sum = 0;

    // fill array with random integers
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 10;
    }

    // calculate sum of array
    for (int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }

    // print array and sum
    printf("Array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nSum: %d", sum);

    return 0;
}