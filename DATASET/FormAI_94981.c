//FormAI DATASET v1.0 Category: Benchmarking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

void bubbleSort(int arr[], int n) {
  int i, j, temp;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void quickSort(int arr[], int left, int right) {
  int i, j, pivot, temp;
  if (left < right) {
    pivot = left;
    i = left;
    j = right;
    while (i < j) {
      while (arr[i] <= arr[pivot] && i < right) {
        i++;
      }
      while (arr[j] > arr[pivot]) {
        j--;
      }
      if (i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    temp = arr[pivot];
    arr[pivot] = arr[j];
    arr[j] = temp;
    quickSort(arr, left, j - 1);
    quickSort(arr, j + 1, right);
  }
}

int main() {
  int arr[SIZE], i, j;
  time_t t;
  srand((unsigned)time(&t));
   
  printf("Generating random numbers...\n");
  for (i = 0; i < SIZE; i++) {
    arr[i] = rand() % 1000;
  }

  printf("Sorting using bubble sort...\n");
  clock_t start = clock();
  bubbleSort(arr, SIZE);
  clock_t end = clock();
  double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Sorting using bubble sort took %f seconds.\n", timeTaken);

  printf("Generating random numbers again...\n");
  for (i = 0; i < SIZE; i++) {
    arr[i] = rand() % 1000;
  }

  printf("Sorting using quick sort...\n");
  start = clock();
  quickSort(arr, 0, SIZE - 1);
  end = clock();
  timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Sorting using quick sort took %f seconds.\n", timeTaken);

  return 0;
}