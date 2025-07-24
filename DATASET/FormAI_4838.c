//FormAI DATASET v1.0 Category: Funny ; Style: single-threaded
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

void bubble_sort(int arr[], int n) {
  int i, j;
  bool swapped;
  for (i = 0; i < n - 1; i++) {
    swapped = false;
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = true;
      }
    }
    if (swapped == false)
      break;
  }
}

int main() {
  srand(time(NULL));
  int arr[ARRAY_SIZE];
  int i;
  for (i = 0; i < ARRAY_SIZE; i++) {
    arr[i] = rand() % ARRAY_SIZE;
  }
  printf("Before Sorting: \n");
  for (i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", arr[i]);
  }
  bubble_sort(arr, ARRAY_SIZE);
  printf("\nAfter Sorting: \n");
  for (i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}