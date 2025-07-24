//FormAI DATASET v1.0 Category: Memory management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main()
{
  // Allocating memory for an array of 5 integers
  int *arr = (int*)malloc(5 * sizeof(int));
  if (arr == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  }

  // Setting values of the array
  *(arr + 0) = 1;
  *(arr + 1) = 2;
  *(arr + 2) = 3;
  *(arr + 3) = 4;
  *(arr + 4) = 5;

  // Printing values of the array
  printf("Values of the array:\n");
  for (int i = 0; i < 5; i++) {
    printf("%d ", *(arr + i));
  }
  printf("\n\n");

  // Reallocating memory for an array of 10 integers
  int *new_arr = (int*)realloc(arr, 10 * sizeof(int));
  if (new_arr == NULL) {
    printf("Memory reallocation failed!\n");
    exit(1);
  }

  // Setting values of the new array
  *(new_arr + 5) = 6;
  *(new_arr + 6) = 7;
  *(new_arr + 7) = 8;
  *(new_arr + 8) = 9;
  *(new_arr + 9) = 10;

  // Printing values of the new array
  printf("Values of the new array:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d ", *(new_arr + i));
  }
  printf("\n\n");

  // Freeing memory of the new array
  free(new_arr);
  printf("Memory freed successfully!\n");

  return 0;
}