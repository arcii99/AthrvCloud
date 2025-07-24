//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_VALUES 1000000

// Function to populate an array with random integers
void fill_array(int *arr, int size) {
    for(int i=0; i<size; i++) {
        arr[i] = rand() % size;
    }
}

// Function to sort an array using bubble sort algorithm
void bubble_sort(int *arr, int size) {
    int temp;
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int *values = malloc(sizeof(int) * NUM_OF_VALUES);

    // Fill the array with random integers
    srand(time(NULL));
    fill_array(values, NUM_OF_VALUES);

    // Sort the array using bubble sort algorithm
    bubble_sort(values, NUM_OF_VALUES);

    // Print the sorted array
    printf("Sorted array:\n");
    for(int i=0; i<NUM_OF_VALUES; i++) {
        printf("%d ", values[i]);
    }

    free(values);
    return 0;
}