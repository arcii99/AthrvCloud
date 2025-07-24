//FormAI DATASET v1.0 Category: Data mining ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 100	// Maximum size of the data set
#define MIN 0	// Minimum size of the data set
#define RANGE MAX-MIN	// Range of the data set

int main() {
    // Data set generation and initialization
    int dataSet[MAX];
    int i;
    srand((unsigned)time(NULL));
    for(i=0; i<MAX; i++) {
        dataSet[i] = rand() % RANGE + MIN;
    }

    // Printing the generated data set
    printf("Generated Data Set:\n");
    for(i=0; i<MAX; i++) {
        printf("%d ", dataSet[i]);
    }
    printf("\n\n");

    // Mean Calculation
    float sum = 0.0;
    float mean = 0.0;
    for(i=0; i<MAX; i++) {
        sum += dataSet[i];
    }
    mean = sum/MAX;
    printf("Mean = %.2f\n", mean);

    // Variance Calculation
    float variance = 0.0;
    for(i=0; i<MAX; i++) {
        variance += pow((dataSet[i]-mean), 2);
    }
    variance = variance/MAX;
    printf("Variance = %.2f\n", variance);

    // Standard Deviation Calculation
    float stdDeviation = sqrt(variance);
    printf("Standard Deviation = %.2f\n", stdDeviation);

    return 0;
}