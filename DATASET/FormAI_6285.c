//FormAI DATASET v1.0 Category: Browser Plugin ; Style: statistical
/** 
 * Program: Unique C Browser Plugin
 * Description: This plugin is designed to streamline data analysis for statistical projects
 * Version: 1.0
 * Author: John Doe
 * Date: 10/10/2021
**/

// Importing necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Defining necessary constants
#define PI 3.14159

// Function to calculate variance in a data set
double calculate_variance(double data[], int n) {
    // Variables for sum and mean calculation
    double sum = 0, mean = 0;
    // Calculating mean
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    mean = sum / n;
    // Calculating variance
    double variance = 0;
    for (int i = 0; i < n; i++) {
        variance += pow((data[i] - mean), 2);
    }
    variance /= n;
    return variance;
}

// Function to calculate standard deviation in a data set
double calculate_standard_deviation(double data[], int n) {
    // Calling calculate_variance function to get variance of data set
    double variance = calculate_variance(data, n);
    // Calculating standard deviation
    double standard_deviation = sqrt(variance);
    return standard_deviation;
}

// Function to calculate correlation coefficient for two data sets
double calculate_correlation_coefficient(double data1[], double data2[], int n) {
    // Variables for sum and mean calculation for both data sets
    double sum1 = 0, mean1 = 0, sum2 = 0, mean2 = 0;
    // Calculating mean
    for (int i = 0; i < n; i++) {
        sum1 += data1[i];
        sum2 += data2[i];
    }
    mean1 = sum1 / n;
    mean2 = sum2 / n;
    // Calculating correlation coefficient
    double numerator = 0, denominator1 = 0, denominator2 = 0;
    for (int i = 0; i < n; i++) {
        numerator += (data1[i] - mean1) * (data2[i] - mean2);
        denominator1 += pow((data1[i] - mean1), 2);
        denominator2 += pow((data2[i] - mean2), 2);
    }
    double denominator = sqrt(denominator1) * sqrt(denominator2);
    double correlation_coefficient = numerator / denominator;
    return correlation_coefficient;
}

// Main function to be called by the browser plugin
int main(int argc, char *argv[]) {
    // Checking for correct number of arguments
    if (argc < 3) {
        printf("Usage: StatisticalPlugin <command> <data_set>\n");
        return 1;
    }
    // Creating array to store data set
    double data[argc - 2];
    // Filling array with data set from command line
    for (int i = 2; i < argc; i++) {
        data[i-2] = atof(argv[i]);
    }
    // Calling appropriate function based on command
    if (strcmp(argv[1], "variance") == 0) {
        double variance = calculate_variance(data, argc - 2);
        printf("Variance: %.2f\n", variance);
    } else if (strcmp(argv[1], "standard_deviation") == 0) {
        double standard_deviation = calculate_standard_deviation(data, argc - 2);
        printf("Standard Deviation: %.2f\n", standard_deviation);
    } else if (strcmp(argv[1], "correlation_coefficient") == 0) {
        // Checking for correct number of arguments with second data set
        if (argc < 4) {
            printf("Usage: StatisticalPlugin correlation_coefficient <data_set1> <data_set2>\n");
            return 1;
        }
        // Creating array to store second data set
        double data2[argc - 3];
        // Filling array with second data set from command line
        for (int i = 3; i < argc; i++) {
            data2[i-3] = atof(argv[i]);
        }
        double correlation_coefficient = calculate_correlation_coefficient(data, data2, argc - 3);
        printf("Correlation Coefficient: %.2f\n", correlation_coefficient);
    } else {
        printf("Command not recognized. Please use one of the following:\n");
        printf("variance, standard_deviation, correlation_coefficient\n");
        return 1;
    }
    return 0;
}