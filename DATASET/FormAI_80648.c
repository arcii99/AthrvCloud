//FormAI DATASET v1.0 Category: Data mining ; Style: shocked
#include <stdio.h>
#include <math.h>

int main() {
  int data_set[10] = {25, 30, 35, 40, 45, 50, 55, 60, 65, 70}; // data set with 10 values
  double average = 0, variance = 0, std_deviation = 0; // declare variables for calculations
  
  // calculate the average of the data set
  for(int i = 0; i < 10; i++) {
    average += data_set[i];
  }
  average = average / 10;
  
  // calculate the variance of the data set
  for(int i = 0; i < 10; i++) {
    variance += pow((data_set[i] - average), 2);
  }
  variance = variance / 10;
  
  // calculate the standard deviation of the data set
  std_deviation = sqrt(variance);
  
  // print out the results
  printf("Data set: ");
  for(int i = 0; i < 10; i++) {
    printf("%d ", data_set[i]);
  }
  printf("\nAverage: %lf\nVariance: %lf\nStandard Deviation: %lf\n", average, variance, std_deviation);
  
  return 0;
}