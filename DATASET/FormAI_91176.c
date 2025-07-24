//FormAI DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

int main() {
  // allocate memory for an array of integers with size of 5
  int* arr = (int*) malloc(5 * sizeof(int));

  // check if memory allocation was successful
  if (arr == NULL) {
    printf("Memory allocation failed!\n");
    return 1; // exit the program with failure status
  }

  // assign values to the array elements
  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;
  arr[3] = 40;
  arr[4] = 50;

  // print the array elements
  printf("Array elements: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // reallocate memory for the array of integers with size of 10
  int* newArr = (int*) realloc(arr, 10 * sizeof(int));

  // check if memory reallocation was successful
  if (newArr == NULL) {
    printf("Memory reallocation failed!\n");
    free(arr); // free the previously allocated memory
    return 1; // exit the program with failure status
  }

  // assign values to the new array elements
  newArr[5] = 60;
  newArr[6] = 70;
  newArr[7] = 80;
  newArr[8] = 90;
  newArr[9] = 100;

  // print the new array elements
  printf("New array elements: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", newArr[i]);
  }
  printf("\n");

  // free the dynamically allocated memory
  free(newArr);

  return 0; // exit the program with success status
}