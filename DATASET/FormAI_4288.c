//FormAI DATASET v1.0 Category: Benchmarking ; Style: bold
#include <stdio.h>
#include <time.h>

#define SIZE 1000000

int main(void) {

    long long sum = 0;
    int array[SIZE];

    // Filling array with random values
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand();
    }

    clock_t tstart = clock(); // Starting the timer

    // Sequential Sum Calculation
    for (int i = 0; i < SIZE; i++) {
        sum += array[i];
    }

    clock_t tend = clock(); // Ending the timer

    printf("Sequential Sum: %lld\n", sum);
    printf("Sequential Time: %lf seconds\n", ((double)tend - tstart) / CLOCKS_PER_SEC);


    // --------------------------- PARALLEL CODE --------------------------- //

    sum = 0; // Reset sum

    tstart = clock(); // Starting the timer

    // Parallel Sum Calculation
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < SIZE; i++) {
        sum += array[i];
    }

    tend = clock(); // Ending the timer

    printf("Parallel Sum: %lld\n", sum);
    printf("Parallel Time: %lf seconds\n", ((double)tend - tstart) / CLOCKS_PER_SEC);

    return 0;
}