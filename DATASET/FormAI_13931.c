//FormAI DATASET v1.0 Category: Data mining ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate mean
float calculateMean(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return (float) sum/n;
}

// Function to calculate standard deviation
float calculateSD(int arr[], int n, float mean){
    float sum = 0;
    for(int i = 0; i < n; i++){
        sum += pow(arr[i] - mean, 2);
    }
    return sqrt(sum/n);
}

int main(){
    int arr[10] = {12, 23, 34, 45, 56, 67, 78, 89, 90, 100};
    int n = sizeof(arr)/sizeof(arr[0]);

    float mean = calculateMean(arr, n);
    float sd = calculateSD(arr, n, mean);

    printf("Data Mining Example Program\n");
    printf("----------------------------\n");
    printf("Data Set: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Mean: %.2f\n", mean);
    printf("Standard Deviation: %.2f\n", sd);

    printf("\n");
    printf("Data Points Beyond Two Standard Deviations\n");
    printf("-------------------------------------------\n");

    // Find the data points beyond two standard deviations
    int count = 0;
    for(int i = 0; i < n; i++){
        if(abs(arr[i] - mean) > 2*sd){
            printf("Data point at index %d: %d\n", i, arr[i]);
            count++;
        }
    }

    if(count == 0){
        printf("No data points beyond two standard deviations\n");
    }

    return 0;
}