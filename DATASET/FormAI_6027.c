//FormAI DATASET v1.0 Category: Benchmarking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PARANOID_THRESHOLD 50000000 // 50 million iterations

int main() {
    int i, n = 0;
    clock_t start, end;

    printf("Enter the number of iterations to benchmark:\n");
    scanf("%d", &n);

    printf("Starting benchmark...\n");
    start = clock();

    for (i = 0; i < n; i++) {
        srand(i);
        rand();
    }

    end = clock();
    printf("Benchmark completed in %lu ticks\n", end - start);

    if (n > PARANOID_THRESHOLD) {
        printf("Large number of iterations detected, verifying results...\n");

        srand(0);
        int result1 = rand();

        srand(1);
        int result2 = rand();

        srand(PARANOID_THRESHOLD);
        int result3 = rand();

        srand(PARANOID_THRESHOLD + 1);
        int result4 = rand();

        if ((result1 == result3) && (result2 == result4)) {
            printf("Results verified!\n");
        } else {
            printf("ERROR: Results do not match. Please re-run the program.\n");
        }
    }

    return 0;
}