//FormAI DATASET v1.0 Category: Benchmarking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000
#define NUM_TIMES 1000000

double get_time() {
    struct timespec time;
    clock_gettime(CLOCK_REALTIME, &time);
    return time.tv_sec + (double) time.tv_nsec / 1000000000;
}

void create_random_array(int *array, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand();
    }
}

int compare_ints(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void run_benchmark() {
    int array[ARRAY_SIZE];
    create_random_array(array, ARRAY_SIZE);
    double start_time = get_time();
    for (int i = 0; i < NUM_TIMES; i++) {
        qsort(array, ARRAY_SIZE, sizeof(int), compare_ints);
    }
    double end_time = get_time();
    double total_time = end_time - start_time;
    printf("Total time: %f seconds\n", total_time);
}

int main() {
    run_benchmark();
    return 0;
}