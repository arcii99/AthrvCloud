//FormAI DATASET v1.0 Category: Arithmetic ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
int randomInt(int min, int max);
float calculateMean(int *data, int numElements);
float calculateStdDev(int *data, int numElements, float mean);

int main() {
  // seed the random number generator
  srand((unsigned) time(NULL));

  // generate some random integers
  int nums[100];
  for (int i = 0; i < 100; i++) {
    nums[i] = randomInt(0, 100);
  }

  // calculate the mean and standard deviation
  float mean = calculateMean(nums, 100);
  float stdDev = calculateStdDev(nums, 100, mean);

  // print out the results
  printf("The mean of the data set is %.2f\n", mean);
  printf("The standard deviation of the data set is %.2f\n", stdDev);

  return 0;
}

// function to generate a random integer between min and max (inclusive)
int randomInt(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

// function to calculate the mean of an array of integers
float calculateMean(int *data, int numElements) {
  int sum = 0;
  for (int i = 0; i < numElements; i++) {
    sum += data[i];
  }
  return (float) sum / numElements;
}

// function to calculate the standard deviation of an array of integers
float calculateStdDev(int *data, int numElements, float mean) {
  float sum = 0;
  for (int i = 0; i < numElements; i++) {
    sum += (data[i] - mean) * (data[i] - mean);
  }
  return sqrt(sum / numElements);
}