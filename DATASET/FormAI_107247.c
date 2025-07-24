//FormAI DATASET v1.0 Category: Benchmarking ; Style: imaginative
#include <stdio.h>
#include <time.h>

int main() {
  int n = 10000;
  int array[n];
  clock_t start, end;
  double time_taken;

  // Fill the array with random values
  for (int i = 0; i < n; i++) {
    array[i] = rand() % 1000;
  }

  // Bubble sort algorithm
  start = clock();
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-i-1; j++) {
      if (array[j] > array[j+1]) {
        int temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }
  end = clock();
  time_taken = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Bubble Sort took %f seconds to execute.\n", time_taken);

  // Quick sort algorithm
  start = clock();
  quickSort(array, 0, n-1);
  end = clock();
  time_taken = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Quick Sort took %f seconds to execute.\n", time_taken);

  return 0;
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int partitionIndex = partition(array, low, high);
    quickSort(array, low, partitionIndex - 1);
    quickSort(array, partitionIndex + 1, high);
  }
}

int partition (int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);

  for (int j = low; j <= high-1; j++) {
    if (array[j] <= pivot) {
      i++;
      int temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }

  int temp = array[i+1];
  array[i+1] = array[high];
  array[high] = temp;

  return (i+1);
}