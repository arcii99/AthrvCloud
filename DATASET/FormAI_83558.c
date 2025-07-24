//FormAI DATASET v1.0 Category: Data mining ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 5

int main() {
    int data[MAX_ROWS][MAX_COLS] = {{1, 2, 3, 4, 5},
                                    {6, 7, 8, 9, 10},
                                    {11, 12, 13, 14, 15},
                                    {16, 17, 18, 19, 20},
                                    {21, 22, 23, 24, 25},
                                    {26, 27, 28, 29, 30},
                                    {31, 32, 33, 34, 35},
                                    {36, 37, 38, 39, 40},
                                    {41, 42, 43, 44, 45},
                                    {46, 47, 48, 49, 50}};

    int i, j, sum_row, min_row, max_row, avg_row;

    printf("The dataset has %d rows and %d columns.\n", MAX_ROWS, MAX_COLS);

    // Calculate sum, min, max, and avg for each row
    for (i = 0; i < MAX_ROWS; i++) {
        sum_row = 0;
        min_row = data[i][0];
        max_row = data[i][0];
        
        for (j = 0; j < MAX_COLS; j++) {
            sum_row += data[i][j];
            if (data[i][j] < min_row) {
                min_row = data[i][j];
            }
            if (data[i][j] > max_row) {
                max_row = data[i][j];
            }
        }

        avg_row = sum_row / MAX_COLS;
        printf("Row %d: Sum = %d, Min = %d, Max = %d, Avg = %d\n", i + 1, sum_row, min_row, max_row, avg_row);
    }

    // Find the row with the highest average value
    int max_avg_index = 0;
    int max_avg = 0;

    for (i = 0; i < MAX_ROWS; i++) {
        sum_row = 0;
        for (j = 0; j < MAX_COLS; j++) {
            sum_row += data[i][j];
        }

        avg_row = sum_row / MAX_COLS;
        if (avg_row > max_avg) {
            max_avg = avg_row;
            max_avg_index = i;
        }
    }

    printf("Row %d has the highest average value of %d.\n", max_avg_index + 1, max_avg);

    return 0;
}