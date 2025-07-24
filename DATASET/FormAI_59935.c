//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000

// Function to calculate the sum of two arrays element-wise
void addArrays(int *arr1, int *arr2, int *result, int size) {
    for(int i=0; i<size; i++) {
        result[i] = arr1[i] + arr2[i];
    }
}

int main() {
    int *arr1 = (int*) malloc(SIZE * sizeof(int));
    int *arr2 = (int*) malloc(SIZE * sizeof(int));
    int *result = (int*) malloc(SIZE * sizeof(int));

    // Initialize arrays with random values
    for(int i=0; i<SIZE; i++) {
        arr1[i] = rand() % 100;
        arr2[i] = rand() % 100;
    }

    // Add arrays element-wise
    addArrays(arr1, arr2, result, SIZE);

    // Print the result
    for(int i=0; i<SIZE; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(arr1);
    free(arr2);
    free(result);

    return 0;
}