//FormAI DATASET v1.0 Category: Benchmarking ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define N 1000000

int main() {
    double *a = (double *) malloc(N * sizeof(double));
    double *b = (double *) malloc(N * sizeof(double));

    // initialize arrays with random doubles
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        a[i] = (double) rand() / RAND_MAX;
        b[i] = (double) rand() / RAND_MAX;
    }

    double sum = 0;

    #pragma omp parallel for reduction(+:sum) // use OpenMP for parallelization
    for (int i = 0; i < N; i++) {
        sum += a[i] * b[i];
    }

    printf("Dot product: %f\n", sum);

    free(a);
    free(b);

    return 0;
}