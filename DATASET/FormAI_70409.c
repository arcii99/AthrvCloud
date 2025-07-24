//FormAI DATASET v1.0 Category: Scientific ; Style: introspective
#include <stdio.h>

int main() {
    // Introduction
    printf("Hi there, I am a C program.\n");
    printf("Today we are going to calculate some statistics!\n");

    // Variable declaration
    int n;
    float sum = 0.0, mean, variance = 0.0;

    // User input
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float data[n];

    // Loop for data input and sum calculation
    for (int i = 0; i < n; i++) {
        printf("Enter data point %d: ", i + 1);
        scanf("%f", &data[i]);
        sum += data[i];
    }

    // Mean calculation
    mean = sum / n;

    // Loop for variance calculation
    for (int i = 0; i < n; i++) {
        variance += (data[i] - mean) * (data[i] - mean);
    }

    variance /= n;

    // Standard deviation calculation
    float std_deviation = sqrt(variance);

    // Output results
    printf("The sum of the data points is: %.2f\n", sum);
    printf("The mean of the data points is: %.2f\n", mean);
    printf("The variance of the data points is: %.2f\n", variance);
    printf("The standard deviation of the data points is: %.2f\n", std_deviation);

    // End of program
    printf("Thank you for using me today!\n");

    return 0;
}