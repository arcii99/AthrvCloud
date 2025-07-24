//FormAI DATASET v1.0 Category: Memory management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
  
  // Welcome message
  printf("Welcome to our memory management program!\n\n");

  // Declare variables
  int numElements;
  int* dynamicArray;

  // Get number of elements from user
  printf("Please enter the number of elements for the dynamic array: ");
  scanf("%d", &numElements);

  // Allocate memory for dynamic array
  dynamicArray = (int*) malloc(numElements * sizeof(int));

  // Check if memory allocation was successful
  if(dynamicArray == NULL) {
    printf("ERROR: Memory allocation unsuccessful!\n");
    exit(1);
  } else {
    printf("Memory allocation successful!\n\n");
  }

  // Populate dynamic array with random numbers
  printf("Populating dynamic array with random numbers...\n\n");

  for(int i = 0; i < numElements; i++) {
    dynamicArray[i] = rand() % 100;
    printf("Element %d: %d\n", i, dynamicArray[i]);
  }

  // Deallocate memory for dynamic array
  free(dynamicArray);
  printf("\nMemory deallocated successfully!\n");

  return 0;
}