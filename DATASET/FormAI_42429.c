//FormAI DATASET v1.0 Category: Sorting ; Style: visionary
#include <stdio.h>

int main() {
  int array[] = {8, 3, 9, 1, 2, 5, 4, 7, 6};
  int length = sizeof(array) / sizeof(array[0]);
  
  printf("Original Array: ");
  for (int i = 0; i < length; i++){
    printf("%d ", array[i]);
  }
  printf("\n");

  for (int i = 0; i < length - 1; i++) {
    for (int j = i + 1; j < length; j++) {
      if (array[i] > array[j]) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }

  printf("Sorted Array: ");
  for (int i = 0; i < length; i++){
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}