//FormAI DATASET v1.0 Category: Benchmarking ; Style: single-threaded
#include <stdio.h>
#include <time.h>

#define SIZE 100000

int main() {
  
  clock_t start, end;
  double cpu_time_used;

  // Create an array of random integers
  int arr[SIZE];
  for (int i = 0; i < SIZE; i++) {
    arr[i] = rand() % 1000;
  }

  // Bubble sort the array and measure time taken
  start = clock();
  for (int i = 0; i < SIZE - 1; i++) {
    for (int j = 0; j < SIZE - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time taken for bubble sort: %lf\n", cpu_time_used);

  // Selection sort the array and measure time taken
  start = clock();
  for (int i = 0; i < SIZE - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < SIZE; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[min_idx];
    arr[min_idx] = temp;
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time taken for selection sort: %lf\n", cpu_time_used);

  // Insertion sort the array and measure time taken
  start = clock();
  for (int i = 1; i < SIZE; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time taken for insertion sort: %lf\n", cpu_time_used);

  return 0;
}