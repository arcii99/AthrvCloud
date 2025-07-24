//FormAI DATASET v1.0 Category: Educational ; Style: authentic
#include <stdio.h>

/* This program calculates the average of an array of integers */

int main() {
  int numbers[5] = {4, 8, 15, 16, 23};
  int sum = 0;
  float average;

  // Calculate the sum of the numbers
  for(int i=0; i<5; i++) {
    sum += numbers[i];
  }

  // Calculate the average using the sum
  average = (float) sum / 5;

  // Display the sum and average
  printf("The sum of the numbers is %d\n", sum);
  printf("The average of the numbers is %.2f\n", average);

  return 0;
}