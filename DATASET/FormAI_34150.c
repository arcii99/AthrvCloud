//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000000

int main() {
  int i, sum = 0;
  int *arr = malloc(sizeof(int) * ARRAY_SIZE);

  // Initialize array with random values
  srand(time(NULL));
  for (i = 0; i < ARRAY_SIZE; i++) {
    arr[i] = rand() % 10;
  }

  // Summing the array
  for (i = 0; i < ARRAY_SIZE; i++) {
    sum += arr[i];
  }

  printf("The sum of the array is: %d\n", sum);

  free(arr);
  return 0;
}