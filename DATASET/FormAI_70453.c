//FormAI DATASET v1.0 Category: Matrix operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ROWS 5
#define COLS 5

void printMatrix(int matrix[][COLS], int rows, int cols);
double mean(int matrix[][COLS], int rows, int cols);
double stdev(int matrix[][COLS], int rows, int cols);

int main()
{
    int matrix[ROWS][COLS];
    srand(time(NULL));

    // Generate random matrix
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            matrix[i][j] = rand() % 10;
        }
    }

    // Print generated matrix
    printf("Generated Matrix:\n");
    printMatrix(matrix, ROWS, COLS);

    double mean_value = mean(matrix, ROWS, COLS);
    double stdev_value = stdev(matrix, ROWS, COLS);

    printf("Mean value: %.2lf\n", mean_value);
    printf("Standard deviation value: %.2lf\n", stdev_value);

    return 0;
}

// Function to print out the matrix
void printMatrix(int matrix[][COLS], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate the mean value of the matrix
double mean(int matrix[][COLS], int rows, int cols)
{
    int sum = 0;
    double mean_value = 0.0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += matrix[i][j];
        }
    }

    mean_value = (double)sum / (double)(rows * cols);

    return mean_value;
}

// Function to calculate the standard deviation value of the matrix
double stdev(int matrix[][COLS], int rows, int cols)
{
    int sum = 0;
    double mean_value = mean(matrix, rows, cols);
    double stdev_value = 0.0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += pow((matrix[i][j] - mean_value), 2);
        }
    }

    stdev_value = sqrt((double)sum / (double)(rows * cols));

    return stdev_value;
}