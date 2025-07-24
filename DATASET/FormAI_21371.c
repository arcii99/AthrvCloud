//FormAI DATASET v1.0 Category: Sorting ; Style: creative
#include <stdio.h>

int main() {
  int array[10];
  int i, j, temp;
  printf("Enter 10 integers: ");

  for (i = 0; i < 10; i++) {
    scanf("%d", &array[i]);
  }

  printf("Unsorted List: ");
  for (i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }

  for (i = 0; i < 10; i++) {
    for (j = i + 1; j < 10; j++) {
      if (array[i] > array[j]) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }

  printf("\nSorted List: ");
  for (i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }
  return 0;
}