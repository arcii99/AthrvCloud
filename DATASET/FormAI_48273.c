//FormAI DATASET v1.0 Category: Math exercise ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Function to generate a random array of integers */
void generateRandomArray(int *arr, int size, int max_val) {
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % max_val;
    }
}

/* Function to print the contents of an array */
void printArray(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Function to calculate the mean of an array */
float findMean(int *arr, int size) {
    float sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

/* Function to calculate the standard deviation of an array */
float findStdDev(int *arr, int size) {
    float mean = findMean(arr, size);
    float sum = 0;
    for(int i = 0; i < size; i++) {
        sum += pow((arr[i] - mean), 2);
    }
    return sqrt(sum / size);
}

/* Main function */
int main() {
    int size = 10;
    int max_val = 100;
    int arr[size];
    generateRandomArray(arr, size, max_val);
    printf("Random Array:\n");
    printArray(arr, size);
    printf("Mean = %.2f\n", findMean(arr, size));
    printf("Standard Deviation = %.2f\n", findStdDev(arr, size));
    return 0;
}