//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 100000000

int main() {
    int i, x;
    double result = 0.0;
    clock_t start, end;
    float time_taken;

    start = clock();

    for (i = 1; i <= N; i++) {
        x = i * i;
        result += (1.0 / sqrt(x));
    }

    end = clock();

    time_taken = (float)(end - start) / CLOCKS_PER_SEC;

    printf("Result = %f\n", result);
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}