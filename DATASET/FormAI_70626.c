//FormAI DATASET v1.0 Category: Data mining ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

// function to calculate the Euclidean distance
double euclidean_distance(double *a, double *b, int features)
{
    double distance = 0.0;
    for (int i = 0; i < features; i++) {
        distance += pow((a[i] - b[i]), 2);
    }
    return sqrt(distance);
}

int main()
{
    srand(time(0));
    int samples = 100; // number of data points
    int features = 3; // number of attributes for each point

    // generate random data points
    double data[samples][features];
    for (int i = 0; i < samples; i++) {
        for (int j = 0; j < features; j++) {
            data[i][j] = (double)(rand()) / RAND_MAX;
        }
    }

    // calculate the distance between data points
    double distance_matrix[samples][samples];
    for (int i = 0; i < samples; i++) {
        for (int j = 0; j < samples; j++) {
            distance_matrix[i][j] = euclidean_distance(data[i], data[j], features);
        }
    }

    // print the distance matrix
    printf("Distance matrix:\n");
    for (int i = 0; i < samples; i++) {
        for (int j = 0; j < samples; j++) {
            printf("%0.2f ", distance_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}