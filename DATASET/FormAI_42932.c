//FormAI DATASET v1.0 Category: Data mining ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 5

// Function to compute the mean of a data set
double compute_mean(double data[], int len) {
    double sum = 0;
    for (int i = 0; i < len; i++) {
        sum += data[i];
    }
    return sum / len;
}

// Function to compute the standard deviation of a data set
double compute_std_dev(double data[], int len) {
    double mean = compute_mean(data, len);
    double sum_sq_diff = 0;
    for (int i = 0; i < len; i++) {
        sum_sq_diff += (data[i] - mean) * (data[i] - mean);
    }
    return sqrt(sum_sq_diff / len);
}

int main() {
    // Generate some sample data
    double data[MAX_ROWS][MAX_COLS] = {
        {1.2, 2.3, 0.8, 0.5, 4.3},
        {3.1, 4.4, 2.3, 1.2, 5.8},
        {0.5, 1.1, 2.9, 1.5, 6.2},
        {2.3, 3.5, 4.7, 3.1, 2.2},
        {0.8, 1.6, 3.4, 2.2, 4.1},
        {3.4, 2.1, 1.2, 0.6, 5.9},
        {1.1, 2.8, 4.4, 3.2, 0.7},
        {2.2, 3.9, 1.9, 0.9, 4.4},
        {4.1, 3.3, 2.5, 1.7, 6.6},
        {0.9, 1.8, 2.7, 3.6, 5.3},
    };

    // Compute the mean and standard deviation of each column
    double means[MAX_COLS] = {0};
    double std_devs[MAX_COLS] = {0};
    for (int i = 0; i < MAX_COLS; i++) {
        double col_data[MAX_ROWS];
        for (int j = 0; j < MAX_ROWS; j++) {
            col_data[j] = data[j][i];
        }
        means[i] = compute_mean(col_data, MAX_ROWS);
        std_devs[i] = compute_std_dev(col_data, MAX_ROWS);
    }

    // Print the results
    printf("Means:\n");
    for (int i = 0; i < MAX_COLS; i++) {
        printf("%.2f ", means[i]);
    }
    printf("\n");
    printf("Standard Deviations:\n");
    for (int i = 0; i < MAX_COLS; i++) {
        printf("%.2f ", std_devs[i]);
    }
    printf("\n");

    return 0;
}