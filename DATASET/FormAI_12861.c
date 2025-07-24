//FormAI DATASET v1.0 Category: Benchmarking ; Style: introspective
#include<stdio.h>
#include<time.h>

int main() {
    clock_t start_time, end_time;
    double time_used;

    // Starting the timer for the benchmarking process
    start_time = clock();

    // The code whose time is to be benchmarked
    for(int i = 0; i < 100000000; i++) {
        // some code
    }

    // Ending the timer
    end_time = clock();

    // Calculating the time used
    time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    // Display the time used in seconds
    printf("The benchmarking process took %f seconds.\n", time_used);

    return 0;
}