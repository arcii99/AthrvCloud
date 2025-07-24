//FormAI DATASET v1.0 Category: Data mining ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_DATA_POINTS 100
#define MAX_RANDOM_VALUE 100

int main() {

    // Generating random data points
    int data_points[NUM_OF_DATA_POINTS];
    srand(time(NULL));
    for (int i=0; i<NUM_OF_DATA_POINTS; i++) {
        data_points[i] = rand() % MAX_RANDOM_VALUE;
    }

    // Finding mean of the data points
    float sum = 0;
    for (int i=0; i<NUM_OF_DATA_POINTS; i++) {
        sum += data_points[i];
    }
    float mean = sum / NUM_OF_DATA_POINTS;
    printf("Mean of the data points: %.2f\n", mean);

    // Finding standard deviation of the data points
    float deviation_sum = 0;
    for (int i=0; i<NUM_OF_DATA_POINTS; i++) {
        deviation_sum += (data_points[i]-mean)*(data_points[i]-mean);
    }
    float standard_deviation = sqrt(deviation_sum/NUM_OF_DATA_POINTS);
    printf("Standard deviation of the data points: %.2f\n", standard_deviation);

    return 0;
}