//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
    // Declare variables
    int i, j, temp;
    int array[ARRAY_SIZE];
    
    // Initialize array with random values
    srand(time(NULL));
    for(i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % ARRAY_SIZE;
    }
    
    // Bubble Sort algorithm
    for(i = 0; i < ARRAY_SIZE - 1; i++) {
        for(j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if(array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    
    // Print sorted array
    for(i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    
    return 0;
}