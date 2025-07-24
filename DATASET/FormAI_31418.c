//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOAT_PRECISION 10

void print_array(float arr[], int n) {
  int i;

  printf("[ ");
  for (i = 0; i < n; i++) {
    printf("%.2f ", arr[i]);
  }
  printf("]\n");
}

void bucket_sort(float arr[], int n) {
  int i, j;
  int index;
  float bucket[MAX_FLOAT_PRECISION][n];
  int size[MAX_FLOAT_PRECISION];
  
  for (i = 0; i < MAX_FLOAT_PRECISION; i++) {
    size[i] = 0;
  }
  
  for (i = 0; i < n; i++) {
    index = arr[i] * MAX_FLOAT_PRECISION;
    bucket[index][size[index]++] = arr[i];
  }
  
  for (i = 0; i < MAX_FLOAT_PRECISION; i++) {
    insertion_sort(bucket[i], size[i]);
  }
  
  index = 0;
  for (i = 0; i < MAX_FLOAT_PRECISION; i++) {
    for (j = 0; j < size[i]; j++) {
      arr[index++] = bucket[i][j];
    }
  }
}

void insertion_sort(float arr[], int n) {
  int i, j;
  float key;

  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }

    arr[j + 1] = key;
  }
}

int main() {
  int n, i;
  float arr[] = {0.23, 0.10, 0.53, 0.65, 0.89, 0.12, 0.045, 0.72, 0.15};
 
  n = sizeof(arr) / sizeof(float);
  
  printf("Original Array:\n");
  print_array(arr, n);

  bucket_sort(arr, n);

  printf("Sorted Array:\n");
  print_array(arr, n);

  return 0;
}