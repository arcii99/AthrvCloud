//FormAI DATASET v1.0 Category: Benchmarking ; Style: detailed
#include <stdio.h>
#include <time.h>

#define SIZE 1000

int main() {
  int array[SIZE], i, j, temp;
  clock_t start, end;
  double time_taken;

  // Generating random numbers for the array
  for (i = 0; i < SIZE; i++) {
    array[i] = rand() % 10000;
  }

  // BENCHMARKING FOR BUBBLE SORT
  start = clock();
  for (i = 0; i < SIZE - 1; i++) {
    for (j = 0; j < SIZE - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        // Swap the elements
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
  end = clock();
  time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("BUBBLE SORT:\n");
  printf("Time taken: %f seconds\n", time_taken);
  printf("Sorted array:\n");
  for (i = 0; i < SIZE; i++) {
    printf("%d ", array[i]);
  }
  printf("\n\n");

  // Generating random numbers for the array
  for (i = 0; i < SIZE; i++) {
    array[i] = rand() % 10000;
  }

  // BENCHMARKING FOR QUICK SORT
  start = clock();
  quick_sort(array, 0, SIZE - 1);
  end = clock();
  time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("QUICK SORT:\n");
  printf("Time taken: %f seconds\n", time_taken);
  printf("Sorted array:\n");
  for (i = 0; i < SIZE; i++) {
    printf("%d ", array[i]);
  }
  printf("\n\n");

  return 0;
}

void quick_sort(int array[], int left, int right) {
  int pivot, i, j, temp;

  // Base case
  if (left < right) {
    pivot = left;
    i = left;
    j = right;

    while (i < j) {
      while (array[i] <= array[pivot] && i < right)
        i++;
      while (array[j] > array[pivot])
        j--;
      if (i < j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }

    temp = array[pivot];
    array[pivot] = array[j];
    array[j] = temp;

    quick_sort(array, left, j - 1);
    quick_sort(array, j + 1, right);
  }
}