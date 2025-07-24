//FormAI DATASET v1.0 Category: Benchmarking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

double get_wall_time() {
    struct timeval time;
    if (gettimeofday(&time,NULL)) {
        return 0;
    }
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}

int cmpfunc(const void * a, const void * b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int* arr = malloc(sizeof(int) * SIZE);
    int i;

    //Initialize array with random values
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    //Start timer
    double start = get_wall_time();

    //Sort array using Quick Sort algorithm from stdlib.h
    qsort(arr, SIZE, sizeof(int), cmpfunc);

    //Stop timer and get elapsed time
    double end = get_wall_time();
    double elapsed_time = end - start;

    printf("Time taken for sorting %d integers: %f seconds\n", SIZE, elapsed_time);

    free(arr);

    return 0;
}