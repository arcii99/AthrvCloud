//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: shape shifting
#include <stdio.h>

void bucketSort(int array[], int n) {
  int bucket[1000000];
  int i, j;
  for (i = 0; i < 1000000; ++i) {
    bucket[i] = 0;
  }
  for (i = 0; i < n; ++i) {
    ++bucket[array[i]];
  }
  for (i = 0, j = 0; i < 1000000; ++i) {
    while (bucket[i] > 0) {
      array[j++] = i;
      --bucket[i];
    }
  }
}

void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; ++i) {
    printf("%d ", array[i]);
  }
}

int main() {
  int array[] = {4, 9, 1, 7, 3, 6, 5};
  int n = sizeof(array) / sizeof(array[0]);
  printf("Input array: ");
  printArray(array, n);
  bucketSort(array, n);
  printf("\nSorted array: ");
  printArray(array, n);
  return 0;
}