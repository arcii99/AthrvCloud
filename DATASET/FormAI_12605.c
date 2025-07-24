//FormAI DATASET v1.0 Category: Data mining ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double mean(int *arr, int size) {
    double sum = 0.0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum/size;
}

double variance(int *arr, int size) {
    double avg = mean(arr, size);
    double sum = 0.0;
    for(int i = 0; i < size; i++) {
        sum += ((arr[i] - avg)*(arr[i] - avg));
    }
    return sum/size;
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(int);
    double meanval = mean(arr, size);
    double var = variance(arr, size);
    double stddev = sqrt(var);

    printf("The mean value of the array is: %lf\n", meanval);
    printf("The variance of the array is: %lf\n", var);
    printf("The standard deviation of the array is: %lf\n", stddev);

    return 0;
}