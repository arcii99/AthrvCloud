//FormAI DATASET v1.0 Category: Data mining ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create an array of numbers
    int numbers[10] = {1, 3, 2, 5, 4, 8, 9, 7, 6, 10};
    
    // Find the maximum and minimum numbers in the array
    int max = numbers[0];
    int min = numbers[0];
    for (int i = 1; i < 10; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    
    // Find the mean and standard deviation of the array
    float sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += numbers[i];
    }
    float mean = sum / 10;
    float variance = 0;
    for (int i = 0; i < 10; i++) {
        variance += (numbers[i] - mean) * (numbers[i] - mean);
    }
    float std_dev = sqrt(variance / 10);
    
    // Print the results
    printf("The maximum number is: %d\n", max);
    printf("The minimum number is: %d\n", min);
    printf("The mean of the numbers is: %f\n", mean);
    printf("The standard deviation of the numbers is: %f\n", std_dev);
    
    return 0;
}