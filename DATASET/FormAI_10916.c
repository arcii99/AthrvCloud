//FormAI DATASET v1.0 Category: Data mining ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 5
#define THRESHOLD 0.5

// Function to generate random values between 0 and 1;
double rand_double() {
    double scale = rand() / (double) RAND_MAX;
    return scale;
}

// Function to calculate the mean of each column in the matrix;
void calculate_mean(double matrix[][COLUMNS], double mean[]) {
    int i, j;
    double sum;

    for (i = 0; i < COLUMNS; i++) {
        sum = 0;
        for (j = 0; j < ROWS; j++) {
            sum += matrix[j][i];
        }
        mean[i] = sum / ROWS;
    }
}

// Function to normalize the matrix by subtracting each value with the mean of that column;
void normalize_matrix(double matrix[][COLUMNS], double mean[]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            matrix[i][j] -= mean[j];
        }
    }
}

// Function to print the matrix
void print_matrix(double matrix[][COLUMNS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    double matrix[ROWS][COLUMNS];
    double mean[COLUMNS];
    int i, j;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Fill the matrix with random values
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            matrix[i][j] = rand_double();
        }
    }

    printf("Matrix before normalization:\n");
    print_matrix(matrix);

    calculate_mean(matrix, mean);

    printf("Mean of each column:\n");
    for (i = 0; i < COLUMNS; i++) {
        printf("%.2f ", mean[i]);
    }
    printf("\n");

    normalize_matrix(matrix, mean);

    printf("Matrix after normalization:\n");
    print_matrix(matrix);

    return 0;
}