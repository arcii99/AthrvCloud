//FormAI DATASET v1.0 Category: Sorting ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int size, i, j, temp;
  int array[100];
  
  printf("Enter array size: ");
  scanf("%d", &size);
 
  printf("Enter %d elements in the array:\n", size);
  
  for(i=0; i<size; i++) {
    scanf("%d", &array[i]);
  }

  printf("\nArray before sorting: ");
  
  for(i=0; i<size; i++) {
    printf("%d ", array[i]);
  }

  for(i=0; i<size-1; i++) {
    for(j=0; j<size-i-1; j++) {
      if(array[j] > array[j+1]) {
        temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }

  printf("\nArray after sorting: ");
  
  for(i=0; i<size; i++) {
    printf("%d ", array[i]);
  }

  return 0;
}