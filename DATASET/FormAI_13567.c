//FormAI DATASET v1.0 Category: Data mining ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  // Define an array of integers for data mining
  int data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

  // Define the length of the array
  int length = sizeof(data)/sizeof(int);

  // Define and calculate the average of the data
  float avg = 0;
  for(int i=0; i<length; i++) {
    avg += data[i];
  }
  avg = avg/length;

  // Define and calculate the standard deviation of the data
  float sd = 0;
  for(int i=0; i<length; i++) {
    sd += (data[i] - avg)*(data[i] - avg);
  }
  sd = sqrt(sd/length);

  // Print the original data, average, and standard deviation
  printf("Original data: ");
  for(int i=0; i<length; i++) {
    printf("%d ", data[i]);
  }
  printf("\nAverage: %.2f\nStandard deviation: %.2f\n\n", avg, sd);

  // Define a threshold for detecting outliers
  float threshold = avg + 2*sd;

  // Detect and print outliers
  printf("Outliers: ");
  for(int i=0; i<length; i++) {
    if(data[i] > threshold) {
      printf("%d ", data[i]);
    }
  }
  printf("\n");

  return 0;
}