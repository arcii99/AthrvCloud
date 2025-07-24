//FormAI DATASET v1.0 Category: Data mining ; Style: energetic
#include <stdio.h>

int main() {

  printf("Welcome to the Data Mining program!\n");

  // Define the data set
  int data[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};

  // Find the average value
  int sum = 0;
  int count = 0;

  for(int i = 0; i < 10; i++) {
    sum += data[i];
    count++;
  }

  float average = (float)sum / (float)count;

  printf("The average value is %.2f\n", average);

  // Find the maximum value
  int max = data[0];

  for(int i = 1; i < 10; i++) {
    if(data[i] > max) {
      max = data[i];
    }
  }

  printf("The maximum value is %d\n", max);

  // Find the minimum value
  int min = data[0];

  for(int i = 1; i < 10; i++) {
    if(data[i] < min) {
      min = data[i];
    }
  }

  printf("The minimum value is %d\n", min);

  // Calculate the variance
  float variance = 0.0;

  for(int i = 0; i < 10; i++) {
    variance += ((float)data[i] - average) * ((float)data[i] - average);
  }

  variance /= (float)count;

  printf("The variance of the data set is %.2f\n", variance);

  return 0;
}