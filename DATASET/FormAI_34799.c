//FormAI DATASET v1.0 Category: Benchmarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    int size = 1000000;
    if (argc > 1) {
        size = atoi(argv[1]);
    }

    int *array = malloc(sizeof(int) * size);
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);

    // Fill array with random numbers
    for (int i = 0; i < size; i++) {
        array[i] = rand();
    }

    // Sort array using Bubble Sort algorithm
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    gettimeofday(&end, NULL);

    double execution_time = (double) (end.tv_usec - start.tv_usec) / 1000000 + (double) (end.tv_sec - start.tv_sec);
    printf("Sorted %d elements in %.6lf seconds\n", size, execution_time);

    free(array);
    return 0;
}