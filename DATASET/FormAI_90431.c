//FormAI DATASET v1.0 Category: Sorting ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int num[], int n);

int main() {
  int randomNum[10], i;
  time_t t;

  srand((unsigned) time(&t));

  printf("Unsorted array:\n");
  for (i = 0; i < 10; i++) {
    randomNum[i] = rand() % 101;
    printf("%d ", randomNum[i]);
  }

  bubbleSort(randomNum, 10);

  printf("\nSorted array:\n");
  for (i = 0; i < 10; i++) {
    printf("%d ", randomNum[i]);
  }

  return 0;
}

void bubbleSort(int num[], int n) {
  int i, j, temp;

  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      if (num[j] > num[j+1]) {
        temp = num[j];
        num[j] = num[j+1];
        num[j+1] = temp;
      }
    }
  }
}