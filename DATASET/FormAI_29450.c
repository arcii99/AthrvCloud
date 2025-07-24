//FormAI DATASET v1.0 Category: Digital signal processing ; Style: multivariable
#include <stdio.h>

#define NROWS 3
#define NCOLS 4
#define NCHANNELS 2

void printMatrix(double matrix[][NCOLS][NCHANNELS], int rows) {
    int i, j, k;

    printf("\nPrinting matrix:\n");

    for (i = 0; i < rows; i++) {
        printf("row %d:\n", i + 1);

        for (j = 0; j < NCOLS; j++) {

            printf("\tcolumn %d: ", j + 1);

            for (k = 0; k < NCHANNELS; k++) {
                printf("%.1f ", matrix[i][j][k]);
            }

            printf("\n");
        }

        printf("\n");
    }
}

int main() {
    double matrix[NROWS][NCOLS][NCHANNELS] = {
        {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}, {7.0, 8.0}},
        {{9.0, 10.0}, {11.0, 12.0}, {13.0, 14.0}, {15.0, 16.0}},
        {{17.0, 18.0}, {19.0, 20.0}, {21.0, 22.0}, {23.0, 24.0}}
    };

    printMatrix(matrix, NROWS);

    int i, j, k;

    for (i = 0; i < NROWS; i++) {
        for (j = 0; j < NCOLS; j++) {
            for (k = 0; k < NCHANNELS; k++) {
                matrix[i][j][k] *= -1;
            }
        }
    }

    printf("\nAfter multiplying the matrix by -1:\n");
    printMatrix(matrix, NROWS);

    return 0;
}