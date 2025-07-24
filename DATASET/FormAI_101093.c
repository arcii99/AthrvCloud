//FormAI DATASET v1.0 Category: Benchmarking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n) {
  int i, j, temp;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

void insertion_sort(int arr[], int n) {
  int i, j, key;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}

void quick_sort(int arr[], int l, int r) {
  if (l < r) {
    int p = partition(arr, l, r);
    quick_sort(arr, l, p-1);
    quick_sort(arr, p+1, r);
  }
}

int partition(int arr[], int l, int r) {
  int pivot = arr[r];
  int i = (l - 1);
  int temp;
  for (int j = l; j <= r-1; j++) {
    if (arr[j] < pivot) {
      i++;
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  temp = arr[i+1];
  arr[i+1] = arr[r];
  arr[r] = temp;
  return (i + 1);
}

int main() {
  int arr[10000];
  int n = sizeof(arr)/sizeof(int);
  int i;
  clock_t start_time, end_time;
  
  srand(time(NULL));
  for (i = 0; i < n; i++) {
    arr[i] = rand() % 10000;
  }
  
  // Bubble sort benchmark
  start_time = clock();
  bubble_sort(arr, n);
  end_time = clock();
  printf("Time taken by bubble sort algorithm: %lu clocks\n", end_time - start_time);
  
  // Insertion sort benchmark
  start_time = clock();
  insertion_sort(arr, n);
  end_time = clock();
  printf("Time taken by insertion sort algorithm: %lu clocks\n", end_time - start_time);
  
  // Quick sort benchmark
  start_time = clock();
  quick_sort(arr, 0, n-1);
  end_time = clock();
  printf("Time taken by quick sort algorithm: %lu clocks\n", end_time - start_time);
  
  return 0;
}