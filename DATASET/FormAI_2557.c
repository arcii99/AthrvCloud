//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int array[], int n) {
  int i, j;
  int count[n];
  for (i = 0; i < n; i++) {
    count[i] = 0;
  }

  for (i = 0; i < n; i++) {
    (count[array[i]])++;
  }

  for (i = 0, j = 0; i < n; i++) {
    for (; count[i] > 0; (count[i])--) {
      array[j++] = i;
    }
  }
}

int main() {
  int array[10] = {10, 5, 20, 8, 15, 3, 12, 2, 1, 6};
  int n = 10;
  int i;
  printf("\nBucket Sort Algorithm :\n\n");
  printf("Before Sorting : \n");
  for (i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }

  bucketSort(array, n);

  printf("\n\nAfter Sorting : \n");
  for (i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  return 0;
}