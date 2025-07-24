//FormAI DATASET v1.0 Category: Scientific ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

int main(void)
{
    int array[ARRAY_SIZE];
    int i, j, temp;

    /* Initialize random number generator */
    srand(time(NULL));

    /* Fill array with random numbers */
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    /* Print original array */
    printf("Original Array:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");

    /* Sort the array using bubble sort */
    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        for (j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                /* Swap the two elements */
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    /* Print sorted array */
    printf("Sorted Array (using Bubble Sort):\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");

    /* Sort the array using insertion sort */
    for (i = 1; i < ARRAY_SIZE; i++) {
        temp = array[i];
        j = i - 1;
        while (j >= 0 && temp < array[j]) {
            /* Move the larger element to the right */
            array[j + 1] = array[j];
            j--;
        }
        /* Insert the temp element */
        array[j + 1] = temp;
    }

    /* Print sorted array */
    printf("Sorted Array (using Insertion Sort):\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");

    return 0;
}