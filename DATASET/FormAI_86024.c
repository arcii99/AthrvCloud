//FormAI DATASET v1.0 Category: Data mining ; Style: genious
#include <stdio.h>

// This is a program that demonstrates data mining using arrays

int main() {
  int data[10] = {12, 34, 56, 78, 90, 23, 45, 67, 89, 10}; // Our data source
  int sum = 0; // Variable to store the sum of all the elements
  float avg; // Variable to store the average

  for(int i = 0; i < 10; i++) {
    sum += data[i]; // Add the current element to the sum
  }

  avg = (float) sum / 10; // Compute the average

  printf("The sum of all elements is: %d\n", sum);
  printf("The average of all elements is: %.2f", avg);

  return 0;
}