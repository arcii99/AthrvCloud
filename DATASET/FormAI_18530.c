//FormAI DATASET v1.0 Category: Educational ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size) {
  for(int i=0; i<size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int size;

  printf("Enter the number of elements in the array: ");
  scanf("%d", &size);

  int *arr = (int*)malloc(size * sizeof(int));

  printf("Enter the elements in the array: ");
  for(int i=0; i<size; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Array before sorting: ");
  printArray(arr, size);

  // Synchronous Bubble Sort
  for(int i=0; i<size-1; i++) {
    for(int j=0; j<size-i-1; j++) {
      if(arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
    printf("After iteration %d: ", i+1);
    printArray(arr, size);
  }

  printf("Array after sorting: ");
  printArray(arr, size);

  free(arr);

  return 0;
}