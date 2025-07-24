//FormAI DATASET v1.0 Category: Data mining ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int n;
    float *data, avg, var, std_dev;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Allocate memory for data array
    data = (float*)malloc(n * sizeof(float));

    // Input the data points
    printf("Enter the data points:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &data[i]);
    }

    // Calculate the average
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    avg = sum / n;

    // Calculate the variance
    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow(data[i] - avg, 2);
    }
    var = sum / (n - 1);

    // Calculate the standard deviation
    std_dev = sqrt(var);

    printf("Average value: %.2f\n", avg);
    printf("Variance: %.2f\n", var);
    printf("Standard deviation: %.2f\n", std_dev);

    // Free allocated memory
    free(data);

    return 0;
}