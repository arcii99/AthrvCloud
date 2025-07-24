//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000 // setting array size to 1 million

int main(void) {

    int array[ARRAY_SIZE], i, j, temp;

    // generating random integers to fill the array
    srand(time(NULL));
    for(i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;
    }

    // printing the unsorted array
    printf("Unsorted array: \n");
    for(i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }

    // implementing bubble sort algorithm
    for(i = 0; i < ARRAY_SIZE - 1; i++) {
        for(j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if(array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    // printing the sorted array
    printf("\nSorted array: \n");
    for(i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}