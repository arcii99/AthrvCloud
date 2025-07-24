//FormAI DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Allocating memory for an integer and a character array
  int *ptr_int = (int *) malloc(sizeof(int));
  char *ptr_char = (char *) malloc(10 * sizeof(char));

  // Checking if memory allocation was successful
  if (ptr_int == NULL && ptr_char == NULL) {
    printf("Error allocating memory!\n");
    return 1;
  }

  // Storing a value in the integer pointer
  *ptr_int = 42;

  // Storing values in the character pointer
  for (int i = 0; i < 10; i++) {
    ptr_char[i] = 'A' + i;
  }

  // Printing the values stored in the pointers
  printf("Value stored in integer pointer: %d\n", *ptr_int);
  printf("Values stored in character pointer: %s\n", ptr_char);

  // Reallocating memory for the character array
  char *new_ptr_char = (char *) realloc(ptr_char, 20 * sizeof(char));

  // Checking if reallocation was successful
  if (new_ptr_char == NULL) {
    printf("Error reallocating memory!\n");
    return 1;
  }

  // Storing values in the new character pointer
  for (int i = 10; i < 20; i++) {
    new_ptr_char[i] = 'a' + i;
  }

  // Printing the values stored in the new character pointer
  printf("Values stored in new character pointer: %s\n", new_ptr_char);

  // Freeing allocated memory
  free(ptr_int);
  free(new_ptr_char);

  return 0;
}