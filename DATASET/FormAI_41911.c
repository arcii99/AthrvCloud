//FormAI DATASET v1.0 Category: Data mining ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 5

void print_matrix(int matrix[][MAX_COLS], int num_rows, int num_cols);
void compute_averages(int matrix[][MAX_COLS], int num_rows, int num_cols, float *row_avg, float *col_avg);
void find_min_max(int matrix[][MAX_COLS], int num_rows, int num_cols, int *min_val, int *max_val);

int main() {
    int data[MAX_ROWS][MAX_COLS] = {
        { 1, 2, 3, 4, 5 },
        { 6, 7, 8, 9, 10 },
        { 11, 12, 13, 14, 15 },
        { 16, 17, 18, 19, 20 },
        { 21, 22, 23, 24, 25 },
        { 26, 27, 28, 29, 30 },
        { 31, 32, 33, 34, 35 },
        { 36, 37, 38, 39, 40 },
        { 41, 42, 43, 44, 45 },
        { 46, 47, 48, 49, 50 }
    };
    
    // Compute row and column averages
    float row_avg[MAX_ROWS];
    float col_avg[MAX_COLS];
    compute_averages(data, MAX_ROWS, MAX_COLS, row_avg, col_avg);
    
    printf("Row averages:\n");
    for (int i = 0; i < MAX_ROWS; i++) {
        printf("%f\n", row_avg[i]);
    }
    
    printf("Column averages:\n");
    for (int j = 0; j < MAX_COLS; j++) {
        printf("%f\n", col_avg[j]);
    }
    
    // Find minimum and maximum values
    int min_val, max_val;
    find_min_max(data, MAX_ROWS, MAX_COLS, &min_val, &max_val);
    
    printf("Minimum value: %d\n", min_val);
    printf("Maximum value: %d\n", max_val);
    
    return 0;
}

void print_matrix(int matrix[][MAX_COLS], int num_rows, int num_cols) {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void compute_averages(int matrix[][MAX_COLS], int num_rows, int num_cols, float *row_avg, float *col_avg) {
    // Compute row averages
    for (int i = 0; i < num_rows; i++) {
        float sum = 0.0;
        for (int j = 0; j < num_cols; j++) {
            sum += matrix[i][j];
        }
        row_avg[i] = sum / num_cols;
    }
    
    // Compute column averages
    for (int j = 0; j < num_cols; j++) {
        float sum = 0.0;
        for (int i = 0; i < num_rows; i++) {
            sum += matrix[i][j];
        }
        col_avg[j] = sum / num_rows;
    }
}

void find_min_max(int matrix[][MAX_COLS], int num_rows, int num_cols, int *min_val, int *max_val) {
    *min_val = matrix[0][0];
    *max_val = matrix[0][0];
    
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (matrix[i][j] < *min_val) {
                *min_val = matrix[i][j];
            }
            if (matrix[i][j] > *max_val) {
                *max_val = matrix[i][j];
            }
        }
    }
}