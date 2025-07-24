//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000 // 1 million elements in the array

int main() {
    int array[ARRAY_SIZE]; // the array of integers
    int i, j, temp, idx, min_val;

    // Generate random elements in the array
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;
    }

    // Perform selection sort on the array
    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        min_val = array[i];
        idx = i;
        for (j = i + 1; j < ARRAY_SIZE; j++) {
            if (array[j] < min_val) {
                min_val = array[j];
                idx = j;
            }
        }
        temp = array[i];
        array[i] = array[idx];
        array[idx] = temp;
    }

    // Print the sorted array
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}