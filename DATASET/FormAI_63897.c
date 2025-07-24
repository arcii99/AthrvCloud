//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: beginner-friendly
#include <stdio.h>

#define SIZE 5 // number of elements in array

int main() {
  int arr[SIZE] = {5, 1, 3, 2, 4};
  int i, j, min, temp;

  printf("Unsorted array: ");
  for (i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // implementation of selection sort algorithm
  for (i = 0; i < SIZE-1; i++) {
    min = i;
    for (j = i+1; j < SIZE; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    if (min != i) {
      temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
  }

  printf("Sorted array: ");
  for (i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}