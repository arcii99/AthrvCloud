//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBERS 10000000
#define MAX_THREADS 4

int numbers[MAX_NUMBERS];

void generateNumbers() {
  srand(time(NULL));
  for (int i = 0; i < MAX_NUMBERS; i++) {
    numbers[i] = rand() % 100;
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}

void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

void* threadSorting(void* arg) {
  int id = (int)arg;
  int start = id * (MAX_NUMBERS / MAX_THREADS);
  int end = start + (MAX_NUMBERS / MAX_THREADS);
  mergeSort(numbers, start, end - 1);
}

void sortNumbers() {
  pthread_t threads[MAX_THREADS];
  for (int i = 0; i < MAX_THREADS; i++) {
    pthread_create(&threads[i], NULL, threadSorting, (void*)i);
  }
  for (int i = 0; i < MAX_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }
  merge(numbers, 0, MAX_NUMBERS / 2 - 1, MAX_NUMBERS - 1);
}

int main() {
  generateNumbers();
  printf("Unsorted numbers: ");
  printArray(numbers, MAX_NUMBERS);
  sortNumbers();
  printf("\nSorted numbers: ");
  printArray(numbers, MAX_NUMBERS);
  return 0;
}