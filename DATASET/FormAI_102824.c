//FormAI DATASET v1.0 Category: Memory management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {

  // We want to allocate memory for an array of 10 ints
  int *myArray = (int*) malloc(10 * sizeof(int));

  // Let's make sure the allocation was successful
  if (myArray == NULL) {
    printf("Oops, we couldn't allocate memory for the array... :(\n");
    return 1;
  }

  // Yay, we got our memory!
  printf("Hooray, we allocated memory for our array! :D\n");

  // Let's fill the array with some numbers
  for (int i = 0; i < 10; i++) {
    myArray[i] = i * i;
  }

  // Time to print out our array
  printf("Here are the values in our array: \n\n");

  for (int i = 0; i < 10; i++) {
    printf("%d ", myArray[i]);
  }

  printf("\n\n");

  // We're done with our array, so it's time to free up the memory
  free(myArray);

  // Let's make sure the memory was freed properly
  if (myArray == NULL) {
    printf("We successfully freed up the memory for our array! :)\n");
  }

  // And we're done!
  return 0;
}