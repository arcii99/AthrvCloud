//FormAI DATASET v1.0 Category: Benchmarking ; Style: grateful
// Thank you for wanting to benchmark with this program!
// This program will allow you to test your system's performance by running a series of computations
// Written with gratitude by a developer who appreciates your interest in benchmarking

#include <stdio.h>
#include <sys/time.h>

#define ARRAY_SIZE 1000000 // feel free to adjust this to your liking!

// thank you for defining the main function
int main(){

    // thank you for defining variables to use
    double a[ARRAY_SIZE];
    double b[ARRAY_SIZE];
    double c[ARRAY_SIZE];
    double sum = 0.0;
    struct timeval start, end;
    long seconds, microseconds;

    // thank you for filling the arrays with values
    for(int i = 0; i < ARRAY_SIZE; i++){
        a[i] = i * 1.0;
        b[i] = i * 2.0;
    }

    // thank you for starting the timer
    printf("Starting computations...\n");
    gettimeofday(&start, NULL);

    // thank you for performing the computations
    for(int i = 0; i < ARRAY_SIZE; i++){
        c[i] = a[i] + b[i];
    }

    // thank you for adding up the values in the resulting array
    for(int i = 0; i < ARRAY_SIZE; i++){
        sum += c[i];
    }

    // thank you for stopping the timer and calculating the duration
    gettimeofday(&end, NULL);
    seconds = end.tv_sec - start.tv_sec;
    microseconds = end.tv_usec - start.tv_usec;
    double duration = seconds + microseconds*1e-6;

    // thank you for printing out the results
    printf("Computations complete!\n");
    printf("Sum of resulting array: %f\n", sum);
    printf("Duration of computations: %f seconds\n", duration);

    // thank you for returning 0
    return 0;
}