//FormAI DATASET v1.0 Category: Sorting ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Wow, I can't believe I'm sorting!\n");
  int array[] = {10, 3, 7, 2, 5, 8, 1, 6, 9, 4};
  int size = sizeof(array)/sizeof(array[0]);

  printf("Unsorted Array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  for (int i = 0; i < size-1; i++) {
    for (int j = 0; j < size-i-1; j++) {
      if (array[j] > array[j+1]) {
        printf("\nSwapping %d and %d\n", array[j], array[j+1]);
        int temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
        printf("Array after swap: ");
        for (int k = 0; k < size; k++) {
          printf("%d ", array[k]);
        }
      }
    }
  }

  printf("\n\nSorted Array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  printf("\n\nAmazing, I did it!");
  return 0;
}