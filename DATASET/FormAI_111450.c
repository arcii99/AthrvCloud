//FormAI DATASET v1.0 Category: Scientific ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100
#define MEAN_ERROR 0.01
#define VAR_ERROR 0.001
#define MAX_ITERATIONS 100

// Function prototypes
double calculate_mean(double array[], int n);
double calculate_variance(double array[], int n, double mean);
double calculate_standard_deviation(double variance);
double calculate_pdf(double x, double mean, double sd);

int main() {
    double data[MAX];
    int n;
    
    printf("Enter number of data points (maximum %d): ", MAX);
    scanf("%d", &n);
    
    // Get data from user
    for (int i=0; i<n; i++) {
        printf("Enter data point %d: ", i+1);
        scanf("%lf", &data[i]);
    }
    
    // Calculate mean and variance
    double mean = calculate_mean(data, n);
    double variance = calculate_variance(data, n, mean);
    double standard_deviation = calculate_standard_deviation(variance);
    
    // Print statistics
    printf("\nStatistics:\n");
    printf("Mean: %.3lf\n", mean);
    printf("Variance: %.3lf\n", variance);
    printf("Standard Deviation: %.3lf\n\n", standard_deviation);
    
    // Calculate and print probability density function for x=mean+sd
    double x = mean + standard_deviation;
    double pdf = calculate_pdf(x, mean, standard_deviation);
    printf("PDF for x=%.3lf: %.6lf\n", x, pdf);
    
    return 0;
}

// Calculate mean of array
double calculate_mean(double array[], int n) {
    double sum = 0;
    for (int i=0; i<n; i++) {
        sum += array[i];
    }
    return sum/n;
}

// Calculate variance of array
double calculate_variance(double array[], int n, double mean) {
    double sum_squared_diff = 0;
    for (int i=0; i<n; i++) {
        sum_squared_diff += pow(array[i]-mean, 2);
    }
    return sum_squared_diff/n;
}

// Calculate standard deviation using variance
double calculate_standard_deviation(double variance) {
    return sqrt(variance);
}

// Calculate probability density function for x given mean and standard deviation
double calculate_pdf(double x, double mean, double sd) {
    double exponent = -1 * pow(x-mean, 2) / (2*pow(sd, 2));
    double denominator = sd * sqrt(2*M_PI);
    return exp(exponent) / denominator;
}