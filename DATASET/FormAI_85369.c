//FormAI DATASET v1.0 Category: Benchmarking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  const int ARRAY_SIZE = 1000000;
  int arr[ARRAY_SIZE];
  srand(time(NULL));
  
  // Initialize array with random integers between 1 and 1000000
  for (int i = 0; i < ARRAY_SIZE; i++) {
    arr[i] = rand() % 1000000 + 1;
  }
  
  // Bubble sort
  clock_t start_bubble = clock();
  for (int i = 0; i < ARRAY_SIZE - 1; i++) {
    for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
      if (arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  clock_t end_bubble = clock();
  double elapsed_bubble = (double)(end_bubble - start_bubble) / CLOCKS_PER_SEC;
  
  // Insertion sort
  clock_t start_insertion = clock();
  for (int i = 1; i < ARRAY_SIZE; i++) {
    int j = i;
    while (j > 0 && arr[j-1] > arr[j]) {
      int temp = arr[j];
      arr[j] = arr[j-1];
      arr[j-1] = temp;
      j--;
    }
  }
  clock_t end_insertion = clock();
  double elapsed_insertion = (double)(end_insertion - start_insertion) / CLOCKS_PER_SEC;

  printf("Bubble sort took %f seconds\n", elapsed_bubble);
  printf("Insertion sort took %f seconds\n", elapsed_insertion);

  return 0;
}