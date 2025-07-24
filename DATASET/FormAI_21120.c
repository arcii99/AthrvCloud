//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) printf("%d ", arr[i]);
  printf("\n");
}

void bucketSort(int arr[], int n) {
  int i, j;
  int maxVal = arr[0];
  for (i = 1; i < n; i++) if (arr[i] > maxVal) maxVal = arr[i];
  maxVal++;
  int buckets[maxVal];
  for (i = 0; i < maxVal; i++) buckets[i] = 0;
  for (i = 0; i < n; i++) buckets[arr[i]]++;
  for (i = 0, j = 0; i < maxVal; i++) {
    while (buckets[i] > 0) {
      arr[j++] = i;
      buckets[i]--;
    }
  }
}

int main() {
  int arr[] = {5, 8, 2, 7, 1, 6, 3, 4};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Before sorting:\n");
  printArray(arr, n);
  bucketSort(arr, n);
  printf("After sorting:\n");
  printArray(arr, n);
  return 0;
}