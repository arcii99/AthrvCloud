//FormAI DATASET v1.0 Category: Benchmarking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Defining a constant for array size */
#define ARRAY_SIZE 10000

/* Function to generate random numbers between 0 and 99 inclusive */
int generateRandomNumber() {
    int num = rand() % 100;
    return num;
}

int main() {
    int i, j, temp;
    int arr[ARRAY_SIZE];

    srand(time(NULL)); /* Seed for random number generation */

    /* Filling the array with random numbers */
    for(i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = generateRandomNumber();
    }

    /* Bubble Sort Algorithm */
    clock_t start = clock(); /* Start time */
    for(i = 0; i < ARRAY_SIZE; i++) {
        for(j = i+1; j < ARRAY_SIZE; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    clock_t end = clock(); /* End time */

    /* Calculate the total time taken for sorting */
    double total_time = (double)(end - start)/CLOCKS_PER_SEC;

    /* Print out the sorted array and time taken for sorting */
    printf("Sorted array: ");
    for(i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTotal Time Taken for sorting: %f seconds", total_time);

    return 0;
}