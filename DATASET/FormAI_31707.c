//FormAI DATASET v1.0 Category: Benchmarking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The array size to sort
#define ARRAY_SIZE 10000

// Timing utility function
double elapsedTime(clock_t start, clock_t end) {
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

// Bubble sort algorithm
void bubbleSort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

// Selection sort algorithm
void selectionSort(int a[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n-1; i++) {
        minIndex = i;
        for (j = i+1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}

// Insertion sort algorithm
void insertionSort(int a[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = a[i];
        j = i-1;
        while (j >= 0 && a[j] > temp) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

int main() {
    int i, a[ARRAY_SIZE];

    // Initialize the array with random values
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        a[i] = rand() % 10000;
    }

    // Test the bubble sort algorithm
    clock_t start = clock();
    bubbleSort(a, ARRAY_SIZE);
    clock_t end = clock();
    printf("Bubble sort took %.4f seconds.\n", elapsedTime(start, end));
    
    // Test the selection sort algorithm
    start = clock();
    selectionSort(a, ARRAY_SIZE);
    end = clock();
    printf("Selection sort took %.4f seconds.\n", elapsedTime(start, end));
    
    // Test the insertion sort algorithm
    start = clock();
    insertionSort(a, ARRAY_SIZE);
    end = clock();
    printf("Insertion sort took %.4f seconds.\n", elapsedTime(start, end));

    return 0;
}