//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//function to calculate mean
double calculate_mean(int* data, int size) {
    double sum = 0.0;
    for(int i=0; i<size; i++) {
        sum += data[i];
    }
    double mean = sum/size;
    return mean;
}

//function to calculate standard deviation
double calculate_standard_deviation(int* data, int size, double mean) {
    double variance = 0.0;
    for(int i=0; i<size; i++) {
        variance += pow(data[i] - mean, 2);
    }
    variance = variance/size;
    double standard_deviation = sqrt(variance);
    return standard_deviation;
}

int main() {
    int num_samples;
    printf("Enter the number of samples: ");
    scanf("%d", &num_samples);
    int* signal_strengths = malloc(num_samples * sizeof(int));
    if(signal_strengths == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    printf("Enter the signal strengths in dBm:\n");
    for(int i=0; i<num_samples; i++) {
        scanf("%d", &signal_strengths[i]);
    }
    double mean = calculate_mean(signal_strengths, num_samples);
    double standard_deviation = calculate_standard_deviation(signal_strengths, num_samples, mean);
    printf("Mean signal strength: %f dBm\n", mean);
    printf("Standard deviation: %f dBm\n", standard_deviation);
    free(signal_strengths);
    return 0;
}