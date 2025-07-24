//FormAI DATASET v1.0 Category: Data mining ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 5
#define COLS 3

// Function to print 2D array
void printData(double data[][COLS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%.2f ", data[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate mean
double calculateMean(double data[][COLS], int colIndex, int rows) {
    double sum = 0;
    for (int i = 0; i < rows; i++) {
        sum += data[i][colIndex];
    }
    return sum / rows;
}

// Function to calculate standard deviation
double calculateStdDev(double data[][COLS], int colIndex, int rows, double mean) {
    double sum = 0;
    for (int i = 0; i < rows; i++) {
        sum += pow((data[i][colIndex] - mean), 2);
    }
    return sqrt(sum / rows);
}

int main() {
    double data[ROWS][COLS] = {{1.2, 3.4, 2.1},
                               {4.5, 2.3, 1.5},
                               {3.2, 4.0, 2.9},
                               {1.8, 2.4, 3.9},
                               {4.1, 3.5, 2.2}};
    printf("Original Data:\n");
    printData(data, ROWS);
    printf("\n");

    // Normalize the data
    for (int i = 0; i < COLS; i++) {
        double mean = calculateMean(data, i, ROWS);
        double stdDev = calculateStdDev(data, i, ROWS, mean);
        for (int j = 0; j < ROWS; j++) {
            data[j][i] = (data[j][i] - mean) / stdDev;
        }
    }

    printf("Normalized Data:\n");
    printData(data, ROWS);
    printf("\n");

    // Find the min and max values for each column
    double minVals[COLS] = {9999, 9999, 9999};
    double maxVals[COLS] = {-9999, -9999, -9999};
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            if (data[j][i] < minVals[i]) {
                minVals[i] = data[j][i];
            }
            if (data[j][i] > maxVals[i]) {
                maxVals[i] = data[j][i];
            }
        }
    }

    printf("Min values:\n");
    for (int i = 0; i < COLS; i++) {
        printf("%.2f ", minVals[i]);
    }
    printf("\n");
    printf("Max values:\n");
    for (int i = 0; i < COLS; i++) {
        printf("%.2f ", maxVals[i]);
    }
    printf("\n");

    return 0;
}