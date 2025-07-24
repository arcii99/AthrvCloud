//FormAI DATASET v1.0 Category: Math exercise ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 1000

void print_array(double array[], int size);
double mean(double array[], int size);
double variance(double array[], int size, double mean);
double standard_deviation(double variance);

int main() {
    double array[SIZE];
    int i;

    srand(time(0));  // Seed the random number generator

    // Populate the array with random numbers between 0 and 100
    for (i = 0; i < SIZE; i++) {
        array[i] = (double)rand() / (double)RAND_MAX * 100.0;
    }

    printf("Array:\n");
    print_array(array, SIZE);

    double mean_value = mean(array, SIZE);
    printf("\nMean: %f\n", mean_value);

    double variance_value = variance(array, SIZE, mean_value);
    printf("Variance: %f\n", variance_value);

    double standard_deviation_value = standard_deviation(variance_value);
    printf("Standard Deviation: %f\n", standard_deviation_value);

    return 0;
}

void print_array(double array[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%.2f ", array[i]);
    }

    printf("\n");
}

double mean(double array[], int size) {
    int i;
    double sum = 0.0;

    for (i = 0; i < size; i++) {
        sum += array[i];
    }

    return sum / size;
}

double variance(double array[], int size, double mean) {
    int i;
    double sum_squares = 0.0;

    for (i = 0; i < size; i++) {
        sum_squares += (array[i] - mean) * (array[i] - mean);
    }

    return sum_squares / size;
}

double standard_deviation(double variance) {
    return sqrt(variance);
}