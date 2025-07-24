//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
  int arr[SIZE];

  // Generate random values for array elements
  srand(time(NULL));
  for (int i = 0; i < SIZE; i++) {
    arr[i] = rand() % 100;
  }

  int min = arr[0];
  int max = arr[0];
  double avg = 0;

  // Find minimum, maximum, and average of array elements
  for (int i = 0; i < SIZE; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
    if (arr[i] > max) {
      max = arr[i];
    }
    avg += arr[i];
  }
  avg /= SIZE;
  
  // Output results
  printf("Minimum value: %d\n", min);
  printf("Maximum value: %d\n", max);
  printf("Average value: %g\n", avg);

  return 0;
}