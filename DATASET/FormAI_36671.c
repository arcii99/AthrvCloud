//FormAI DATASET v1.0 Category: Sorting ; Style: careful
#include <stdio.h>

int main() {
  int size, i, j, temp;
  printf("Enter size of array: ");
  scanf("%d", &size);

  int array[size];

  printf("Enter array elements:\n");
  for(i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }

  printf("Unsorted array: ");
  for(i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  // bubble sort algorithm
  for(i = 0; i < size - 1; i++) {
    for(j = 0; j < size - i - 1; j++) {
      if(array[j] > array[j+1]) {
        // swap elements
        temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }

  printf("\nSorted array: ");
  for(i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  return 0;
}