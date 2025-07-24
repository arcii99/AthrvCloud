//FormAI DATASET v1.0 Category: Benchmarking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

int array[MAX];

void populateArray() {
    // fill the array with random integers
    srand(time(NULL));
    int i;
    for (i = 0; i < MAX; i++) {
        array[i] = rand();
    }
}

void bubbleSort() {
    // implement bubble sort algorithm
    int i,j,temp;

    for (i = 0; i < MAX-1; i++) {
        for (j = 0; j < MAX-i-1; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void quickSort(int left, int right) {
    // implement quick sort algorithm
    int i = left, j = right;
    int pivot = array[(left+right)/2];
    int temp;

    while (i <= j) {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j)
        quickSort(left, j);
    if (i < right)
        quickSort(i, right);
}

int main() {
    clock_t start, end;
    double timeTaken;

    // populate array with random integers
    populateArray();

    // measure time taken by bubble sort algorithm
    start = clock();
    bubbleSort();
    end = clock();
    timeTaken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by bubble sort: %f seconds\n", timeTaken);

    // populate array with random integers again
    populateArray();

    // measure time taken by quick sort algorithm
    start = clock();
    quickSort(0, MAX-1);
    end = clock();
    timeTaken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by quick sort: %f seconds\n", timeTaken);

    return 0;
}