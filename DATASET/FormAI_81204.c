//FormAI DATASET v1.0 Category: Memory management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main() {
  // declare and initialize integer pointer
  int *numbers = NULL;

  // allocate memory for 5 integers
  numbers = (int*) malloc(5 * sizeof(int));

  // check if memory allocation was successful
  if (numbers == NULL) {
    printf("Memory allocation failed!\n");
    return -1;
  }

  // assign values to the integers using pointer arithmetic
  *(numbers + 0) = 10;
  *(numbers + 1) = 20;
  *(numbers + 2) = 30;
  *(numbers + 3) = 40;
  *(numbers + 4) = 50;

  // print the values of the integers
  for (int i = 0; i < 5; i++) {
    printf("%d\n", *(numbers + i));
  }

  // reallocate memory for 10 integers
  numbers = (int*) realloc(numbers, 10 * sizeof(int));

  // check if memory reallocation was successful
  if (numbers == NULL) {
    printf("Memory reallocation failed!\n");
    return -1;
  }

  // assign new integer values using array syntax
  numbers[5] = 60;
  numbers[6] = 70;
  numbers[7] = 80;
  numbers[8] = 90;
  numbers[9] = 100;

  // print the values of all 10 integers
  for (int i = 0; i < 10; i++) {
    printf("%d\n", numbers[i]);
  }

  // free the allocated memory
  free(numbers);

  return 0;
}