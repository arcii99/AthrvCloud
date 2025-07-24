//FormAI DATASET v1.0 Category: Scientific ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void square(double arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i]*arr[i];
    }
}

void printArray(double arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%f ", arr[i]);
    }
}

int main(void) {
    double arr[SIZE] = {1.2, 3.4, 5.6, 7.8, 9.10, 11.12, 13.14, 15.16, 17.18, 19.20};   
    printf("Original array: \n");
    printArray(arr, SIZE);
    square(arr, SIZE);
    printf("\nSquared array: \n");
    printArray(arr, SIZE);
    return 0;
}