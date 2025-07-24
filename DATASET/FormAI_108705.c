//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int array[10];
  
  // Fill the array with random numbers
  for (int i = 0; i < 10; i++) {
    array[i] = rand() % 100 + 1;
  }

  // Print the array before sorting
  printf("Array before sorting:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  // Perform bubble sort on the array
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9 - i; j++) {
      if (array[j] > array[j+1]) {
        int temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }

  // Print the array after sorting
  printf("Array after sorting:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}