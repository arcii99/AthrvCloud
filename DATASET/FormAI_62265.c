//FormAI DATASET v1.0 Category: Data mining ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define DATA_SIZE 1000

// Generate random data between -10 and 10
void generateData(int* data, int size) {
    for (int i = 0; i < size; i++) {
        data[i] = rand() % 21 - 10;
    }
}

// Display data
void displayData(int* data, int size) {
    printf("[");
    for (int i = 0; i < size-1; i++) {
        printf("%d, ", data[i]);
    }
    printf("%d]\n", data[size-1]);
}

// Find the maximum value in the data
int findMax(int* data, int size) {
    int max = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}

// Find the minimum value in the data
int findMin(int* data, int size) {
    int min = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    return min;
}

// Find the average of the data
double findAverage(int* data, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}

int main() {
    // Generate random data
    int data[DATA_SIZE];
    generateData(data, DATA_SIZE);

    // Display data
    printf("Data:\n");
    displayData(data, DATA_SIZE);

    // Find maximum, minimum, and average
    int max = findMax(data, DATA_SIZE);
    int min = findMin(data, DATA_SIZE);
    double average = findAverage(data, DATA_SIZE);

    // Display results
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    printf("Average: %f\n", average);

    return 0;
}