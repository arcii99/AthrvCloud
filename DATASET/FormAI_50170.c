//FormAI DATASET v1.0 Category: Sorting ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
  int original[10] = {8, 6, 4, 2, 9, 7, 5, 3, 1, 0};
  int sorted[10];
  int i, j, temp;

  printf("Original Array: ");
  for (i = 0; i < 10; i++) {
    printf("%d ", original[i]);
  }

  for (i = 0; i < 10; i++) {
    sorted[i] = original[i];
  }

  printf("\nSorting the array...\n");

  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9 - i; j++) {
      if (sorted[j] > sorted[j + 1]) {
        temp = sorted[j];
        sorted[j] = sorted[j + 1];
        sorted[j + 1] = temp;
      }
    }
  }

  printf("Sorted Array: ");
  for (i = 0; i < 10; i++) {
    printf("%d ", sorted[i]);
  }

  printf("\n\nThat's it! Code executed successfully.\n");

  return 0;
}