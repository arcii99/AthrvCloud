//FormAI DATASET v1.0 Category: Data mining ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 5
#define COLS 4

float data[ROWS][COLS] = {
    {2.5, 3.6, 4.8, 2.2},
    {3.0, 3.7, 4.5, 2.5},
    {2.8, 3.2, 4.2, 2.0},
    {3.5, 3.9, 4.9, 2.7},
    {2.9, 3.4, 4.0, 2.1}
};

int main() {
    // Calculate mean of each column
    float mean[COLS];
    for (int j=0; j<COLS; j++) {
        float sum = 0;
        for (int i=0; i<ROWS; i++) {
            sum += data[i][j];
        }
        mean[j] = sum / ROWS;
    }
    
    // Print mean of each column
    printf("Mean of each column:\n");
    for (int j=0; j<COLS; j++) {
        printf("%f ", mean[j]);
    }
    printf("\n\n");
    
    // Calculate standard deviation of each column
    float standardDeviation[COLS];
    for (int j=0; j<COLS; j++) {
        float sum = 0;
        for (int i=0; i<ROWS; i++) {
            sum += pow(data[i][j] - mean[j], 2);
        }
        standardDeviation[j] = sqrt(sum / ROWS);
    }
    
    // Print standard deviation of each column
    printf("Standard deviation of each column:\n");
    for (int j=0; j<COLS; j++) {
        printf("%f ", standardDeviation[j]);
    }
    printf("\n\n");
    
    // Normalize data
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            data[i][j] = (data[i][j] - mean[j]) / standardDeviation[j];
        }
    }
    
    // Print normalized data
    printf("Normalized data:\n");
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            printf("%f ", data[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}