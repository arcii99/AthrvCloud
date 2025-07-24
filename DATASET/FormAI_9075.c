//FormAI DATASET v1.0 Category: Data mining ; Style: funny
// Welcome to the world of data mining with a twist of comedy!
#include <stdio.h>

int main() {
  int data[10] = {23, 34, 12, 67, 89, 43, 12, 10, 56, 78};
  
  // First, let's find the maximum data value
  int max = data[0];
  for (int i = 1; i < 10; i++) {
    if (data[i] > max) {
      max = data[i];
    }
  }
  printf("The maximum data value is %d\n", max);
  
  // Now, let's find the minimum data value
  int min = data[0];
  for (int i = 1; i < 10; i++) {
    if (data[i] < min) {
      min = data[i];
    }
  }
  printf("The minimum data value is %d\n", min);
  
  // Next, let's calculate the range
  int range = max - min;
  printf("The range is %d\n", range);
  
  // Moving on to the mean
  int sum = 0;
  float mean;
  for (int i = 0; i < 10; i++) {
    sum += data[i];
  }
  mean = sum / 10.0;
  printf("The mean is %.2f\n", mean);
  
  // Time to calculate the variance
  float temp = 0;
  float variance;
  for (int i = 0; i < 10; i++) {
    temp += (data[i] - mean) * (data[i] - mean);
  }
  variance = temp / 10.0;
  printf("The variance is %.2f\n", variance);
  
  // Finally, let's find the standard deviation
  float stdev;
  stdev = sqrt(variance);
  printf("The standard deviation is %.2f\n", stdev);
  
  // That's it folks, we've successfully mined some data with some laughs along the way
  return 0;
}