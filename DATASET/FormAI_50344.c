//FormAI DATASET v1.0 Category: Benchmarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAX_ELEMENTS 1000000

struct timeval start, end;

int main() {
    int array[MAX_ELEMENTS];
    int i, j;
    long long sum = 0;

    // initialize array with random values
    for(i=0; i<MAX_ELEMENTS; i++) {
        array[i] = rand() % 100;
    }

    // start timer
    gettimeofday(&start, NULL);

    // calculate sum using nested loop
    for(i=0;i<MAX_ELEMENTS;i++) {
        for(j=0;j<MAX_ELEMENTS;j++) {
            sum += array[i] * array[j];
        }
    }

    // stop timer 
    gettimeofday(&end, NULL);

    // calculate elapsed time
    long seconds = (end.tv_sec - start.tv_sec);
    long microseconds = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);

    // print results
    printf("Sum = %lld\n", sum);
    printf("Time taken: %ld microseconds", microseconds);

    return 0;
}