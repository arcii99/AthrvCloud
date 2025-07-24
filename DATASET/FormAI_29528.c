//FormAI DATASET v1.0 Category: Data mining ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 100
#define MAX_COLS 100

void generateData(float data[MAX_ROWS][MAX_COLS], int numRows, int numCols) {
    srand(time(NULL));

    float min = 0;
    float max = 100;

    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < numCols; j++) {
            // Generate random float between min and max
            data[i][j] = ((float)rand() / RAND_MAX * (max - min)) + min;
        }
    }
}

float calculateAverage(float data[MAX_ROWS][MAX_COLS], int numRows, int numCols) {
    float total = 0;
    int count = 0;

    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < numCols; j++) {
            total += data[i][j];
            count++;
        }
    }

    return total / count;
}

int main() {
    float data[MAX_ROWS][MAX_COLS];
    int numRows = 10;
    int numCols = 5;

    // Generate random data
    generateData(data, numRows, numCols);

    // Print out the data
    printf("Data:\n");
    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < numCols; j++) {
            printf("%.2f ", data[i][j]);
        }
        printf("\n");
    }

    // Calculate the average of the data
    float avg = calculateAverage(data, numRows, numCols);
    printf("\nAverage: %.2f\n", avg);

    return 0;
}