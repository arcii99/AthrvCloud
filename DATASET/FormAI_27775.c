//FormAI DATASET v1.0 Category: Benchmarking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

int main() {
    double a[N], b[N], c[N], d[N], e[N];
    int i, j;

    // Populate arrays with random values
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        a[i] = (double)rand() / RAND_MAX * 1000.0;
        b[i] = (double)rand() / RAND_MAX * 1000.0;
        c[i] = (double)rand() / RAND_MAX * 1000.0;
        d[i] = (double)rand() / RAND_MAX * 1000.0;
        e[i] = (double)rand() / RAND_MAX * 1000.0;
    }

    // Benchmarking starts here
    clock_t start = clock();

    // Operation 1: Multiply each element of a with the corresponding element of b
    for (i = 0; i < N; i++) {
        a[i] *= b[i];
    }

    // Operation 2: Add each element of c with the corresponding element of d
    for (i = 0; i < N; i++) {
        c[i] += d[i];
    }

    // Operation 3: Subtract 5 from each element of e
    for (i = 0; i < N; i++) {
        e[i] -= 5.0;
    }

    // Operation 4: Multiply each element of a with the corresponding element of e
    for (i = 0; i < N; i++) {
        a[i] *= e[i];
    }

    // Operation 5: Add each element of c with the corresponding element of e
    for (i = 0; i < N; i++) {
        c[i] += e[i];
    }

    // Benchmarking ends here
    clock_t end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print the results
    printf("Results:\n");
    printf("a[0] = %lf\n", a[0]);
    printf("b[0] = %lf\n", b[0]);
    printf("c[0] = %lf\n", c[0]);
    printf("d[0] = %lf\n", d[0]);
    printf("e[0] = %lf\n", e[0]);
    printf("cpu_time_used = %lf seconds\n", cpu_time_used);

    return 0;
}