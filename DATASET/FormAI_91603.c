//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// bucket sort function
void bucket_sort(int array[], int n, int max_value) {
  int i, j;
  int *buckets = calloc(max_value + 1, sizeof(int));

  for (i = 0; i < n; i++) {
    buckets[array[i]]++;
  }

  for (i = 0, j = 0; i <= max_value; i++) {
    while (buckets[i] > 0) {
      array[j++] = i;
      buckets[i]--;
    }
  }

  free(buckets);
}

// display function
void display_array(int array[], int n) {
  int i;

  for (i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

// main function
int main() {
  int array[] = {5, 7, 1, 3, 1, 6, 4, 8, 2, 5};
  int n = sizeof(array) / sizeof(int);
  int max_value = 8;

  printf("Unsorted array:\n");
  display_array(array, n);

  bucket_sort(array, n, max_value);

  printf("\nSorted array:\n");
  display_array(array, n);

  return 0;
}