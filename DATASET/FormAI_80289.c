//FormAI DATASET v1.0 Category: Memory management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // allocate memory for a string
  char *string = malloc(15 * sizeof(char));
  if (string == NULL) {
    printf("Oh no! Memory allocation failed :(\n");
    return 1;
  }
  
  // copy a happy message into the string
  strcpy(string, "Hello world!");

  // allocate memory for an int array
  int *array = calloc(10, sizeof(int));
  if (array == NULL) {
    printf("Uh oh! Memory allocation failed :(\n");
    return 1;
  }

  // fill the array with happy values
  for (int i = 0; i < 10; i++) {
    array[i] = i * 2;
  }

  // print the happy string and array
  printf("%s\n", string);
  printf("My happy array of even numbers:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d\n", array[i]);
  }

  // free the allocated memory
  free(string);
  free(array);

  printf("Yay! Memory management was successful :)\n");
  return 0;
}