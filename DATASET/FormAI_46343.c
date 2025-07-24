//FormAI DATASET v1.0 Category: Benchmarking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100
#define MAX_ITERATIONS 100000000

double time_difference(struct timespec start, struct timespec end) {
    double ns = (end.tv_nsec - start.tv_nsec) / 1000000000.0;
    double s = end.tv_sec - start.tv_sec;
    return s + ns;
}

double sum_array(int *arr, int n) {
    int i;
    double sum = 0;
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int numbers[MAX_NUMBERS];
    int i, j, k;
    double sum = 0, elapsed_time;

    srand(time(NULL));

    for (i = 0; i < MAX_NUMBERS; i++) {
        numbers[i] = rand();
    }

    struct timespec start, end;

    clock_gettime(CLOCK_REALTIME, &start);

    for (k = 0; k < MAX_ITERATIONS; k++) {
        sum += sum_array(numbers, MAX_NUMBERS);
    }

    clock_gettime(CLOCK_REALTIME, &end);

    elapsed_time = time_difference(start, end);

    printf("Time taken: %lf seconds\n", elapsed_time);
    printf("Sum: %lf\n", sum);

    return 0;
}