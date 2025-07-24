//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000000

int main() {

    long int *array = (long int*)malloc(SIZE * sizeof(long int)); //Allocate memory

    for(long int i = 0; i < SIZE; i++) {
        array[i] = i;
    }

    long int sum = 0;

    for(long int i = 0; i < SIZE; i++) {
        sum += array[i];
    }

    printf("Sum is: %ld\n", sum);

    free(array); //Free the allocated memory

    return 0;
}