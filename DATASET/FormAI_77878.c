//FormAI DATASET v1.0 Category: Error handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  // Let's create an array to store some numbers
  int myArray[5] = {1, 2, 3, 4, 5};

  // Let's try to access an element outside the bounds of the array
  printf("Accessing an element outside the bounds of the array: \n");
  int i = 7;
  if(i < 0 || i >= 5) {
    printf("Index out of bounds: %d\n", i);
    exit(1);
  }
  int value = myArray[i]; // This is a bug!

  // Let's try to divide by zero
  printf("\nDividing by zero: \n");
  int a = 10, b = 0;
  if(b == 0) {
    printf("Cannot divide by zero!\n");
    exit(2);
  }
  int result = a / b; // This is a bug!

  // Let's try to allocate too much memory
  printf("\nAllocating too much memory: \n");
  int* c = malloc(sizeof(int) * 1e9);
  if(c == NULL) {
    printf("Failed to allocate memory!\n");
    exit(3);
  }

  // Let's try to open a non-existent file
  printf("\nOpening a non-existent file: \n");
  FILE* file = fopen("non-existent.txt", "r");
  if(file == NULL) {
    printf("Failed to open file!\n");
    exit(4);
  }

  printf("\nProgram ran successfully!\n");
  return 0;
}