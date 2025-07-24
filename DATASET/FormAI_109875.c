//FormAI DATASET v1.0 Category: Data mining ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// A function to calculate the mean of an array
float mean(int *array, int size) {
    float sum = 0.0;
    for(int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

// A function to calculate the standard deviation of an array
float standard_deviation(int *array, int size) {
    float mean_value = mean(array, size);
    float sum = 0.0;
    for(int i = 0; i < size; i++) {
        sum += (array[i] - mean_value) * (array[i] - mean_value);
    }
    float variance = sum / size;
    return sqrt(variance);
}

int main() {
    int size = 10;
    int array[size];

    // Generate random numbers for the array
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }

    // Display the generated array
    printf("Generated array:\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");

    // Calculate the mean and standard deviation of the array
    float mean_value = mean(array, size);
    float standard_deviation_value = standard_deviation(array, size);
    printf("Mean: %f\n", mean_value);
    printf("Standard deviation: %f\n", standard_deviation_value);

    return 0;
}