//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Donald Knuth
/* Donald Knuth Style Performance-Critical Component */
#include <stdio.h>

#define ARRAY_SIZE 1000000

int main() {

  /* Declare an array of ints */
  int array[ARRAY_SIZE];
  
  /* Initialize array elements with random values */
  srand(time(NULL));
  for (int i = 0; i < ARRAY_SIZE; i++) {
    array[i] = rand() % 100;
  }
  
  /* Sort the array in ascending order using Bubble Sort algorithm */
  for (int i = 0; i < ARRAY_SIZE - 1; i++) {
    for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
      if (array[j] > array[j+1]) {
        int temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }
  
  /* Print the sorted array */
  printf("Sorted Array: ");
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", array[i]);
  }
  
  return 0;
}