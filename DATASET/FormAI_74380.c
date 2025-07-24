//FormAI DATASET v1.0 Category: Sorting ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
  int data[] = {1, 10, 2, 9, 3, 8, 4, 7, 5, 6};

  printf("Unsorted list: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", data[i]);
  }
  printf("\n\n");

  printf("Sorting...\n");

  for (int i = 0; i < 10; i++) {
    for (int j = i + 1; j < 10; j++) {
      if (data[i] > data[j]) {
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
      }
    }
  }

  printf("\nSorted list: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", data[i]);
  }
  printf("\n\n");

  printf("Congratulations! Your list has been sorted!\n");

  return 0;
}