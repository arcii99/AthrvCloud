//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int size) {

  // Create an array of empty buckets
  int i, j;
  int count[size];
  for (i = 0; i < size; i++)
    count[i] = 0;

  // Increment the count of each element in the array
  for (i = 0; i < size; i++)
    ++count[(int)arr[i]];

  // Sort the elements in each bucket
  for (i = 0, j = 0; i < size; ++i) {
    for (; count[i] > 0; --count[i]) {
      arr[j++] = (float)i;
    }
  }
}

int main() {
  float arr[] = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51, 0.25};
  int i, size = sizeof(arr) / sizeof(arr[0]);

  printf("Unsorted array:\n");
  for (i = 0; i < size; i++)
    printf("%f ", arr[i]);

  bucketSort(arr, size);

  printf("\nSorted array:\n");
  for (i = 0; i < size; i++)
    printf("%f ", arr[i]);
  printf("\n");

  return 0;
}