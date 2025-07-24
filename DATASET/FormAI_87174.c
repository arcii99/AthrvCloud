//FormAI DATASET v1.0 Category: Benchmarking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOOPS 10000 // number of loops to average over
#define ARRAY_SIZE 1000000 // size of the array to sort
#define MAX_VAL 1000 // maximum value of each element in the array

void bubbleSort(int arr[], int n) { // bubble sort algorithm
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[ARRAY_SIZE], i, j;
    double time_spent;
    clock_t begin, end;

    printf("Generating random array of %d numbers...\n", ARRAY_SIZE);
    srand(time(0)); // initialize random seed
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % MAX_VAL; // fill array with random values
    }

    printf("Sorting array using bubble sort algorithm %d times...\n", LOOPS);
    begin = clock(); // start timer
    for (i = 0; i < LOOPS; i++) {
        bubbleSort(arr, ARRAY_SIZE); // sort array using bubble sort
    }
    end = clock(); // end timer

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC; // calculate time spent in seconds
    printf("Time spent sorting array using bubble sort algorithm: %lf seconds.\n", time_spent);

    return 0;
}