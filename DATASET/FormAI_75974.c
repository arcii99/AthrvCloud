//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: calm
#include <stdio.h>

#define SIZE 10000

int main(void) {
  int arr[SIZE];
  int i;

  // Initialize the array with random values between 0 and 999
  for (i = 0; i < SIZE; i++) {
    arr[i] = rand() % 1000;
  }

  int sum = 0;

  // Loop through the array and add up the values
  for (i = 0; i < SIZE; i++) {
    sum += arr[i];
  }

  // Print the sum
  printf("Sum: %d\n", sum);

  return 0;
}