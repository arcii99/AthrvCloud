//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void bucket_sort(int arr[], int size, int buckets) {
  int i, j, k, *b;
  b = (int*)malloc(buckets * sizeof(int));
  if (b == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }
  for (i = 0; i < buckets; i++) {
    b[i] = 0;
  }
  for (i = 0; i < size; i++) {
    (b[arr[i]])++;
  }
  for (i = 0, j = 0; j < buckets; j++) {
    for (k = b[j]; k > 0; k--) {
      arr[i++] = j;
    }
  }
  free(b);
}

int main() {
  int arr[] = {8, 3, 1, 5, 9, 4, 2, 7, 6, 0};
  int size = sizeof(arr) / sizeof(arr[0]);
  printf("Original array:\n");
  print_array(arr, size);
  printf("Bucket sort:\n");
  bucket_sort(arr, size, 5);
  print_array(arr, size);
  return 0;
}