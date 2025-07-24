//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, j, k, n;
  printf("Enter the size of the array: ");
  scanf("%d", &n);

  int *array = (int *)malloc(n * sizeof(int));

  printf("Enter the elements one by one: \n");
  for(i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  printf("The original array: \n");
  for(i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  printf("Sorting the array...\n");
  for(i = 0; i < n; i++) {
    for(j = 0; j < n - i - 1; j++) {
      if(array[j] > array[j+1]) {
        k = array[j];
        array[j] = array[j+1];
        array[j+1] = k;
      }
    }
  }

  printf("The sorted array: \n");
  for(i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  free(array);

  return 0;
}