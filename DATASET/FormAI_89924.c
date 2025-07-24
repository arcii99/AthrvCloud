//FormAI DATASET v1.0 Category: Data mining ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Function to calculate mean of an array
float mean(float arr[], int n) {
    float sum = 0.0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

//Function to calculate standard deviation of an array
float standard_deviation(float arr[], int n) {
    float avg = mean(arr, n);
    float sum = 0.0;
    for(int i = 0; i < n; i++) {
        sum += pow(arr[i] - avg, 2);
    }
    return sqrt(sum / n);
}

int main() {
    //Example dataset
    float dataset[] = {10.2, 15.4, 12.5, 7.8, 9.3, 6.7, 8.9, 11.1, 17.8, 20.0};
    int n = sizeof(dataset) / sizeof(float);

    //Calculate mean and standard deviation of the dataset
    float avg = mean(dataset, n);
    float sd = standard_deviation(dataset, n);

    //Print the results
    printf("Mean: %.2f\nStandard deviation: %.2f\n", avg, sd);

    return 0;
}