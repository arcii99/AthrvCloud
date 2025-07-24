//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Dennis Ritchie
#include <stdio.h>

// Function to calculate the mean of an array of numbers
double calculate_mean(double arr[], int n) {
    double sum = 0;
    int i;
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
    double mean = sum / n;
    return mean;
}

// Function to calculate the standard deviation of an array of numbers
double calculate_standard_deviation(double arr[], int n, double mean) {
    double sum = 0;
    int i;
    for (i = 0; i < n; i++) {
        sum += (arr[i] - mean) * (arr[i] - mean);
    }
    double standard_deviation = sqrt(sum / n);
    return standard_deviation;
}

int main() {
    // Example data
    double data[] = {1.2, 2.3, 3.4, 4.5, 5.6};
    int n = sizeof(data) / sizeof(double);

    // Calculate the mean and standard deviation of the data
    double mean = calculate_mean(data, n);
    double standard_deviation = calculate_standard_deviation(data, n, mean);

    // Print the results
    printf("The mean of the data is: %lf\n", mean);
    printf("The standard deviation of the data is: %lf\n", standard_deviation);

    return 0;
}