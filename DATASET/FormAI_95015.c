//FormAI DATASET v1.0 Category: Data mining ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 1000
#define MAX_COLS 100

// Function to calculate the mean of a given array
double mean(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double) sum / n;
}

int main() {
    int data[MAX_ROWS][MAX_COLS];
    int n_rows, n_cols;

    // Generate random data
    srand(time(NULL));
    n_rows = rand() % MAX_ROWS + 1;
    n_cols = rand() % MAX_COLS + 1;
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            data[i][j] = rand() % 100;
        }
    }

    // Calculate the means of each column
    double means[n_cols];
    for (int i = 0; i < n_cols; i++) {
        int col_data[n_rows];
        for (int j = 0; j < n_rows; j++) {
            col_data[j] = data[j][i];
        }
        means[i] = mean(col_data, n_rows);
    }

    // Print the means
    printf("Means:\n");
    for (int i = 0; i < n_cols; i++) {
        printf("%f ", means[i]);
    }

    return 0;
}