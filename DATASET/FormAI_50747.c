//FormAI DATASET v1.0 Category: Matrix operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// function prototypes
double** create_matrix(int rows, int cols);
void fill_matrix(double** matrix, int rows, int cols);
void print_matrix(double** matrix, int rows, int cols);
double calculate_mean(double** matrix, int rows, int cols);
double calculate_variance(double** matrix, int rows, int cols);
double calculate_standard_deviation(double** matrix, int rows, int cols);

int main(void) {
    int rows, cols;
    double** matrix;
    double mean, variance, standard_deviation;

    // get user input for matrix dimensions
    printf("Enter number of rows (max %d): ", MAX_ROWS);
    scanf("%d", &rows);
    printf("Enter number of columns (max %d): ", MAX_COLS);
    scanf("%d", &cols);

    // create matrix
    matrix = create_matrix(rows, cols);

    // fill matrix with user input
    fill_matrix(matrix, rows, cols);

    // print matrix
    print_matrix(matrix, rows, cols);

    // calculate mean
    mean = calculate_mean(matrix, rows, cols);
    printf("\nThe mean is: %lf\n", mean);

    // calculate variance
    variance = calculate_variance(matrix, rows, cols);
    printf("The variance is: %lf\n", variance);

    // calculate standard deviation
    standard_deviation = calculate_standard_deviation(matrix, rows, cols);
    printf("The standard deviation is: %lf\n", standard_deviation);

    // free memory
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

/**
 * Creates a matrix with the specified number of rows and columns.
 */
double** create_matrix(int rows, int cols) {
    double** matrix = (double**) malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (double*) malloc(cols * sizeof(double));
    }
    return matrix;
}

/**
 * Fills a matrix with user input values.
 */
void fill_matrix(double** matrix, int rows, int cols) {
    printf("Enter values for matrix:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}

/**
 * Prints a matrix to the console.
 */
void print_matrix(double** matrix, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

/**
 * Calculates the mean value of a matrix.
 */
double calculate_mean(double** matrix, int rows, int cols) {
    double sum = 0.0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += matrix[i][j];
        }
    }
    return sum / (rows * cols);
}

/**
 * Calculates the variance of a matrix.
 */
double calculate_variance(double** matrix, int rows, int cols) {
    double mean = calculate_mean(matrix, rows, cols);
    double sum = 0.0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += pow((matrix[i][j] - mean), 2);
        }
    }
    return sum / (rows * cols);
}

/**
 * Calculates the standard deviation of a matrix.
 */
double calculate_standard_deviation(double** matrix, int rows, int cols) {
    double variance = calculate_variance(matrix, rows, cols);
    return sqrt(variance);
}