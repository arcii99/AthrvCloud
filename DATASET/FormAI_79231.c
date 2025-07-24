//FormAI DATASET v1.0 Category: Sorting ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

void print_array(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void quick_sort(int array[], int left, int right) {
  if (left >= right) {
    return;
  }
  int pivot = array[(left+right)/2];
  int i = left, j = right;
  while (i <= j) {
    while (array[i] < pivot) {
      i++;
    }
    while (array[j] > pivot) {
      j--;
    }
    if (i <= j) {
      swap(&array[i], &array[j]);
      i++;
      j--;
    }
  }
  #pragma omp task
  quick_sort(array, left, j);
  #pragma omp task
  quick_sort(array, i, right);
}

int main() {
  srand(time(NULL));
  int size = 100;
  int array[size];
  printf("Original Array:\n");
  for (int i = 0; i < size; i++) {
    array[i] = rand() % 100;
  }
  print_array(array, size);
  #pragma omp parallel
  #pragma omp single nowait
  quick_sort(array, 0, size-1);
  printf("Sorted Array:\n");
  print_array(array, size);
  return 0;
}