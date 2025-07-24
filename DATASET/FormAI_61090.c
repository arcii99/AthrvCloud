//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000
#define MAX_VALUE 10000

int main() {

    srand(time(NULL));
    int array[SIZE];
    int i, j, temp;

    // Fill the array with random values
    for (i=0; i<SIZE; i++) {
        array[i] = rand() % MAX_VALUE;
    }

    // Sort the array using bubble sort algorithm
    for (i=0; i<SIZE-1; i++) {
        for (j=0; j<SIZE-i-1; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    // Print the sorted array
    printf("Sorted array:\n");
    for (i=0; i<SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}