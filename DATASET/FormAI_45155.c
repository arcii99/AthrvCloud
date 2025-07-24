//FormAI DATASET v1.0 Category: Data mining ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int i, j;

    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            matrix[i][j] = rand();
        }
    }

    int sum = 0;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            sum += matrix[i][j];
        }
    }

    int avg = sum / (MAX_ROWS * MAX_COLS);
    printf("Average value of elements in matrix: %d\n", avg);

    int max = matrix[0][0], min = matrix[0][0];
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }

    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);

    return 0;
}