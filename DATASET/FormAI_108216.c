//FormAI DATASET v1.0 Category: Benchmarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEN_MICROSECONDS 10000

int main()
{
    // Get the current time
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Perform some operation
    printf("Let's count to a million!\n");
    for (int i = 0; i < 1000000; i++) {
        printf("%d\n", i);
    }

    // Get the current time again
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate the elapsed time in microseconds
    double elapsed_time = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;

    // Cheerful message to show off our results!
    printf("Wow! We counted to a million in %0.2lf microseconds! That's amazing!\n", elapsed_time);

    // Check if we completed our task within 10 microseconds
    if (elapsed_time <= TEN_MICROSECONDS) {
        printf("We did it in less than 10 microseconds! Hooray!\n");
    } else {
        printf("Oops, it took us more than 10 microseconds. Let's try again!\n");
    }

    return 0;
}