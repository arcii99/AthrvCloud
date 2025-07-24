//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10000

int main() {
    // Initialize the array with random integers
    srand(time(NULL));
    int array[SIZE];
    for(int i = 0; i < SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Check if the array is sorted
    bool isSorted = true;
    for(int i = 0; i < SIZE - 1; i++) {
        if(array[i] > array[i + 1]) {
            isSorted = false;
            break;
        }
    }

    // If the array is not sorted, sort it using bubble sort
    if(!isSorted) {
        for(int i = 0; i < SIZE - 1; i++) {
            for(int j = 0; j < SIZE - i - 1; j++) {
                if(array[j] > array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }

    // Print the sorted array
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
        if((i + 1) % 10 == 0) {
            printf("\n");
        }
    }

    return 0;
}