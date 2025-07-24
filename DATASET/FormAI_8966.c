//FormAI DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Allocate memory for an array of ten integers
  int *myArray = malloc(10 * sizeof(int));

  // Zero out the array
  for(int i = 0; i < 10; i++) {
    myArray[i] = 0;
  }

  // Print the contents of the array
  printf("myArray content:\n");
  for(int i = 0; i < 10; i++) {
    printf("%d ", myArray[i]);
  }
  printf("\n");

  // Let's allocate some more memory for another array
  int *anotherArray = malloc(5 * sizeof(int));

  // Fill up the array with some numbers
  for(int i = 0; i < 5; i++) {
    anotherArray[i] = i * 2;
  }

  // Print the contents of the second array
  printf("anotherArray content:\n");
  for(int i = 0; i < 5; i++) {
    printf("%d ", anotherArray[i]);
  }
  printf("\n");

  // Let's allocate some memory for a string
  char *myString = malloc(20 * sizeof(char));
  sprintf(myString, "Hello, World!");

  // Print the string
  printf("myString content: %s\n", myString);

  // Now we're done using the arrays and string, so we need to free up the memory
  free(myArray);
  free(anotherArray);
  free(myString);

  return 0;
}