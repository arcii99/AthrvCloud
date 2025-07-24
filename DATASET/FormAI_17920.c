//FormAI DATASET v1.0 Category: Data mining ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100

// Function to generate a random array of integers
void randomArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

// Function to find the sum of an array
int arraySum(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to find the mean of an array
float arrayMean(int arr[], int size) {
    float sum = (float)arraySum(arr, size);
    float mean = sum / size;
    return mean;
}

// Function to find the standard deviation of an array
float arrayStdDev(int arr[], int size) {
    float mean = arrayMean(arr, size);
    float stdDev = 0;
    for(int i = 0; i < size; i++) {
        stdDev += pow(arr[i] - mean, 2);
    }
    stdDev = sqrt(stdDev / size);
    return stdDev;
}

int main() {
    int arr[SIZE];
    randomArray(arr, SIZE);
    printf("Array: ");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int sum = arraySum(arr, SIZE);
    printf("Sum: %d\n", sum);
    float mean = arrayMean(arr, SIZE);
    printf("Mean: %f\n", mean);
    float stdDev = arrayStdDev(arr, SIZE);
    printf("Standard Deviation: %f\n", stdDev);

    return 0;
}