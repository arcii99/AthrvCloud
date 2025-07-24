//FormAI DATASET v1.0 Category: Benchmarking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int n = 100000;
  int *arr = (int*)malloc(n * sizeof(int));
  srand(time(NULL));
  
  // fill the array with random integers
  for(int i = 0; i < n; i++) {
    arr[i] = rand() % 100;
  }
  
  // selection sort algorithm
  for(int i = 0; i < n - 1; i++) {
    for(int j = i + 1; j < n; j++) {
      if(arr[j] < arr[i]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  
  // print the sorted array
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  free(arr);
  return 0;
}