//FormAI DATASET v1.0 Category: Data mining ; Style: minimalist
#include <stdio.h>

int main() {
    int data[] = {3, 7, 2, 8, 4, 5, 6, 1, 9, 10}; // Sample data
    int data_length = sizeof(data) / sizeof(int); // Length of data array
    
    int min = data[0]; // Initialize minimum value to first element in data
    int max = data[0]; // Initialize maximum value to first element in data
    double avg = 0; // Initialize average value to 0
    
    // Loop through data to calculate min, max, and average values
    for (int i = 0; i < data_length; i++) {
        if (data[i] < min) {
            min = data[i]; // Update minimum value
        }
        
        if (data[i] > max) {
            max = data[i]; // Update maximum value
        }
        
        avg += (double)data[i] / data_length; // Update average value
    }
    
    // Print results
    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);
    printf("Average value: %f\n", avg);
    
    return 0;
}