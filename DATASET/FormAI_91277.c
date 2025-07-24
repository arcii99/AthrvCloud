//FormAI DATASET v1.0 Category: Benchmarking ; Style: thoughtful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Function to generate random numbers
void generate_numbers(int *array, int size) {
  for (int i = 0; i < size; i++) {
    array[i] = rand() % 100;
  }
}

// Function to sort array using bubble sort algorithm
void bubble_sort(int *array, int size) {
  int tmp;
  for (int i = 0; i < size-1; i++) {
    for (int j = 0; j < size-i-1; j++) {
      if (array[j] > array[j+1]) {
        tmp = array[j];
        array[j] = array[j+1];
        array[j+1] = tmp;
      }
    }
  }
}

int main() {
  int array[1000], n = 1000;

  // Generate random numbers
  srand(time(NULL));
  generate_numbers(array, n);

  // Start benchmarking for bubble sort
  clock_t t;
  t = clock();
  bubble_sort(array, n);
  t = clock() - t;
  double time_taken = ((double) t)/CLOCKS_PER_SEC;

  // Print sorted array and time taken for bubble sort
  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  printf("Bubble Sort took %f seconds to sort %d numbers.\n", time_taken, n);

  return 0;
}