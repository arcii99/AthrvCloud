//FormAI DATASET v1.0 Category: Fractal Generation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to compute the fractal dimension
double fractal_dimension(int dim, int samples) {
    double sum = 0.0, d;
    int i, j, k, l, m, count;

    // Set the limit for the random numbers
    unsigned int limit = (unsigned int) pow(10, dim);

    // Generate random points and count the number of pairs
    srand(time(NULL));
    for (i = 0; i < samples; i++) {
        int x1 = rand() % limit, y1 = rand() % limit, x2, y2;
        count = 0;
        for (j = 0; j < samples; j++) {
            if (i != j) {
                x2 = rand() % limit, y2 = rand() % limit;
                d = sqrt(pow(x2-x1, 2.0) + pow(y2-y1, 2.0));
                if (d <= pow(2.0, (double) dim)) {
                    count++;
                }
            }
        }
        sum += log((double) count / (double) samples);
    }

    // Compute the fractal dimension
    return (double) dim - (sum / log(2.0));
}

int main() {
    int samples = 1000, dim = 2;
    double dimension;

    // Compute the fractal dimension
    dimension = fractal_dimension(dim, samples);
    printf("Fractal dimension of a %d-dimensional set with %d samples is %f\n", dim, samples, dimension);

    return 0;
}