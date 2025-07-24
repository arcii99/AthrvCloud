//FormAI DATASET v1.0 Category: Data mining ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A structure to represent a data point
struct Data {
    float variable1;
    float variable2;
    float variable3;
    bool isPositive;
};

// Initialize an array of data points
struct Data dataPoints[] = {
    {3.4, 5.1, 2.3, true},
    {4.5, 6.2, 1.8, true},
    {6.7, 7.3, 3.2, true},
    {5.6, 6.7, 2.5, true},
    {2.1, 4.9, 1.7, false},
    {1.9, 3.5, 0.8, false},
    {3.2, 4.7, 1.9, false},
    {1.6, 3.2, 0.5, false}
};

// Calculate the mean of a variable within a range of data points
float calcMean(struct Data data[], int start, int end, char varName) {
    float sum = 0;
    int numPts = end - start + 1;
    for (int i=start; i<=end; i++) {
        switch (varName) {
            case '1':
                sum += data[i].variable1;
                break;
            case '2':
                sum += data[i].variable2;
                break;
            case '3':
                sum += data[i].variable3;
                break;
            default:
                printf("Error: Invalid variable name\n");
                return 0;
        }
    }
    return sum / numPts;
}

// Calculate the standard deviation of a variable within a range of data points
float calcStdDev(struct Data data[], int start, int end, char varName) {
    float sumDeviationSquared = 0;
    float mean = calcMean(data, start, end, varName);
    int numPts = end - start + 1;
    for (int i=start; i<=end; i++) {
        switch (varName) {
            case '1':
                sumDeviationSquared += (data[i].variable1 - mean) * (data[i].variable1 - mean);
                break;
            case '2':
                sumDeviationSquared += (data[i].variable2 - mean) * (data[i].variable2 - mean);
                break;
            case '3':
                sumDeviationSquared += (data[i].variable3 - mean) * (data[i].variable3 - mean);
                break;
            default:
                printf("Error: Invalid variable name\n");
                return 0;
        }
    }
    return sqrt(sumDeviationSquared / numPts);
}

int main() {
    // Calculate the means of the variables for the entire dataset
    float meanVariable1 = calcMean(dataPoints, 0, 7, '1');
    float meanVariable2 = calcMean(dataPoints, 0, 7, '2');
    float meanVariable3 = calcMean(dataPoints, 0, 7, '3');
    
    // Calculate the standard deviations of the variables for the entire dataset
    float stdDevVariable1 = calcStdDev(dataPoints, 0, 7, '1');
    float stdDevVariable2 = calcStdDev(dataPoints, 0, 7, '2');
    float stdDevVariable3 = calcStdDev(dataPoints, 0, 7, '3');
    
    // Print out the results
    printf("Variable 1: Mean=%.2f, Std Dev=%.2f\n", meanVariable1, stdDevVariable1);
    printf("Variable 2: Mean=%.2f, Std Dev=%.2f\n", meanVariable2, stdDevVariable2);
    printf("Variable 3: Mean=%.2f, Std Dev=%.2f\n", meanVariable3, stdDevVariable3);
    
    return 0;
}