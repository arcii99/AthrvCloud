//FormAI DATASET v1.0 Category: Memory management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to my Memory Management program!\n");

  // Allocating memory for an array of integers
  int* myArray = (int*) malloc(10 * sizeof(int));

  // Filling the array with some values
  for (int i = 0; i < 10; i++) {
    myArray[i] = i * 2;
  }

  // Printing out the array
  printf("Array contents:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d ", myArray[i]);
  }
  printf("\n");

  // Re-allocating the memory to make the array larger
  myArray = (int*) realloc(myArray, 20 * sizeof(int));

  // Filling the newly allocated memory with some more values
  for (int i = 10; i < 20; i++) {
    myArray[i] = i * 2;
  }

  // Printing out the array again
  printf("New array contents:\n");
  for (int i = 0; i < 20; i++) {
    printf("%d ", myArray[i]);
  }
  printf("\n");

  // Freeing the allocated memory
  free(myArray);
  
  printf("Thank you for using my Memory Management program!\n");

  return 0;
}