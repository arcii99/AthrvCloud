//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

// Define struct to hold information for each data point
typedef struct {
    int id;
    float value1;
    float value2;
} DataPoint;

// Function to generate random data points
void generateData(DataPoint *data) {
    int i;
    for (i = 0; i < SIZE; i++) {
        data[i].id = i;
        data[i].value1 = (float) rand() / RAND_MAX;
        data[i].value2 = (float) rand() / RAND_MAX;
    }
}

// Function to calculate the average of value1 for a subset of data points
float computeSubsetAverage(DataPoint *data, int start, int end) {
    int i;
    float sum = 0;
    for (i = start; i < end; i++) {
        sum += data[i].value1;
    }
    return sum / (end - start);
}

// Main function
int main() {
    // Seed random number generator
    srand(time(NULL));

    // Allocate memory for data points
    DataPoint *data = (DataPoint*) malloc(SIZE * sizeof(DataPoint));
    if (!data) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Generate random data points
    generateData(data);

    // Calculate average of value1 for all data points
    float average = computeSubsetAverage(data, 0, SIZE);

    // Print result
    printf("Average of value1 for all data points: %.6f\n", average);

    // Free memory
    free(data);

    return 0;
}