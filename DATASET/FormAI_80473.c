//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000
#define MAX_VAL 1000

int main() {
  int *arr;
  arr = (int *) malloc (SIZE * sizeof(int));

  srand(time(NULL));

  for (int i = 0; i < SIZE; i++) {
    arr[i] = rand() % MAX_VAL;   //filling array with random values
  }

  for (int i = 0; i < SIZE; i++) {
    for (int j = i + 1; j < SIZE; j++) {
      if (arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

  // printing sorted array
  for (int i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }

  free(arr);
  return 0;
}