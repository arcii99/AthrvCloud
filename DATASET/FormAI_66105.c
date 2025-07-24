//FormAI DATASET v1.0 Category: Memory management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main() {
  // allocate enough memory for 5 integer values
  int *numbers = (int*) malloc(5 * sizeof(int));
  
  if (numbers == NULL) {
    printf("Memory allocation error!\n");
    return 1;
  }
  
  // initialize values in the array
  for (int i = 0; i < 5; i++) {
    numbers[i] = i + 1;
  }
  
  // print the values in the array
  for (int i = 0; i < 5; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");
  
  // reallocate memory for 10 integer values
  int *new_numbers = (int*) realloc(numbers, 10 * sizeof(int));
  
  if (new_numbers == NULL) {
    printf("Memory reallocation error!\n");
    return 1;
  }
  
  // initialize the new values in the array
  for (int i = 5; i < 10; i++) {
    new_numbers[i] = i + 1;
  }
  
  // print the values in the new array
  for (int i = 0; i < 10; i++) {
    printf("%d ", new_numbers[i]);
  }
  printf("\n");
  
  // free the memory allocated for the array
  free(new_numbers);
  
  return 0;
}