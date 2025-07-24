//FormAI DATASET v1.0 Category: Sorting ; Style: expert-level
// A unique C Sorting example program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000

void print_array(int array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bubble_sort(int array[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    int array[ARRAY_SIZE];
    int i;

    // seed the random number generator
    srand(time(NULL));

    // fill the array with random numbers between 0 and 999 inclusive
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;
    }

    // print the unsorted array
    printf("Unsorted array:\n");
    print_array(array, ARRAY_SIZE);

    // sort the array using bubble sort
    bubble_sort(array, ARRAY_SIZE);

    // print the sorted array
    printf("Sorted array:\n");
    print_array(array, ARRAY_SIZE);

    return 0;
}