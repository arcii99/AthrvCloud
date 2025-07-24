//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

void square_array(double *array, int size);

int main(void) {
    double *array = (double *)malloc(MAX_SIZE * sizeof(double));
    int i;

    if (array == NULL) {
        printf("Error: unable to allocate memory.\n");
        exit(1);
    }

    for (i = 0; i < MAX_SIZE; i++) {
        array[i] = i;
    }

    square_array(array, MAX_SIZE);

    for (i = 0; i < MAX_SIZE; i++) {
        printf("%g\n", array[i]);
    }

    free(array);
    return 0;
}

void square_array(double *array, int size) {
    int i;

    for (i = 0; i < size; i++) {
        array[i] = array[i] * array[i];
    }
}