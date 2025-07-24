//FormAI DATASET v1.0 Category: Data mining ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Function to calculate mean of an array
float mean(int data[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum/n;
}

// Function to calculate standard deviation of an array
float standard_deviation(int data[], int n) {
    float sum = 0;
    float x_bar = mean(data, n);
    for (int i = 0; i < n; i++) {
        sum += (data[i] - x_bar) * (data[i] - x_bar);
    }
    return sqrt(sum / (n-1));
}

int main() {
    // Generate random data for testing
    int n = 100;
    int data[n];
    for (int i = 0; i < n; i++) {
        data[i] = rand() % 100 + 1;
    }

    // Calculate mean and standard deviation of the data
    float x_bar = mean(data, n);
    float s = standard_deviation(data, n);

    // Print the results
    printf("Data: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\nMean: %f\n", x_bar);
    printf("Standard Deviation: %f\n", s);

    return 0;
}