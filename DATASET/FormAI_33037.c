//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 100000000

int main()
{
    int *array = (int*) malloc(sizeof(int) * ARRAY_SIZE);
    int i, j, temp;

    // Initialize the array in reverse order
    for(i = ARRAY_SIZE - 1, j = 0; i >= 0; i--, j++) {
        array[i] = j;
    }

    // Perform bubble sort
    for(i = 0; i < ARRAY_SIZE; i++) {
        for(j = 1; j < ARRAY_SIZE - i; j++) {
            if(array[j - 1] > array[j]) {
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        }
    }

    // Print the first 10 elements of the sorted array
    for(i = 0; i < 10; i++) {
        printf("%d\n", array[i]);
    }

    // Free dynamically allocated memory
    free(array);

    return 0;
}