//FormAI DATASET v1.0 Category: Data mining ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numData; // Number of data
    float* data; // Dynamic array to store data
    float mean = 0, variance = 0, deviation; // Variables to hold mean, variance and deviation values
    printf("Enter the number of data: ");
    scanf("%d", &numData);
    data = (float*)calloc(numData, sizeof(float)); // Allocate memory for the dynamic array

    if (data == NULL) { // Check if memory allocation was successful
        printf("Memory allocation error!");
        exit(1);
    }

    for (int i = 0; i < numData; i++) {
        printf("Enter data %d: ", i+1);
        scanf("%f", &data[i]); // Store input into dynamic array
        mean += data[i]; // Calculate mean
    }

    mean = mean / numData; // Calculate mean

    for (int i = 0; i < numData; i++) {
        variance += ((data[i] - mean) * (data[i] - mean)); // Calculate variance
    }

    variance = variance / numData; // Calculate variance

    deviation = sqrt(variance); // Calculate standard deviation

    printf("Mean: %.2f\nVariance: %.2f\nStandard deviation: %.2f\n", mean, variance, deviation); // Print results

    free(data); // Free dynamically allocated memory

    return 0;
}