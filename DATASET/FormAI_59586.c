//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// A function to exchange two values in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// A function to perform bubble sort on an array
void bubbleSort(int arr[], int n) {
    int i, j;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// A function to generate random numbers
void generateRandomArray(int arr[], int n) {
    srand(time(0));
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

int main() {
    int arr[ARRAY_SIZE];
    generateRandomArray(arr, ARRAY_SIZE);

    clock_t start = clock(); // Start measuring the time
    bubbleSort(arr, ARRAY_SIZE);
    clock_t end = clock(); // Stop measuring the time
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken: %lf seconds\n", time_spent);

    return 0;
}