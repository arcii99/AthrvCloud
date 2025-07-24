//FormAI DATASET v1.0 Category: Benchmarking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random array
void generateArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

// Function to print array
void printArray(int *array, int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to perform bubble sort
void bubbleSort(int *array, int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Main function
int main() {
    int size = 10000;
    int *array = (int*) malloc(size * sizeof(int));
    generateArray(array, size);
    printArray(array, size);
    clock_t start = clock();
    bubbleSort(array, size);
    clock_t end = clock();
    double time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("Execution Time: %f seconds\n", time_taken);
    printArray(array, size);
    free(array);
    return 0;
}