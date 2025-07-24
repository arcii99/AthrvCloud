//FormAI DATASET v1.0 Category: Sorting ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program will create a random array of integers
   and sort them using the bubble sort algorithm.
   The size of the array and the range of the values can
   be adjusted using the constants below. */

#define ARRAY_SIZE 100
#define VALUE_RANGE 1000

/* Function to swap two values in an array. */

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Function to sort an array using bubble sort. */

void bubble_sort(int array[], int size) {
    int i, j;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

/* Main function to create an array of random integers and sort them. */

int main(void) {
    int i;
    
    /* Seed the random number generator. */
    srand(time(NULL));
    
    /* Create the array of integers. */
    int array[ARRAY_SIZE];
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % VALUE_RANGE;
    }
    
    /* Print the unsorted array. */
    printf("Unsorted array:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    /* Sort the array. */
    bubble_sort(array, ARRAY_SIZE);
    
    /* Print the sorted array. */
    printf("Sorted array:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return 0;
}