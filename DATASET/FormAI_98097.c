//FormAI DATASET v1.0 Category: Math exercise ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Seed the random number generator
  srand(time(NULL)); 

  // Initialize an array with 10 random integers between 0 and 99
  int nums[10];
  for (int i = 0; i < 10; i++) {
    nums[i] = rand() % 100;
    printf("%d ", nums[i]);
  }

  // Find the total sum of the array
  int sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += nums[i];
  }

  // Calculate the average
  double avg = (double) sum / 10;
  printf("\nAverage: %f\n", avg);

  // Find the minimum value
  int min = nums[0];
  for (int i = 1; i < 10; i++) {
    if (nums[i] < min) {
      min = nums[i];
    }
  }
  printf("Minimum: %d\n", min);

  // Find the maximum value
  int max = nums[0];
  for (int i = 1; i < 10; i++) {
    if (nums[i] > max) {
      max = nums[i];
    }
  }
  printf("Maximum: %d\n", max);

  return 0;
}