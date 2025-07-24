//FormAI DATASET v1.0 Category: Data mining ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function to calculate mean of an array of numbers
double mean(double arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i]; 
    }
    double mean = sum/n;
    return mean;
}

// function to calculate standard deviation of an array of numbers
double stddev(double arr[], int n, double mean) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow(arr[i] - mean, 2);
    }
    double stddev = sqrt(sum/n);
    return stddev;
}

int main() {
    // input data arrays
    double age[10] = {23, 32, 45, 19, 27, 55, 31, 40, 26, 29};
    double income[10] = {25000, 54000, 67000, 32000, 44000, 78000, 52000, 61000, 36000, 48000};
    double credit[10] = {500, 750, 600, 550, 800, 710, 550, 600, 450, 670};

    // calculate mean and standard deviation for each data array
    double age_mean = mean(age, 10);
    double age_stddev = stddev(age, 10, age_mean);

    double income_mean = mean(income, 10);
    double income_stddev = stddev(income, 10, income_mean);

    double credit_mean = mean(credit, 10);
    double credit_stddev = stddev(credit, 10, credit_mean);

    // print results
    printf("Age mean and standard deviation: %.2f, %.2f\n", age_mean, age_stddev);
    printf("Income mean and standard deviation: %.2f, %.2f\n", income_mean, income_stddev);
    printf("Credit score mean and standard deviation: %.2f, %.2f\n", credit_mean, credit_stddev);

    return 0;
}