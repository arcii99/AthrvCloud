//FormAI DATASET v1.0 Category: Computer Biology ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate mean
double calc_mean(double *arr, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum / (double)n;
}

// Function to calculate standard deviation
double calc_stdev(double *arr, int n, double mean) {
    double sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += pow(arr[i] - mean, 2);
    return sqrt(sum / (double)n);
}

// Main function
int main() {
    int n;
    printf("Enter the number of cells in the sample: ");
    scanf("%d", &n);

    // Dynamic memory allocation for cell count array
    int *cell_count = (int*) malloc(sizeof(int) * n);

    // Input cell count for each sample
    for (int i = 0; i < n; i++) {
        printf("Enter cell count for sample %d: ", i+1);
        scanf("%d", &cell_count[i]);
    }

    // Calculate mean and standard deviation of cell count
    double mean = calc_mean(cell_count, n);
    double stdev = calc_stdev(cell_count, n, mean);

    // Print the results
    printf("Mean cell count: %f\n", mean);
    printf("Standard deviation of cell count: %f\n", stdev);

    // Free memory allocation
    free(cell_count);

    return 0;
}