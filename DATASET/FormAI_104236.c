//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum value of the array
#define MAX_VALUE 100

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void bucketSort(int arr[], int n) {
  // Create an array of buckets
  int buckets[MAX_VALUE] = {0};

  // Increase the count of each element in the bucket
  for (int i = 0; i < n; i++) {
    buckets[arr[i]]++;
  }

  // Sort the array using the buckets
  int index = 0;
  for (int i = 0; i < MAX_VALUE; i++) {
    for (int j = 0; j < buckets[i]; j++) {
      arr[index++] = i;
    }
  }
}

int main() {
  int arr[] = {22, 45, 12, 8, 10, 6, 72, 81, 33, 18};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Before sorting:\n");
  printArray(arr, n);

  bucketSort(arr, n);

  printf("After sorting:\n");
  printArray(arr, n);

  return 0;
}