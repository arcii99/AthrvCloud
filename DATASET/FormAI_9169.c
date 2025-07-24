//FormAI DATASET v1.0 Category: Benchmarking ; Style: Donald Knuth
#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort(int arr[]) {
  int i, j;
  for (i = 0; i < ARRAY_SIZE-1; i++) {
    for (j = 0; j < ARRAY_SIZE-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        swap(&arr[j], &arr[j+1]);
      }
    }
  }
}

void quick_sort(int arr[], int left, int right) {
  if (left < right) {
    int pivot = arr[right];
    int i = left - 1;
    int j;
    for (j = left; j <= right-1; j++) {
      if (arr[j] <= pivot) {
        i++;
        swap(&arr[i], &arr[j]);
      }
    }
    swap(&arr[i+1], &arr[right]);
    int partition = i+1;
    quick_sort(arr, left, partition-1);
    quick_sort(arr, partition+1, right);
  }
}

int main() {
  int arr[ARRAY_SIZE], i, j;
  clock_t start_time, end_time;
  
  // Generate random numbers for array
  srand(time(NULL));
  for (i = 0; i < ARRAY_SIZE; i++) {
    arr[i] = rand() % 10000;
  }
  
  printf("Original Array:\n");
  for (i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", arr[i]);
  }
  
  printf("\n\nSorting using Bubble Sort...\n");
  start_time = clock();
  bubble_sort(arr);
  end_time = clock();
  printf("Bubble Sort Complete. Time Taken: %lf\n\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
  
  printf("Sorted Array using Bubble Sort:\n");
  for (i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", arr[i]);
  }
  
  printf("\n\nSorting using Quick Sort...\n");
  start_time = clock();
  quick_sort(arr, 0, ARRAY_SIZE-1);
  end_time = clock();
  printf("Quick Sort Complete. Time Taken: %lf\n\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
  
  printf("Sorted Array using Quick Sort:\n");
  for (i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", arr[i]);
  }
  
  return 0;
}