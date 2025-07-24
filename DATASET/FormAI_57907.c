//FormAI DATASET v1.0 Category: Audio processing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_SIZE 128

/* Function to calculate the mean of an array */
float calculate_mean(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return ((float) sum / (float) n);
}

/* Function to calculate the variance of an array */
float calculate_variance(int arr[], int n) {
    float mean = calculate_mean(arr, n);
    float variance = 0;
    
    for (int i = 0; i < n; i++) {
        variance += pow(arr[i] - mean, 2);
    }
    
    return (variance / n);
}

/* Main function */
int main() {
    int buffer[BUFFER_SIZE];
    int n;
    
    printf("Enter size of the buffer: ");
    scanf("%d", &n);
    
    printf("Enter audio data:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &buffer[i]);
    }
    
    float mean = calculate_mean(buffer, n);
    float variance = calculate_variance(buffer, n);
    
    printf("Mean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);
    
    return 0;
}