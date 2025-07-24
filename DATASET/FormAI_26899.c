//FormAI DATASET v1.0 Category: Random ; Style: statistical
// This program generates a random series of numbers using the time function as seed 
// and calculates various statistical measures to analyze the distribution of values.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_NUM 1000000

int main()
{
    int count = 0;
    float sum = 0, mean, variance = 0, stdev, skewness = 0, kurtosis = 0;
    int freq_count[MAX_NUM] = {0};
    float freq_dist[MAX_NUM] = {0};
    
    // Seed rand with the current time
    srand(time(NULL));
    
    // Generate random numbers between 1 and 1000 and store the frequency distribution
    for (int i = 0; i < MAX_NUM; i++) {
        int num = rand() % 1000 + 1;
        freq_count[num]++;
    }
    
    // Calculate the frequency distribution and the mean
    for (int i = 1; i <= 1000; i++) {
        freq_dist[i] = (float)freq_count[i] / MAX_NUM;
        sum += i * freq_dist[i];
        count += freq_count[i];
    }
    
    mean = sum / count;
    
    // Calculate the variance
    for (int i = 1; i <= 1000; i++) {
        variance += pow(i - mean, 2) * freq_dist[i];
    }
    
    // Calculate the standard deviation
    stdev = sqrt(variance);
    
    // Calculate the skewness
    for (int i = 1; i <= 1000; i++) {
        skewness += pow(i - mean, 3) * freq_dist[i] / pow(stdev, 3);
    }
    
    // Calculate the kurtosis
    for (int i = 1; i <= 1000; i++) {
        kurtosis += pow(i - mean, 4) * freq_dist[i] / pow(stdev, 4) - 3;
    }
    
    printf("Mean: %f\n", mean);
    printf("Variance: %f\n", variance);
    printf("Standard Deviation: %f\n", stdev);
    printf("Skewness: %f\n", skewness);
    printf("Kurtosis: %f\n", kurtosis);
    
    return 0;
}