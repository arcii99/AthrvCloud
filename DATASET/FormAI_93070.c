//FormAI DATASET v1.0 Category: Benchmarking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
int generateRandom(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main() {
    // Initialize variables
    int numElements = 100000000;
    int* array = (int*)malloc(numElements*sizeof(int));

    // Fill array with random numbers
    srand(time(0));
    for(int i=0; i<numElements; i++) {
        array[i] = generateRandom(0,100);
    }

    // Start time for benchmarking
    clock_t start = clock();

    // Sort array using quicksort algorithm
    quicksort(array, 0, numElements-1);

    // End time for benchmarking
    clock_t end = clock();

    // Calculate time taken for benchmarking
    double timeTaken = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements using quicksort: %f sec\n", numElements, timeTaken);

    // Free allocated memory
    free(array);

    return 0;
}

// Function implementing quicksort algorithm
void quicksort(int* array, int left, int right) {
    int i = left;
    int j = right;
    int temp;
    int pivot = array[(left + right)/2];

    while(i <= j) {
        while(array[i] < pivot) {
            i++;
        }
        while(array[j] > pivot) {
            j--;
        }
        if(i <= j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }

    if(left < j)
        quicksort(array, left, j);
    if(right > i)
        quicksort(array, i, right);
}