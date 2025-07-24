//FormAI DATASET v1.0 Category: Data mining ; Style: brave
#include <stdio.h>

int main() {
  int data[] = {3, 5, 8, 9, 1, 4, 6, 2, 7}; // Our data to be mined
  int size = sizeof(data) / sizeof(int); // Number of data points
  int min = data[0]; // Initialize the minimum value
  int max = data[0]; // Initialize the maximum value
  int sum = 0; // Initialize the sum
  float mean; // Mean variable, needs to be a float

  // Iterate through data and find the minimum, maximum, and sum
  for(int i = 1; i < size; i++) {
    if(data[i] < min) {
      min = data[i];
    }
    if(data[i] > max) {
      max = data[i];
    }
    sum += data[i];
  }

  // Calculate the mean
  mean = (float)sum / (float)size;

  // Print out the results
  printf("Data Mining Results\n");
  printf("-------------------\n");
  printf("Minimum: %d\n", min);
  printf("Maximum: %d\n", max);
  printf("Sum: %d\n", sum);
  printf("Mean: %f\n", mean);

  return 0;
}