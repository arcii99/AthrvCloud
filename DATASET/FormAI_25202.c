//FormAI DATASET v1.0 Category: Benchmarking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000000

int main() {
  int *arr = malloc(sizeof(int) * SIZE);

  srand(time(NULL)); 
  for(int i = 0; i < SIZE; i++) {
      arr[i] = rand() % SIZE;
  }

  clock_t start = clock(); 
  for(int i = 0; i < SIZE; i++) {
      for(int j = i + 1; j < SIZE; j++) {
          if(arr[i] > arr[j]) {
              int tmp = arr[i];
              arr[i] = arr[j];
              arr[j] = tmp;
          }
      }
  }
  clock_t end = clock();

  double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time taken: %f seconds\n", cpu_time_used);

  free(arr);
  return 0;
}