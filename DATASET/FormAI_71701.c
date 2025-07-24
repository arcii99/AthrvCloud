//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Define the number of elements in the array
#define ARRAY_SIZE 10

// Define the maximum value an element in the array can have
#define MAX_ELEMENT_VALUE 100

// Define the number of buckets to use
#define NUM_BUCKETS 5

void printArray(int array[], int size) {
  printf("[ ");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("]\n");
}

void bucketSort(int array[], int size) {
  // Create an array of buckets
  int buckets[NUM_BUCKETS][ARRAY_SIZE] = {0};

  // Find the maximum element in the array
  int maxElement = 0;
  for (int i = 0; i < size; i++) {
    if (array[i] > maxElement) {
      maxElement = array[i];
    }
  }

  // Calculate the width of each bucket
  float bucketWidth = (float) maxElement / NUM_BUCKETS;

  // Populate the buckets
  for (int i = 0; i < size; i++) {
    int bucketIndex = (int) (array[i] / bucketWidth);
    buckets[bucketIndex][i] = array[i];
  }

  // Sort each bucket using insertion sort
  for (int i = 0; i < NUM_BUCKETS; i++) {
    for (int j = 1; j < size; j++) {
      int currentElement = buckets[i][j];
      int k = j - 1;

      while (k >= 0 && buckets[i][k] > currentElement) {
        buckets[i][k + 1] = buckets[i][k];
        k--;
      }

      buckets[i][k + 1] = currentElement;
    }
  }

  // Merge the sorted buckets back into the original array
  int index = 0;
  for (int i = 0; i < NUM_BUCKETS; i++) {
    for (int j = 0; j < size; j++) {
      if (buckets[i][j] != 0) {
        array[index] = buckets[i][j];
        index++;
      }
    }
  }
}

int main() {
  // Generate random array
  int array[ARRAY_SIZE];
  for (int i = 0; i < ARRAY_SIZE; i++) {
    array[i] = rand() % MAX_ELEMENT_VALUE + 1;
  }

  // Print unsorted array
  printf("Unsorted Array: ");
  printArray(array, ARRAY_SIZE);

  // Sort the array
  bucketSort(array, ARRAY_SIZE);

  // Print sorted array
  printf("Sorted Array:   ");
  printArray(array, ARRAY_SIZE);

  return 0;
}