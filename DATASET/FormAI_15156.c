//FormAI DATASET v1.0 Category: Random ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  // Obtain current time as seed for random generator
  srand(time(0));

  // Get user input for array size
  int arraySize;
  printf("Enter size of array: ");
  scanf("%d", &arraySize);

  // Dynamically allocate memory for array
  int* array = (int*)malloc(sizeof(int) * arraySize);

  // Randomly generate numbers and store in array
  printf("\nGenerating random numbers...\n");
  for (int i = 0; i < arraySize; i++) {
    array[i] = rand() % 100 + 1;
  }

  // Sort the array in ascending order using bubble sort algorithm
  printf("\nSorting array in ascending order...\n");
  for (int i = 0; i < arraySize - 1; i++) {
    for (int j = 0; j < arraySize - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }

  // Print the sorted array
  printf("\nSorted array in ascending order:\n");
  for (int i = 0; i < arraySize; i++) {
    printf("%d ", array[i]);
  }

  // Free allocated memory
  free(array);

  return 0;
}