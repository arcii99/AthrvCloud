//FormAI DATASET v1.0 Category: Data mining ; Style: beginner-friendly
#include <stdio.h>

// Function to calculate the average using an array
float calculateAverage(int data[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return (float)sum / size;
}

int main() {
    // Sample dataset
    int data[] = {6, 7, 8, 9, 10, 12, 15, 20, 25, 30};
    int size = sizeof(data) / sizeof(data[0]);
    
    // Calculate the average of the dataset
    float average = calculateAverage(data, size);
    
    // Calculate the standard deviation of the dataset
    float deviation = 0;
    for (int i = 0; i < size; i++) {
        deviation += (data[i] - average) * (data[i] - average);
    }
    deviation /= size;
    deviation = sqrt(deviation);
    
    // Print the results
    printf("Dataset:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n\nAverage = %f\n", average);
    printf("Standard Deviation = %f\n", deviation);
    
    return 0;
}