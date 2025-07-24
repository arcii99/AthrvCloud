//FormAI DATASET v1.0 Category: Digital signal processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define matrix dimensions
#define N 4

// Define coefficient matrix
float coef_mat[N][N] = {
    {5, 2, 1, 0},
    {-1, 4, 2, 1},
    {2, -1, 3, 2},
    {1, -3, 2, 6}
};

// Define signal vector
float signal_vec[N] = {1, 2, 3, 4};

// Define output vector
float output_vec[N] = {0, 0, 0, 0};

// Define main function
int main() {

    // Initialize parameters
    int i, j, k;

    // Perform matrix-vector multiplication
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            output_vec[i] += coef_mat[i][j] * signal_vec[j];
        }
    }

    // Print output vector
    printf("Output Vector: [");
    for (k = 0; k < N; k++) {
        printf("%f ", output_vec[k]);
    }
    printf("]\n");

    return 0;
}