//FormAI DATASET v1.0 Category: Data mining ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 10
#define NUM_COLS 5

int main() {
    // create a 2D array of random integer values
    int data[NUM_ROWS][NUM_COLS];
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            data[i][j] = rand() % 1000;
        }
    }

    // calculate the average value of each column
    float column_averages[NUM_COLS];
    for (int j = 0; j < NUM_COLS; j++) {
        int column_sum = 0;
        for (int i = 0; i < NUM_ROWS; i++) {
            column_sum += data[i][j];
        }
        column_averages[j] = (float) column_sum / NUM_ROWS;
    }

    // calculate the range of values in each row
    int row_ranges[NUM_ROWS];
    for (int i = 0; i < NUM_ROWS; i++) {
        int max_val = data[i][0];
        int min_val = data[i][0];
        for (int j = 1; j < NUM_COLS; j++) {
            if (data[i][j] > max_val) {
                max_val = data[i][j];
            }
            if (data[i][j] < min_val) {
                min_val = data[i][j];
            }
        }
        row_ranges[i] = max_val - min_val;
    }

    // print the results
    printf("Column averages:\n");
    for (int j = 0; j < NUM_COLS; j++) {
        printf("%f ", column_averages[j]);
    }
    printf("\n");

    printf("Row ranges:\n");
    for (int i = 0; i < NUM_ROWS; i++) {
        printf("%d ", row_ranges[i]);
    }
    printf("\n");

    return 0;
}