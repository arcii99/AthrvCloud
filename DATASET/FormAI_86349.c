//FormAI DATASET v1.0 Category: Memory management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  // Allocate memory for an integer using malloc
  int* myInt = (int*) malloc(sizeof(int));
  if (myInt == NULL) {
    printf("Error allocating memory\n");
    return -1; // Exit the program
  }

  // Assign a value to the integer
  *myInt = 10;

  // Print the value of the integer
  printf("Value of myInt: %d\n", *myInt);

  // Free the allocated memory
  free(myInt);

  // Allocate memory for an array of integers using calloc
  int* myArray = (int*) calloc(5, sizeof(int));
  if (myArray == NULL) {
    printf("Error allocating memory\n");
    return -1; // Exit the program
  }

  // Assign values to the array elements
  myArray[0] = 10;
  myArray[1] = 20;
  myArray[2] = 30;
  myArray[3] = 40;
  myArray[4] = 50;

  // Print the values of the array elements
  for (int i = 0; i < 5; i++) {
    printf("Value of myArray[%d]: %d\n", i, myArray[i]);
  }

  // Reallocate memory for the array of integers using realloc
  myArray = (int*) realloc(myArray, 10 * sizeof(int));
  if (myArray == NULL) {
    printf("Error reallocating memory\n");
    return -1; // Exit the program
  }

  // Assign values to the additional elements of the array
  myArray[5] = 60;
  myArray[6] = 70;
  myArray[7] = 80;
  myArray[8] = 90;
  myArray[9] = 100;

  // Print the values of the array elements
  for (int i = 0; i < 10; i++) {
    printf("Value of myArray[%d]: %d\n", i, myArray[i]);
  }

  // Free the allocated memory
  free(myArray);

  return 0;
}