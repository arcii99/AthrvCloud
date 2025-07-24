//FormAI DATASET v1.0 Category: Sorting ; Style: Alan Touring
#include <stdio.h>
#define ARRAY_SIZE 10

int main() {
  int i, j, temp;
  int arr[ARRAY_SIZE] = {9, 4, 3, 7, 1, 2, 5, 6, 8, 0};

  // Displaying unsorted array
  printf("Unsorted Array: ");
  for(i=0; i<ARRAY_SIZE; i++) {
    printf("%d ", arr[i]);
  }

  // Performing bubble sort
  for(i=0; i<ARRAY_SIZE-1; i++) {
    for(j=0; j<ARRAY_SIZE-1-i; j++) {
      if(arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  // Displaying sorted array
  printf("\nSorted Array: ");
  for(i=0; i<ARRAY_SIZE; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}