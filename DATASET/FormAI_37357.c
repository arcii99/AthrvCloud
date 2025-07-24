//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ARRAY_SIZE 100000

double calc_mean(int *data) {
    double sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += data[i];
    }
    return sum / ARRAY_SIZE;
}

double calc_std_dev(int *data, double mean) {
    double sum_of_squares = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum_of_squares += pow(data[i] - mean, 2);
    }
    return sqrt(sum_of_squares / ARRAY_SIZE);
}

int main() {
    int data[ARRAY_SIZE];

    // Generate random data
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        data[i] = rand() % 1000 + 1;
    }

    // Calculate mean and standard deviation
    double mean = calc_mean(data);
    double std_dev = calc_std_dev(data, mean);

    // Print results
    printf("Mean: %f\n", mean);
    printf("Standard deviation: %f\n", std_dev);

    return 0;
}