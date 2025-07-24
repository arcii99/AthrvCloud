//FormAI DATASET v1.0 Category: Data mining ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {
  int data[] = {4, 2, 6, 1, 9, 3, 5, 8, 7}; // sample dataset
  int sum = 0; // variable to store the sum of all numbers

  // loop through each number in the dataset and add it to the sum
  for (int i=0; i<sizeof(data)/sizeof(int); i++) {
    sum += data[i];
  }

  float mean = (float)sum / (sizeof(data)/sizeof(int)); // calculate the mean

  printf("Dataset: ");
  for (int i=0; i<sizeof(data)/sizeof(int); i++) {
    printf("%d ", data[i]);
  }

  printf("\n\nMean: %0.2f\n", mean); // print the mean with 2 decimal places

  // loop through each number and calculate its deviation from the mean
  for (int i=0; i<sizeof(data)/sizeof(int); i++) {
    float deviation = data[i] - mean;
    printf("Deviation from mean of %d: %0.2f\n", data[i], deviation);
  }

  printf("\n"); // add some spacing

  float sum_squared_deviation = 0; // variable to store the sum of squared deviations

  // loop through each number and calculate its squared deviation from the mean
  for (int i=0; i<sizeof(data)/sizeof(int); i++) {
    float deviation = data[i] - mean;
    float squared_deviation = deviation * deviation;
    sum_squared_deviation += squared_deviation;
    printf("Squared deviation from mean of %d: %0.2f\n", data[i], squared_deviation);
  }

  float variance = sum_squared_deviation / (sizeof(data)/sizeof(int)); // calculate the variance

  printf("\nVariance: %0.2f\n", variance); // print the variance with 2 decimal places

  float standard_deviation = sqrt(variance); // calculate the standard deviation

  printf("Standard deviation: %0.2f\n", standard_deviation); // print the standard deviation with 2 decimal places

  return 0; // end of program
}