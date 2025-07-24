//FormAI DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main() {

  int *arr;

  // allocate memory for array of size 5
  arr = (int*) malloc(5 * sizeof(int));

  // check if memory allocation was successful
  if(arr == NULL) {
    printf("Error allocating memory!\n");
    return 1;
  }

  // initialize array
  arr[0] = 1;
  arr[1] = 2;
  arr[2] = 3;
  arr[3] = 4;
  arr[4] = 5;

  // print array
  printf("Array before resizing:\n");
  for(int i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // resize array to size 10
  int *temp = (int*) realloc(arr, 10 * sizeof(int));

  // check if resizing was successful
  if(temp != NULL) {
    arr = temp;
  }
  else {
    free(arr);
    printf("Error resizing memory!\n");
    return 1;
  }

  // initialize new values in resized array
  arr[5] = 6;
  arr[6] = 7;
  arr[7] = 8;
  arr[8] = 9;
  arr[9] = 10;

  // print resized array
  printf("Array after resizing:\n");
  for(int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // free dynamically allocated memory
  free(arr);

  return 0;
}